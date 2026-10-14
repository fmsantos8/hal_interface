#ifndef HAL_TIMER_H
#define HAL_TIMER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "common/hal_status.h"

/**
 * @brief Opaque handle to a dedicated hardware timer selected by the BSP.
 */
typedef struct hal_timer hal_timer_t;

/**
 * @brief Configure and start a free-running millisecond timer.
 *
 * The first successful call starts the timer with an elapsed count of zero.
 * Calling this function again while the timer is running returns HAL_STATUS_OK
 * without restarting or resetting the count. The timer remains running; this
 * interface does not provide stop or reset operations.
 *
 * @param[in] timer Pointer to a valid timer handle.
 *
 * @return HAL_STATUS_OK on success, HAL_STATUS_INVALID_PARAM for a null
 *         handle, HAL_STATUS_NOT_SUPPORTED if the timer cannot provide
 *         millisecond resolution, or HAL_STATUS_ERROR on hardware failure.
 */
hal_status_t hal_timer_start(hal_timer_t *timer);

/**
 * @brief Read milliseconds elapsed since the first successful start.
 *
 * The timer provides at least 1 ms resolution. The 32-bit result wraps modulo
 * 2^32; calculate intervals using unsigned subtraction of two readings.
 * This call does not block or reset the timer.
 *
 * @param[in] timer Pointer to a valid, started timer handle.
 * @param[out] millis Pointer to receive the elapsed millisecond count.
 *
 * @return HAL_STATUS_OK on success, HAL_STATUS_INVALID_PARAM for a null
 *         argument, or HAL_STATUS_ERROR if the timer has not been started or
 *         the hardware read fails. On failure, *millis is unchanged.
 */
hal_status_t hal_timer_get_millis(hal_timer_t *timer, uint32_t *millis);

#ifdef __cplusplus
}
#endif

#endif
