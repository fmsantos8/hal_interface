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
 * @brief UART mode.
 *
 */
typedef enum {
    HAL_UART_MODE_TX = 0,    /** UART Transmit mode */
    HAL_UART_MODE_RX = 1,    /** UART Receive mode */
    HAL_UART_MODE_TX_RX = 2, /** UART Transmit and Receive mode */
} hal_uart_mode_t;

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
 * @brief UART configuration structure.
 *
 */
typedef struct {
    uint32_t baud_rate;       /** UART baud rate */
    hal_uart_mode_t mode;     /** UART mode (TX, RX, or TX_RX) */
    hal_uart_parity_t parity; /** UART parity configuration */
    uint8_t stop_bits;        /** Number of stop bits (1 or 2) */
} hal_uart_config_t;

/**
 * @brief Configure an UART controller instance.
 *
 * @param[in] uart Pointer to the UART controller instance to configure.
 * @param[in] config Pointer to the UART configuration structure.
 *
 * @return hal_status_t Status code indicating success or failure of the operation.
 */
hal_status_t hal_uart_configure(hal_uart_t *uart, const hal_uart_config_t *config);

/**
 * @brief Write data to an UART device.
 *
 * @param[in] uart Pointer to the UART controller instance.
 * @param[in] data Pointer to the data buffer to be written.
 * @param[in] size The number of bytes to write from the data buffer.
 * @param[in] timeout The maximum time to wait for the operation to complete (milliseconds).
 *
 * @return hal_status_t Status code indicating success or failure of the operation.
 */
hal_status_t hal_uart_write(hal_uart_t *uart, const uint8_t *data, uint32_t size, uint32_t timeout);

#ifdef __cplusplus
}
#endif

#endif