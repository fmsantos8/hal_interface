#ifndef HAL_UART_H
#define HAL_UART_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "status/hal_status.h"

/**
 * @brief Opaque structure representing an UART peripheral.
 *
 */
typedef struct hal_uart hal_uart_t;

/**
 * @brief UART parity configuration.
 *
 */
typedef enum {
    HAL_UART_PARITY_NONE = 0, /** No parity */
    HAL_UART_PARITY_EVEN = 1, /** Even parity */
    HAL_UART_PARITY_ODD = 2,  /** Odd parity */
} hal_uart_parity_t;

/**
 * @brief Number of UART stop bits.
 */
typedef enum {
    HAL_UART_STOP_BITS_1 = 1, /** One stop bit */
    HAL_UART_STOP_BITS_2 = 2, /** Two stop bits */
} hal_uart_stop_bits_t;

/**
 * @brief UART configuration structure.
 *
 */
typedef struct {
    uint32_t baud_rate;             /** Requested baud rate in bps; zero is invalid */
    hal_uart_parity_t parity;       /** UART parity configuration */
    hal_uart_stop_bits_t stop_bits; /** One or two stop bits */
} hal_uart_config_t;

/**
 * @brief Configure an UART controller instance.
 *
 * @param[in] uart Pointer to the UART controller instance to configure.
 * @param[in] config Pointer to the UART configuration structure.
 *
 * @return HAL_STATUS_INVALID_PARAM for a null argument, zero baud rate or
 *         invalid enum value; HAL_STATUS_NOT_SUPPORTED for a valid setting
 *         unavailable on this UART; HAL_STATUS_OK on success; otherwise
 *         HAL_STATUS_ERROR on hardware failure.
 */
hal_status_t hal_uart_config(hal_uart_t *uart, const hal_uart_config_t *config);

/**
 * @brief Write data to an UART device.
 *
 * @param[in] uart Pointer to the UART controller instance.
 * @param[in] data Buffer to transmit; must not be null.
 * @param[in] size Number of bytes to transmit; zero is invalid.
 *
 * @return HAL_STATUS_INVALID_PARAM for a null buffer or zero size; otherwise
 *         a hal_status_t indicating the transmission result.
 */
hal_status_t hal_uart_write(hal_uart_t *uart, const uint8_t *data, uint32_t size);

#ifdef __cplusplus
}
#endif

#endif