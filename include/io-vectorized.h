#ifndef IO_H_
#define IO_H_

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Endiannes conversion based on openssl: crypto/bf/bf_locl.h
#define n2l(c,l) (l =((uint32_t)(*((c)++)))<<24L, \
                  l|=((uint32_t)(*((c)++)))<<16L, \
                  l|=((uint32_t)(*((c)++)))<< 8L, \
                  l|=((uint32_t)(*((c)++))))

#define l2n(l,c) (*((c)++)=(uint8_t)(((l)>>24L)&0xff), \
                  *((c)++)=(uint8_t)(((l)>>16L)&0xff), \
                  *((c)++)=(uint8_t)(((l)>> 8L)&0xff), \
                  *((c)++)=(uint8_t)(((l)     )&0xff))

#define BYTE_LENGTH 4096  // 4k chunks
#define VECTOR_SIZE (BYTE_LENGTH / sizeof(uint64_t))

bool read_block(uint64_t *bs) {
  size_t bytesRead = 0;
  bool readOk = true;

  while (bytesRead < BYTE_LENGTH && !feof(stdin)) {
    bytesRead += fread((uint8_t *)bs + bytesRead, sizeof(uint8_t), BYTE_LENGTH, stdin);
  }

  if (bytesRead < BYTE_LENGTH) {
    readOk = false;
  } else {
    for (int i = 0; i < VECTOR_SIZE; ++i) {
      uint64_t *b = &(bs[i]);
      // Conversion to big-endian
      uint64_t t = *b;
      uint8_t *in = (uint8_t *)&t;
      uint32_t l;
      n2l(in, l);
      *(((uint32_t *)b) + 1) = l;
      n2l(in, l);
      *((uint32_t *)b) = l;
    }
  }

  return readOk;
}

bool write_block(uint64_t *bs) {
  for (int i = 0; i < VECTOR_SIZE; ++i) {
    // Conversion to little-endian
    uint64_t b = bs[i];
    uint8_t *out = (uint8_t *)(&(bs[i]));
    uint32_t l;
    l = b >> 32;
    l2n(l, out);
    l = b;
    l2n(l, out);
  }

  fwrite(bs, sizeof(uint8_t), BYTE_LENGTH, stdout);
  return true;
}

void read_key(uint8_t *key) {
  char *buff = malloc(100 * sizeof(char));
  size_t len = 100;
  ssize_t read = getline(&buff, &len, stdin);

  if (read > 0) {
    for (int i = 0; i < 16; ++i) {
      sscanf(buff + i * 2, "%2hhx", &key[i]);
    }
  }
  free(buff);
}

#endif // IO_H_

