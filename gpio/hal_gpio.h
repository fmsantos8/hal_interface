#ifndef __HAL_GPIO__
#define __HAL_GPIO__

#include <stdbool.h>
#include <stdint.h>

#include "status/hal_status.h"

#ifdef __cplusplus
extern "C" {
#endif

// TODO: Make this a opaque structure to hide implementation details from the user.
typedef struct {

} hal_gpio_t;

/**
 * @brief Read the level of a GPIO pin.
 *
 * @param gpio[in] Pointer to the GPIO structure.
 * @param level[out] Pointer to a boolean variable where the level will be stored.
 * True for high, false for low.
 *
 * @return hal_status_t Status code indicating success or failure of the operation.
 */
hal_status_t hal_gpio_read(hal_gpio_t *gpio, bool *level);

/**
 * @brief Write a level to a GPIO pin.
 *
 * @param gpio[in] Pointer to the GPIO structure.
 * @param level[in] Pointer to a boolean variable indicating the level to set.
 * True for high, false for low.
 *
 * @return hal_status_t Status code indicating success or failure of the operation.
 */
hal_status_t hal_gpio_write(hal_gpio_t *gpio, bool *level);

#ifdef __cplusplus
}
#endif

#endif