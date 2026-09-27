#ifndef HAL_I2C_H
#define HAL_I2C_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "status/hal_status.h"

/**
 * @brief Opaque structure representing an I2C peripheral.
 *
 */
typedef struct hal_i2c hal_i2c_t;

/**
 * @brief I2C configuration structure.
 *
 */
typedef struct {
    uint32_t clock_speed; /** Requested I2C clock speed in Hz; zero is invalid */
} hal_i2c_config_t;

/**
 * @brief Configure an I2C controller instance.
 *
 * @param[in] i2c Pointer to the I2C controller instance to configure.
 * @param[in] config Pointer to the I2C configuration structure.
 *
 * @return HAL_STATUS_INVALID_PARAM for a null argument or zero clock speed,
 *         HAL_STATUS_NOT_SUPPORTED if the requested speed is unavailable, or
 *         HAL_STATUS_OK on success. Hardware failures return HAL_STATUS_ERROR.
 */
hal_status_t hal_i2c_config(hal_i2c_t *i2c, const hal_i2c_config_t *config);

/**
 * @brief Write data to an I2C device using the specified address.
 *
 * @param[in] i2c Pointer to the I2C controller instance.
 * @param[in] address The 7-bit I2C address of the target device.
 * @param[in] data Pointer to the data buffer to be written; must not be null.
 * @param[in] size Number of bytes to write; zero is invalid.
 *
 * @return HAL_STATUS_INVALID_PARAM for a null buffer or zero size; otherwise
 *         a hal_status_t indicating the transfer result.
 */
hal_status_t hal_i2c_write(hal_i2c_t *i2c, uint8_t address, const uint8_t *data, uint32_t size);

/**
 * @brief Read data from an I2C device using the specified address.
 *
 * After any error, the buffer may contain partial data and its contents must
 * not be used.
 *
 * @param[in] i2c Pointer to the I2C controller instance.
 * @param[in] address The 7-bit I2C address of the target device.
 * @param[out] data Buffer for the read data; must not be null.
 * @param[in] size Number of bytes to read; zero is invalid.
 *
 * @return HAL_STATUS_INVALID_PARAM for a null buffer or zero size; otherwise
 *         a hal_status_t indicating the transfer result.
 */
hal_status_t hal_i2c_read(hal_i2c_t *i2c, uint8_t address, uint8_t *data, uint32_t size);

#ifdef __cplusplus
}
#endif

#endif
