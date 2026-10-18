/**
 * @file hal_system.h
 * @author Fabricio Santos (fmsantos8@ucs.br)
 * @brief System initialization
 */
#ifndef HAL_SYSTEM_H
#define HAL_SYSTEM_H

#include <stdint.h>

#include "common/hal_status.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Backing storage supplied by the integration for all HAL objects.
 */
typedef struct {
    void *memory_buffer;      /** Persistent writable storage aligned for max_align_t. */
    uint32_t memory_capacity; /** Positive buffer size in bytes; includes allocation padding. */
} hal_system_config_t;

/**
 * @brief Initialize the platform infrastructure and open HAL construction.
 *
 * @details Call once during startup, before constructing any HAL resource.
 * The port establishes the required system-clock infrastructure according to
 * the board/SDK build configuration, respecting initialization already performed
 * by the SDK. Required SDK startup must precede this call as documented by the
 * port. Peripheral clocks, pin routing and peripheral configuration are completed
 * by the corresponding resource constructors.
 *
 * @param[in] config Required system configuration.
 *
 * @retval HAL_STATUS_OK The system is ready for HAL resource construction.
 * @retval HAL_STATUS_INVALID_ARGUMENT config or memory_buffer is NULL, capacity
 * is zero, or the buffer alignment is invalid.
 * @retval HAL_STATUS_INVALID_STATE System initialization has already succeeded.
 * @retval HAL_STATUS_ERROR Required platform initialization failed.
 */
hal_status_t hal_system_init(const hal_system_config_t *config);

/**
 * @brief Permanently close HAL object allocation after resource construction.
 *
 * @retval HAL_STATUS_OK Construction is closed, including a repeated seal.
 * @retval HAL_STATUS_NOT_INITIALIZED hal_system_init() has not succeeded.
 */
hal_status_t hal_system_seal(void);

#ifdef __cplusplus
}
#endif

#endif
