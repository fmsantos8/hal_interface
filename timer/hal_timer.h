/**
 * @file hal_timer.h
 * @author Fabricio Santos (fmsantos8@ucs.br)
 * @brief Periodic notifications from a dedicated hardware timer.
 *
 */
#ifndef HAL_TIMER_H
#define HAL_TIMER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "common/hal_status.h"

/**
 * @brief Opaque hardware timer object.
 */
typedef struct hal_timer hal_timer_t;

/**
 * @brief Handle a serviced hardware timer expiration in interrupt context.
 *
 * @details The callback takes no arguments and must be short and nonblocking.
 * It must not call HAL operations unless they explicitly support interrupt
 * context. Shared application data requires synchronization appropriate to the
 * selected platform; volatile alone does not guarantee atomic access.
 */
typedef void (*hal_timer_callback_t)(void);

/**
 * @brief Fixed periodic configuration copied by the constructor.
 *
 * @details The port reserves a dedicated hardware timer for the firmware lifetime.
 * It validates the period before allocation or hardware configuration. Supported
 * periods and nominal timing resolution are documented by the port; unavailable
 * settings return HAL_STATUS_NOT_SUPPORTED without silent substitution.
 */
typedef struct {
    uint8_t instance;              /** Port-defined hardware timer resource identifier selected by the BSP */
    uint32_t period;               /** Positive interval between periodic hardware expirations, in milliseconds */
    hal_timer_callback_t callback; /** Required expiration callback; must not be NULL */
} hal_timer_config_t;

/**
 * @brief Construct and configure a periodic hardware timer without starting it.
 *
 * @details Construction is sequential and requires an initialized, unsealed
 * framework memory arena. Configuration remains fixed for the object's lifetime.
 * The callback is not invoked until hal_timer_start() activates the timer.
 * Failed construction may consume arena space. No destruction or runtime
 * reconfiguration is provided.
 *
 * @param[out] timer Timer object pointer to receive the allocated handle; must not be NULL.
 * @param[in] config Complete startup configuration; must not be NULL.
 *
 * @retval HAL_STATUS_OK The timer is configured and stopped.
 * @retval HAL_STATUS_INVALID_ARGUMENT A required pointer, callback, identifier, or period is invalid.
 * @retval HAL_STATUS_NOT_SUPPORTED The requested period or dedicated hardware resource is unavailable on this platform.
 * @retval HAL_STATUS_NOT_INITIALIZED Platform or arena initialization is missing.
 * @retval HAL_STATUS_INVALID_STATE The construction phase has ended.
 * @retval HAL_STATUS_RESOURCE_BUSY The selected hardware resource is already assigned or the hardware timer pool is exhausted.
 * @retval HAL_STATUS_NO_MEMORY Framework or SDK storage is unavailable.
 * @retval HAL_STATUS_ERROR The platform failed to configure the timer.
 */
hal_status_t hal_timer_config(hal_timer_t **out_timer, const hal_timer_config_t *config);

/**
 * @brief Start a configured periodic timer once, after application initialization.
 *
 * @details Call from normal execution context after construction and dependency
 * initialization. Shared data used by the callback must already be initialized.
 * This operation allocates no framework objects and may follow arena sealing.
 * The first expiration occurs after one configured period measured from hardware
 * activation; the callback may run before this function returns. Subsequent
 * expirations are periodic. Repeated starts do not restart the timer.
 * No callbacks are delivered after a failed start returns.
 *
 * Interrupt latency may delay callback execution. The port documents conditions
 * under which multiple expirations can coalesce; recovery of every missed period
 * is not guaranteed. A callback-maintained tick counter counts delivered
 * notifications and is not an unconditional measurement of physical elapsed time.
 *
 * @param[in] timer Valid handle returned by hal_timer_config().
 *
 * @retval HAL_STATUS_OK The timer is running with periodic notifications enabled.
 * @retval HAL_STATUS_INVALID_ARGUMENT The handle is NULL.
 * @retval HAL_STATUS_NOT_INITIALIZED The timer or platform is not ready.
 * @retval HAL_STATUS_INVALID_STATE The timer is already running.
 * @retval HAL_STATUS_ERROR The platform failed to start the timer.
 */
hal_status_t hal_timer_start(hal_timer_t *timer);

#ifdef __cplusplus
}
#endif

#endif
