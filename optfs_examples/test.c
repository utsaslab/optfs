#include <fcntl.h>
#include <stdio.h>
#include <sys/syscall.h>
#include <sys/time.h>
#include <unistd.h>

/* Wrappers for osync and dsync. */
#define __NR_osync 349
#define __NR_dsync 350

int osync(int fd) 
{
    return syscall(__NR_osync, fd);
}

int dsync(int fd) 
{
    return syscall(__NR_dsync, fd);
}

/* Elapsed time in milliseconds. */
double elapsed_ms(struct timeval* start,
        struct timeval* end) {
    unsigned long sec = end->tv_sec - start->tv_sec;
    unsigned long usec = end->tv_usec - start->tv_usec;

    return sec * 1000.0 + usec / 1000.0;
}

#define NUM_RUNS 20

int main() 
{
    int fd; 
    struct timeval st, et;
    double total_osync_time = 0;
    double total_dsync_time = 0;
    double total_fsync_time = 0;
    int i;

    /* Open file. */
    fd = open ("/mnt/mydisk/testing2", O_CREAT | O_RDWR);

    /* Measure osync() latency. */
    for (i = 0; i < NUM_RUNS; i++) {
        gettimeofday(&st, NULL);
        write(fd, "hello\n", 6);
        osync(fd);
        gettimeofday(&et, NULL);
        total_osync_time += elapsed_ms(&st, &et);
    }

    printf("osync() latency in ms: %f\n", total_osync_time/NUM_RUNS);

    /* Measure dsync() latency. */
    for (i = 0; i < NUM_RUNS; i++) {
        gettimeofday(&st, NULL);
        write(fd, "hello\n", 12);
        dsync(fd);
        gettimeofday(&et, NULL);
        total_dsync_time += elapsed_ms(&st, &et);
    }

    printf("dsync() latency in ms: %f\n", total_dsync_time/NUM_RUNS);

    /* Measure fsync() latency. */
    for (i = 0; i < NUM_RUNS; i++) {
        gettimeofday(&st, NULL);
        write(fd, "hello\n", 12);
        fsync(fd);
        gettimeofday(&et, NULL);
        total_fsync_time += elapsed_ms(&st, &et);
    }

    printf("fsync() latency in ms: %f\n", total_fsync_time/NUM_RUNS);

    close(fd);
    return 0;
}
