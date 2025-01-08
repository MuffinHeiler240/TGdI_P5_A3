#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ZEILEN 4
#define SPALTEN 4
#include "matrix.h"
#include "vector.h"

matrix random_matrix(matrix m) {
    unsigned short i,j;
    for ( i = 0; i < rows(m); i++) {
        for (j= 0; j < cols(m); j++) {
            setEntry(m,i,j,(rand() % 65)-32);
        }
    }
    return m;
}

vector random_vector(vector v) {
    unsigned short i;
    for (i = 0; i < size(v); i++) {
        setValue(v,i, (rand() % 65)-32);
    }
    return  v;
}

void print_matrix(matrix m) {
    unsigned short i,j;
    for ( i = 0; i < rows(m); i++) {
        for (j= 0; j < cols(m); j++) {
            printf("%4.0d |", getEntry(m,i,j));
        }
        printf("\n");
    }
}

void print_vector(vector v) {
    unsigned short i;
    for (i = 0; i < size(v); i++) {
        printf("%4.0d \n", getValue(v,i));
    }
    printf("\n");
}

int main(void) {
    int i, print = 0;
    srand(time(NULL));

    for (i = 2; i <= 200; i++) {
        matrix m = createMatrix(i, i);
        random_matrix(m);

        matrix n = createMatrix(i, i);
        random_matrix(m);

        clock_t start, end;
        double time_req, time_reqVar;

        // Timing first function
        start = clock();
        matrix result = matrixDotMatrix(m, n);
        end = clock();
        time_req = (double)(end - start) / CLOCKS_PER_SEC;

        // Timing second function
        start = clock();
        result = matrixDotMatrixWithTempVar(m, n);
        end = clock();
        time_reqVar = (double)(end - start) / CLOCKS_PER_SEC;

        if (print != 0) {
            printf("Matrix A:\n");
            print_matrix(m);
            printf("\n");
            printf("Vector b:\n");
            print_matrix(n);
            printf("Matrix A * Vector b:\n");
            print_matrix(result);
        }
        printf("%d;", i);
        printf("%.6f;", time_req);
        printf("%.6f\n", time_reqVar);


        //printf("i =  %d\n", i);
        //printf("Time     : %.6f seconds\n", time_req);
        //printf("Time Temp: %.6f seconds\n\n", time_reqVar);
    }


    return 0;

}
