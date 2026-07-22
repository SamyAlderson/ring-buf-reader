#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ringbuf.h"

int main(int argc, char *argv[]) {
    // Check if the ring buffer size was provided as an argument
    if (argc < 2) {
        fprintf(stderr, "Error: Ring buffer size must be provided as an argument\n");
        return EXIT_FAILURE;
    }

    // Convert the size string to an integer
    char *endptr;
    unsigned int size = strtoul(argv[1], &endptr, 10);
    if (*endptr != '\0' || size == 0) {
        fprintf(stderr, "Error: Ring buffer size must be a positive integer\n");
        return EXIT_FAILURE;
    }

    // Allocate and initialize the ring buffer
    ringbuf_t *buf = ringbuf_create(size);
    if (!buf) {
        fprintf(stderr, "Error: Failed to allocate ring buffer\n");
        return EXIT_FAILURE;
    }

    // Read and print the contents of the ring buffer
    char *data = ringbuf_read(buf);
    if (!data) {
        fprintf(stderr, "Error: Failed to read from ring buffer\n");
        ringbuf_destroy(buf);
        return EXIT_FAILURE;
    }

    printf("%s\n", data);

    // Clean up
    free(data);
    ringbuf_destroy(buf);

    return EXIT_SUCCESS;
}