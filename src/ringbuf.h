#ifndef RINGBUF_H
#define RINGBUF_H

/**
 * Ring buffer structure.
 */
typedef struct {
    void *data;
    size_t capacity;
    size_t size;
    size_t start;
    size_t end;
} ringbuf_t;

/**
 * Initialize a ring buffer.
 * 
 * @param buf  Ring buffer to initialize.
 * @param data Buffer to store the data in.
 * @param capacity Capacity of the buffer.
 */
void ringbuf_init(ringbuf_t *buf, void *data, size_t capacity);

/**
 * Write data to the ring buffer.
 * 
 * @param buf  Ring buffer to write to.
 * @param data Data to write.
 * @param len  Length of the data.
 * 
 * @return 1 if successful, 0 otherwise.
 */
int ringbuf_write(ringbuf_t *buf, const void *data, size_t len);

/**
 * Read data from the ring buffer.
 * 
 * @param buf  Ring buffer to read from.
 * @param data Buffer to store the data in.
 * @param len  Length of the data.
 * 
 * @return 1 if successful, 0 otherwise.
 */
int ringbuf_read(ringbuf_t *buf, void *data, size_t len);

/**
 * Get the current size of the ring buffer.
 * 
 * @param buf  Ring buffer to get the size of.
 * 
 * @return The current size of the ring buffer.
 */
size_t ringbuf_size(ringbuf_t *buf);

#endif /* RINGBUF_H */