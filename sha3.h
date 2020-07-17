#ifndef __SHA3_H__
#define __SHA3_H__

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define decsha3(bits)                                                          \
  int sha3_##bits(uint8_t *, size_t, uint8_t const *, size_t);

decsha3(256)
decsha3(512)

__attribute__((always_inline)) static inline
void SHA3_256(uint8_t const *ret, uint8_t const *data, size_t const size) {
  sha3_256((uint8_t *)ret, 32, data, size);
}

__attribute__((always_inline)) static inline
void SHA3_512(uint8_t *ret, uint8_t const *data, size_t const size) {
  sha3_512(ret, 64, data, size);
}

#endif