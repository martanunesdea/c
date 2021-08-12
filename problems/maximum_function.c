
#include <stdlib.h>
#include <stdio.h>

double fill_matrix( int nrows, int ncols, double matrix[nrows][ncols] ) {
    double max = matrix[0][0]; 
    for(int r=0; r<nrows; ++r) {
        for(int c=0; c<ncols; ++c) {
            matrix[r][c] = r;
            printf("%f ", matrix[r][c]); 
        }
        printf("\n");
    }

    return max;
}

double maximum( int nrows, int ncols, double matrix[nrows][ncols] ) {
    double max = matrix[0][0]; 
    for(int r=0; r<nrows; ++r) {
        for(int c=0; c<ncols; ++c) {
            if ( max < matrix[r][c] )
                max = matrix[r][c]; 
        }
    }

    return max;
}

int main()
{
    int nrows = 2;
    int ncols = 2;
    double matrix1[nrows][ncols];
    double res = fill_matrix(nrows, ncols, matrix1);
    res = maximum (nrows, ncols, matrix1);
    printf("max is %f", res);
}