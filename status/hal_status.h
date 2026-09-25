#ifndef HAL_STATUS_H
#define HAL_STATUS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/**
 * @brief Status codes for all HAL operations.
 *
 */
typedef enum {
    HAL_STATUS_OK = 0,            /** Operation completed successfully */
    HAL_STATUS_ERROR = 1,         /** Operation failed due to an error */
    HAL_STATUS_TIMEOUT = 2,       /** Operation timed out */
    HAL_STATUS_INVALID_PARAM = 3, /** Invalid parameter provided to the operation */
    HAL_STATUS_NOT_SUPPORTED = 4, /** Operation not supported */
} hal_status_t;

#ifdef __cplusplus
}
#endif

#endif
