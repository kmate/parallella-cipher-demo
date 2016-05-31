#ifndef IO_H_
#define IO_H_

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

// Timing utilities

#include <time.h>


struct timespec start;
struct timespec end;
unsigned long long nsecs = 0;

#define start_iteration() \
    clock_gettime(CLOCK_MONOTONIC, &start);

#define end_iteration() \
    clock_gettime(CLOCK_MONOTONIC, &end); \
    nsecs += (end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec);

#define print_time() \
    printf("%llu\n", nsecs / (unsigned long long)1e6);


// Endiannes conversion based on openssl: crypto/bf/bf_locl.h
#define n2l(c,l) (l =((uint32_t)(*((c)++)))<<24L, \
                  l|=((uint32_t)(*((c)++)))<<16L, \
                  l|=((uint32_t)(*((c)++)))<< 8L, \
                  l|=((uint32_t)(*((c)++))))

#define l2n(l,c) (*((c)++)=(uint8_t)(((l)>>24L)&0xff), \
                  *((c)++)=(uint8_t)(((l)>>16L)&0xff), \
                  *((c)++)=(uint8_t)(((l)>> 8L)&0xff), \
                  *((c)++)=(uint8_t)(((l)     )&0xff))

#define min(a, b) ((a) < (b) ? (a) : (b))

#define CHUNK_LENGTH 4096  // 4k chunks

int fd;
size_t file_length;
char *mapped;

void map_to_be() {
  size_t blocks = file_length / sizeof(uint64_t);
  for (int i = 0; i < blocks; ++i) {
    // conversion to big-endian
    uint64_t *b = (uint64_t *)(mapped + i * sizeof(uint64_t));
    uint64_t t = *b;
    uint8_t *in = (uint8_t *)&t;
    uint32_t l;
    n2l(in, l);
    *(((uint32_t *)b) + 1) = l;
    n2l(in, l);
    *((uint32_t *)b) = l;
  }
}

void map_to_le() {
  size_t blocks = file_length / sizeof(uint64_t);
  for (int i = 0; i < blocks; ++i) {
    // conversion to little-endian
    uint8_t *out = (uint8_t *)(mapped + i * sizeof(uint64_t));
    uint64_t b = *(uint64_t *)out;
    uint32_t l;
    l = b >> 32;
    l2n(l, out);
    l = b;
    l2n(l, out);
  }
}

void open_file(char *buff) {
  char *file_name = buff + 32; // skip key
  file_name[strlen(file_name) - 1] = '\0'; // removing newline at the end
  fd = open(file_name, O_RDWR);
  struct stat s;
  fstat(fd, &s);
  file_length = s.st_size;
  mapped = mmap(NULL, file_length, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
  map_to_be();
  free(buff);
  start_iteration();
}

void close_file() {
  end_iteration();
  map_to_le();
  munmap(mapped, file_length);
  close(fd);
  print_time();
}

bool read_block(uint64_t **bs, uint32_t *len) {
  static size_t rptr = 0;
  if (rptr >= file_length) {
    return false;
  }

  size_t bytes_read = min(file_length - rptr, CHUNK_LENGTH);
  *len = bytes_read / sizeof(uint64_t);
  *bs = (uint64_t *)(mapped + rptr);
  rptr += bytes_read;
  return true;
}

bool write_block(uint64_t *bs, uint32_t *len) {
  static size_t wptr = 0;
  size_t bytes_written = *len * sizeof(uint64_t);
  memcpy(mapped + wptr, bs, bytes_written);
  wptr += bytes_written;

  if (wptr >= file_length) {
    close_file();
    return false;
  }
  return true;
}

void read_key(uint8_t *key) {
  char *buff = malloc(1024 * sizeof(char));
  size_t len = 1024;
  ssize_t read = getline(&buff, &len, stdin);

  if (read > 0) {
    for (int i = 0; i < 16; ++i) {
      sscanf(buff + i * 2, "%2hhx", &key[i]);
    }
  }
  open_file(buff);
}

#endif // IO_H_

