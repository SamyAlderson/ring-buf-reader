#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RINGBUF_MAX_SIZE 256

typedef struct {
    char data[RINGBUF_MAX_SIZE];
    size_t head;
    size_t tail;
    size_t size;
} ringbuf_t;

ringbuf_t ringbuf_init() {
    ringbuf_t rb;
    rb.head = 0;
    rb.tail = 0;
    rb.size = 0;
    return rb;
}

int ringbuf_empty(const ringbuf_t *rb) {
    return rb->size == 0;
}

int ringbuf_full(const ringbuf_t *rb) {
    return rb->size == RINGBUF_MAX_SIZE;
}

void ringbuf_push(ringbuf_t *rb, const char *data, size_t len) {
    if (ringbuf_full(rb)) {
        fprintf(stderr, "ringbuf_push: buffer full\n");
        exit(1);
    }
    size_t new_len = rb->size + len;
    if (new_len > RINGBUF_MAX_SIZE) {
        fprintf(stderr, "ringbuf_push: buffer overflow\n");
        exit(1);
    }
    if (rb->tail + len > RINGBUF_MAX_SIZE) {
        memcpy(rb->data, rb->data + rb->head, RINGBUF_MAX_SIZE - rb->head);
        rb->head = 0;
        rb->size = RINGBUF_MAX_SIZE - rb->head;
    } else {
        size_t i;
        for (i = 0; i < len; i++) {
            rb->data[rb->tail + i] = data[i];
        }
        rb->tail += len;
        rb->size = new_len;
    }
}

char ringbuf_pop(ringbuf_t *rb) {
    if (ringbuf_empty(rb)) {
        fprintf(stderr, "ringbuf_pop: buffer empty\n");
        exit(1);
    }
    char c = rb->data[rb->head];
    rb->head++;
    rb->size--;
    return c;
}

void ringbuf_clear(ringbuf_t *rb) {
    rb->head = 0;
    rb->tail = 0;
    rb->size = 0;
}