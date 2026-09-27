#ifndef HAL_GPIO_H
#define HAL_GPIO_H

#include <stdbool.h>
#include <stdint.h>

#include "status/hal_status.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Opaque structure representing a GPIO pin.
 *
 */
typedef struct hal_gpio hal_gpio_t;

/**
 * @brief GPIO pin direction.
 */
typedef enum {
    HAL_GPIO_DIRECTION_INPUT = 0,  /** Configure the pin as an input */
    HAL_GPIO_DIRECTION_OUTPUT = 1, /** Configure the pin as an output */
} hal_gpio_direction_t;

/**
 * @brief GPIO internal pull resistor.
 */
typedef enum {
    HAL_GPIO_PULL_NONE = 0, /** Disable internal pull resistors */
    HAL_GPIO_PULL_UP = 1,   /** Enable the internal pull-up resistor */
    HAL_GPIO_PULL_DOWN = 2, /** Enable the internal pull-down resistor */
} hal_gpio_pull_t;

/**
 * @brief GPIO configuration.
 */
typedef struct {
    hal_gpio_direction_t direction; /** Input or push-pull output */
    hal_gpio_pull_t pull;           /** Internal pull resistor */
} hal_gpio_config_t;

/**
 * @brief Configure a GPIO pin with the specified direction and pull resistor.
 *
 * Configuring an output always drives it to a low electrical level, including
 * when reconfiguring an already active output. The port sets the output latch
 * low before enabling the output. Unsupported electrical configurations return
 * HAL_STATUS_NOT_SUPPORTED.
 *
 * @param[in] gpio Pointer to the GPIO handle.
 * @param[in] config Pointer to the GPIO configuration.
 *
 * @return HAL_STATUS_OK on success, HAL_STATUS_INVALID_PARAM for a null
 *         argument or invalid enum value, HAL_STATUS_NOT_SUPPORTED for an
 *         unsupported configuration, or HAL_STATUS_ERROR on hardware failure.
 */
hal_status_t hal_gpio_config(hal_gpio_t *gpio, const hal_gpio_config_t *config);

/**
 * @brief Read the level of a GPIO pin.
 *
 * @param[in] gpio Pointer to the GPIO structure.
 * @param[out] level Pointer to a boolean variable where the level will be stored.
 * True for high, false for low.
 *
 * @return hal_status_t Status code indicating success or failure of the operation.
 */
hal_status_t hal_gpio_read(hal_gpio_t *gpio, bool *level);

/**
 * @brief Write a level to a GPIO pin.
 *
 * @param[in] gpio Pointer to the GPIO structure.
 * @param[in] level Electrical level to set: true for high, false for low.
 *
 * @return hal_status_t Status code indicating success or failure of the operation.
 */
hal_status_t hal_gpio_write(hal_gpio_t *gpio, bool level);

#ifdef __cplusplus
}
#endif

#endif