#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>

/* MACROS */
#define _vector_init(vec)                                                      \
  vector vec;                                                                  \
  vector_init(&vec)

#define _vector_add(vec, item) vector_add(&vec, (void *)item);

/* TYPEDEFS */
typedef size_t vec_size_t;
typedef unsigned char vec_type_size_t; /* used to store size of type */
typedef int *vec_int;
typedef char *vec_char;

typedef struct vector {
  vec_type_size_t capacity; /* capacity and total bytes allocated */
  vec_type_size_t total;
  void **data; /* access data of unknown type */
} vector;

void vector_init(vector *);
void vector_add(vector *, void *);

#endif
