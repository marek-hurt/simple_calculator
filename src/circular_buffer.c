/**
 * @file circular_buffer.c
 * @brief Circular buffer implementation
 */

#include "circular_buffer.h"

void cbuf_init(circular_buffer_t *cbuf, uint8_t *buffer, uint16_t size) {
    cbuf->buffer = buffer;
    cbuf->size = size;
    cbuf->head = 0;
    cbuf->tail = 0;
    cbuf->count = 0;
}

cbuf_status_t cbuf_write(circular_buffer_t *cbuf, uint8_t data) {
    if (cbuf->count == cbuf->size) {
        return CBUF_FULL;
    }

    cbuf->buffer[cbuf->head] = data;
    cbuf->head = (cbuf->head + 1) % cbuf->size;
    cbuf->count++;
    return CBUF_OK;
}

cbuf_status_t cbuf_read(circular_buffer_t *cbuf, uint8_t *data) {
    if (cbuf->count == 0) {
        return CBUF_EMPTY;
    }

    *data = cbuf->buffer[cbuf->tail];
    cbuf->tail = (cbuf->tail + 1) % cbuf->size;
    cbuf->count--;
    return CBUF_OK;
}

bool cbuf_is_full(const circular_buffer_t *cbuf) {
    return cbuf->count == cbuf->size;
}

bool cbuf_is_empty(const circular_buffer_t *cbuf) {
    return cbuf->count == 0;
}