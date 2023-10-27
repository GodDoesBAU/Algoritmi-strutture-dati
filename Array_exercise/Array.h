#ifndef C_ARRAY_H
#define C_ARRAY_H

#include <stdlib.h>
#include <stdbool.h>

#define MIN_VALUE 1
#define MAX_VALUE 1000

enum status {
    undefined = 0,
    ascending = 1,
    decreasing = 2,
    constant = 3
};

typedef struct {
    int* Array;
    int length;
} C_Array;

void initialize_Array(C_Array* to_initialize, int length);
int greaterThan(int value, C_Array* to_scan);
bool member(int value, C_Array* to_scan);
int* largest(C_Array* to_scan);
void remove_element(C_Array* to_scan, int to_remove);
int ordering(C_Array* to_scan);
void reverse(C_Array* to_invert);

#endif /* C_ARRAY_H */


