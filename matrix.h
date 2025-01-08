
#ifndef MATRIX_H_
#define MATRIX_H_
#include "vector.h"
/** forward declaration to an internal hidden matrix structure. */
typedef struct matrix_struct *matrix;

/** create a (zero filled) NxM int matrix.
 *  @param n the number of rows, with 0<n
 *  @param m the number of columns with 0<m
 *  @return a NxM int matrix reference
 */
matrix createMatrix(unsigned short n, unsigned short m);

/**
 * remove a matrix freeing allocated memory.
 *  @param a valid matrix reference
 */
void rmMatrix(matrix a);

/** return the number of matrix rows.    */
unsigned short rows(matrix a);

/** return the number of matrix columns. */
unsigned short cols(matrix a);

/** access to the internal NxM data.     */
int** data(matrix a);

/** get the matrix entry with index r,c
 * @param a matrix reference
 * @param r the row number  0<=r < N
 * @param c the column number 0<=c< M
 * @return the entry
 * @print error and exits if dimensions wrong
 */
int getEntry(matrix a, unsigned short r, unsigned short c);

/** set the matrix entry with index r,c
 * @param a matrix reference
 * @param r the row number  0<=r < N
 * @param c the column number 0<=c< M
 * @param v the data value
 * @print error and exits if dimensions wrong
 */
void setEntry(matrix a, unsigned short r, unsigned short c, int v);

/**
 * Calculate the matrix product C = A * B. This method reports an
 * error if the matrix dimensions don't match and calls exit(-1).
 * @param a the A matrix reference
 * @param b the B matrix reference
 * @return the matrix C=A*B
 * @print error and exits if dimensions wrong
 */
matrix matrixDotMatrix(matrix a, matrix b);

/**
 * Calculate the matrix product C = A * B. This method reports an
 * error if the matrix dimensions don't match and calls exit(-1).
 * @param a the A matrix reference
 * @param b the B matrix reference
 * @return the matrix C=A*B
 * @print error and exits if dimensions wrong
 */
matrix matrixDotMatrixWithTempVar(matrix a, matrix b);

/**
 * Calculate the matrix addition C = A + B. This method reports an
 * error if the matrix dimensions don't match and calls exit(-1).
 * @param a the A matrix reference
 * @param b the B matrix reference
 * @return the matrix C=A+B
 * @print error and exits if dimensions wrong
 */
matrix matrixPlusMatrix(matrix a, matrix b);

/**
 * Calculate the matrix vector multiplication y = A * x. This method reports an
 * error if the dimensions don't match and calls exit(-1).
 * @param a the A matrix reference
 * @param x the vector reference
 * @return the vector y=A*x
 * @print error and exits if dimensions wrong
 */
vector matrixDotVector(matrix a, vector x);

/**
 * Calculate the matrix vector multiplication y = A * x with temp variable. This method reports an
 * error if the dimensions don't match and calls exit(-1).
 * @param a the A matrix reference
 * @param x the vector reference
 * @return the vector y=A*x
 * @print error and exits if dimensions wrong
 */
vector matrixDotVectorWithTempVar(matrix a, vector x);

#endif /* MATRIX_H_ */