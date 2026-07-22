#ifndef RINGBUF_H
#define RINGBUF_H

/**
 * Maximum number of elements in the ring buffer.
 */
#define RINGBUF_SIZE 1024

/**
 * Ring buffer structure.
 */
typedef struct {
    unsigned char data[RINGBUF_SIZE];
    unsigned int head;
    unsigned int tail;
    unsigned int size;
} ringbuf_t;

/**
 * Initialize a ring buffer.
 *
 * @param rb Ring buffer to initialize.
 * @return 0 on success, -1 on failure.
 */
int ringbuf_init(ringbuf_t *rb);

/**
 * Write data to the ring buffer.
 *
 * @param rb Ring buffer to write to.
 * @param data Data to write.
 * @param len Length of data to write.
 * @return 0 on success, -1 on failure (buffer full).
 */
int ringbuf_write(ringbuf_t *rb, const unsigned char *data, unsigned int len);

/**
 * Read data from the ring buffer.
 *
 * @param rb Ring buffer to read from.
 * @param data Buffer to store read data.
 * @param len Length of data to read (up to ring buffer size).
 * @return Number of bytes read on success, -1 on failure (buffer empty).
 */
int ringbuf_read(ringbuf_t *rb, unsigned char *data, unsigned int len);

#endif  // RINGBUF_H