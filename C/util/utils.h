#ifndef UTILS_H
#define UTILS_H

#define INIT_STR_CAP 2
#define MAX_INT_DIGITS 20
#define MAX_DOUBLE_DIGITS 40
#define TYPE_DIM 20
#define OP_DIM 20

#define DIE(assertion, call_description)  \
  do {                                    \
    if (assertion) {                      \
      fprintf(stderr, "(%s, %d): ",       \
              __FILE__, __LINE__);        \
      perror(call_description);           \
                  exit(EXIT_FAILURE);     \
    }                                     \
  } while(0)


typedef int (*fprint_t)(FILE*, const char*, ...);
typedef char* (*to_string_t)(const void*);

#endif /* UTILS_H */
