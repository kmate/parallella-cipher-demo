#ifndef IO_H_
#define IO_H_

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include <pthread.h>

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;

bool moreToRead = true;
size_t unprocessedBytes = 0;

bool read_block(uint64_t *b) {
  size_t bytesRead = 0;
  *b = 0;

  while (bytesRead < sizeof(uint64_t) && !feof(stdin)) {
    bytesRead += fread((uint8_t *)b + bytesRead, sizeof(uint8_t), 1, stdin);
  }

  pthread_mutex_lock(&m);
  unprocessedBytes += bytesRead;
  if (feof(stdin)) {
    moreToRead = false;
  }
  pthread_mutex_unlock(&m);

  return true;
}

bool write_block(uint64_t b) {
  pthread_mutex_lock(&m);
  bool writeIt = unprocessedBytes > 0;
  bool more = moreToRead || writeIt;
  unprocessedBytes -= sizeof(uint64_t);
  pthread_mutex_unlock(&m);

  if (writeIt) {
    fwrite(&b, sizeof(uint64_t), 1, stdout);
    fflush(stdout);
  }

  return more;
}

#endif // IO_H_

