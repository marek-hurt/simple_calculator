/**
 * @file circular_buffer.h
 * @brief Circular (ring) buffer module for fixed-size byte queue
 */

#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stdint.h>
#include <stdbool.h>

/**
 * @brief Return codes for circular buffer operations.
 */
typedef enum {
    CBUF_OK = 0,
    CBUF_FULL,
    CBUF_EMPTY
} cbuf_status_t;

/**
 * @brief Circular buffer structure.
 */
typedef struct {
    uint8_t *buffer;       /**< Pointer to buffer array */
    uint16_t size;         /**< Total buffer size */
    uint16_t head;         /**< Write index */
    uint16_t tail;         /**< Read index */
    uint16_t count;        /**< Number of elements stored */
} circular_buffer_t;

/**
 * @brief Initializes the circular buffer.
 *
 * @param cbuf Pointer to circular buffer instance
 * @param buffer Memory buffer (array of uint8_t)
 * @param size Size of the buffer array
 */
void cbuf_init(circular_buffer_t *cbuf, uint8_t *buffer, uint16_t size);

/**
 * @brief Writes one byte to the circular buffer.
 *
 * @param cbuf Pointer to circular buffer
 * @param data Byte to write
 * @return Status: CBUF_OK or CBUF_FULL
 */
cbuf_status_t cbuf_write(circular_buffer_t *cbuf, uint8_t data);

/**
 * @brief Reads one byte from the circular buffer.
 *
 * @param cbuf Pointer to circular buffer
 * @param data Pointer where read byte will be stored
 * @return Status: CBUF_OK or CBUF_EMPTY
 */
cbuf_status_t cbuf_read(circular_buffer_t *cbuf, uint8_t *data);

/**
 * @brief Checks if the buffer is full.
 *
 * @param cbuf Pointer to circular buffer
 * @return true if full, false otherwise
 */
bool cbuf_is_full(const circular_buffer_t *cbuf);

/**
 * @brief Checks if the buffer is empty.
 *
 * @param cbuf Pointer to circular buffer
 * @return true if empty, false otherwise
 */
bool cbuf_is_empty(const circular_buffer_t *cbuf);

#endif // CIRCULAR_BUFFER_H