//
// Created by jgreive on 20.12.2024.
//

#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

typedef struct vector_struct {
    unsigned short n;
    int *data;
} vector_struct;

vector createVector(unsigned short n) {
    vector v = (vector) malloc(sizeof(vector_struct));
    v->n = n;
    v->data = (int *) calloc(n, sizeof(int));
    return v;
}

void rmVector(vector v) {
    free(v->data);
    free(v);
}

unsigned short size(vector v) {
    return v->n;
}

int* values(vector v) {
    return v->data;
}

int getValue(vector v, unsigned short j) {
    if( j >= v->n) {
        printf("Error: index out of bounds\n");
        exit(-1);
    }
    return v->data[j];
}

void setValue(vector v, unsigned short j, int value) {
    if( j >= v->n) {
        printf("Error: index out of bounds\n");
        exit(-1);
    }
    v->data[j] = value;
}

int vectorDotVector(vector a, vector b) {
    unsigned short i;
    int c = 0;

    if (a->n != b->n) {
        printf("Error: vector dimensions do not match\n");
        exit(-1);
    }

    for (i = 0; i < a->n; c += a->data[i] * b->data[i], i++){}
    return c;
}

vector vectorPlusVector(vector a, vector b) {
    unsigned short i;
    vector c = createVector(a->n);

    if (a->n != b->n) {
        printf("Error: vector dimensions do not match\n");
        exit(-1);
    }

    for (i = 0; i < a->n; c->data[i] = a->data[i] + b->data[i], i++) {}
    return c;
}