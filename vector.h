#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
#include <sys/types.h>

/* MACROS */
/* Cast to typeof pointer at this address */
#define _vector_push_back(vec_address) \
  ((typeof(*vec_address))(vector_push_back((vector*)vec_address, sizeof(**vec_address))
#define _vector_insert_assert(vec_address, pos) \
  ((typeof(*vec_address))(vector_insert((vector*)vec_address, sizeof(**vec_address), pos)

/* Verify that the pointer type of vector matches its contents */
#define vector_push_back_assert(vec_address, value) \
  ((*_vector_push_back(vec_address) = value)
#define vector_insert_assert(vec_address, value, pos) \
  ((*_vector_insert_assert(*vec_address, pos) = value);

/* TYPEDEFS */
typedef size_t        vec_size_t;
typedef unsigned char vec_type_size_t; /* used to store size of type */
typedef int*          vec_int;
typedef char*         vec_char;
typedef float*        vec_float;
typedef double*       vec_double;

typedef struct vector {
  vec_size_t bytes_allocated;
  vec_size_t length;
  void**     data; /* access data within vector */
} vector;

void vector_push_back(vector* vec_address, vec_size_t);
void vector_insert(vector*, vec_size_t, vec_int);

#endif
