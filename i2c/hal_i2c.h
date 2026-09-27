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
    uint32_t clock_speed; /** I2C clock speed in Hz */
} hal_i2c_config_t;

/**
 * @brief Configure an I2C controller instance.
 *
 * @param[in] i2c Pointer to the I2C controller instance to configure.
 * @param[in] config Pointer to the I2C configuration structure.
 *
 * @return hal_status_t Status code indicating success or failure of the operation.
 */
hal_status_t hal_i2c_config(hal_i2c_t *i2c, const hal_i2c_config_t *config);

/**
 * @brief Write data to an I2C device using the specified address.
 *
 * @param i2c[in] Pointer to the I2C controller instance.
 * @param address[in] The 7-bit I2C address of the target device.
 * @param data[in] Pointer to the data buffer to be written.
 * @param size[in] The number of bytes to write from the data buffer.
 * @param timeout[in] The maximum time to wait for the operation to complete (milliseconds).
 *
 * @return hal_status_t Status code indicating success or failure of the operation.
 */
hal_status_t hal_i2c_write(hal_i2c_t *i2c, uint8_t address, const uint8_t *data, uint32_t size, uint32_t timeout);

/**
 * @brief Read data from an I2C device using the specified address.
 *
 * @param i2c[in] Pointer to the I2C controller instance.
 * @param address[in] The 7-bit I2C address of the target device.
 * @param data[out] Pointer to the data buffer to store the read data.
 * @param size[in] The number of bytes to read into the data buffer.
 * @param timeout[in] The maximum time to wait for the operation to complete (milliseconds).
 *
 * @return hal_status_t Status code indicating success or failure of the operation.
 */
hal_status_t hal_i2c_read(hal_i2c_t *i2c, uint8_t address, uint8_t *data, uint32_t size, uint32_t timeout);

#ifdef __cplusplus
}
#endif

#endif
