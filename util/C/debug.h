#ifndef DEBUG_H
#define DEBUG_H

/* Debug macro */
#define DIE(assertion, message)               \
  do {                                        \
    if (assertion) {                          \
      fprintf(stderr,"error: %s:%s %s in %s", \
              __FILE__,                       \
              __LINE__,                       \
              __func__, message);             \
      exit(EXIT_FAILURE);                     \
    }                                         \
  } while(0)

/* Find maximum of two numbers */
#define MAX(a,b) ((a)>(b)?(a):(b))

/* Find minimum of two numbers */
#define MIN(a,b) ((a)<(b)?(a):(b))

#endif /* DEBUG_H */
