/**
 * @file hal_pin.h
 * @author Fabricio Santos (fmsantos8@ucs.br)
 * @brief Portable physical pin identification.
 *
 */
#ifndef HAL_PIN_H
#define HAL_PIN_H

#include <stdint.h>

/**
 * @brief Physical pin identifier supplied by the board integration.
 *
 * The port field identifies a GPIO bank, not a platform SDK pointer or a logical
 * device such as an LED. Bank identifiers are zero-based: the ESP32 uses bank 0;
 * STM32 banks A, B, and subsequent banks use 0, 1, and subsequent identifiers;
 * nRF52840 banks P0 and P1 use 0 and 1. The number field is the pin index within
 * the bank, not a bit mask, package lead number, or development-board label.
 *
 * The BSP supplies the available bank mappings and permitted pin assignments.
 * Ports validate these mappings and the capabilities of the selected pin.
 * Identical identifiers do not imply identical wiring on different boards.
 */
typedef struct {
    uint8_t port;   /** Zero-based GPIO bank identifier */
    uint8_t number; /** Zero-based pin index within the bank */
} hal_pin_t;

#endif
