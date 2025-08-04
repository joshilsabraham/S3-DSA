#include <stdio.h>
#define MAX 100

void readSparse(int sparse[100][100], int rows, int cols) {
    int i, j;
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            scanf("%d", &sparse[i][j]);
        }
    }
}

int sparseToMatrix(int matrix[MAX][3], int rows, int cols, int sparse[MAX][MAX]) {
    int i, j, k = 1;
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            if(sparse[i][j] != 0) {
                matrix[k][0] = i;
                matrix[k][1] = j;
                matrix[k][2] = sparse[i][j];
                k++;
            }
        }
    }
    return k;
}

void displayMatrix(int matrix[MAX][3], int count, int rows, int cols) {
    int i, j;
    matrix[0][0] = rows;
    matrix[0][1] = cols;
    matrix[0][2] = count - 1;

    printf("Row\tCol\tValue\n");
    for(i = 0; i < count; i++) {
        for(j = 0; j < 3; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void transposeMatrix(int original[MAX][3], int transpose[MAX][3]) {
    int i;
    int rows = original[0][0];
    int cols = original[0][1];
    int nonZero = original[0][2];

    transpose[0][0] = cols;
    transpose[0][1] = rows;
    transpose[0][2] = nonZero;

    for(i = 1; i <= nonZero; i++) {
        transpose[i][0] = original[i][1]; // swap row and column
        transpose[i][1] = original[i][0];
        transpose[i][2] = original[i][2];
    }
}

int main() {
    int sparse1[MAX][MAX], sparse2[MAX][MAX];
    int matrix1[MAX][3], matrix2[MAX][3], result[MAX][3];
    int rows1, cols1, rows2, cols2;
    int count1, count2, countResult;

    printf("Enter the number of rows of first sparse matrix: ");
    scanf("%d", &rows1);
    printf("Enter the number of columns of first sparse matrix: ");
    scanf("%d", &cols1);
    printf("Enter the first sparse matrix:\n");
    readSparse(sparse1, rows1, cols1);
    count1 = sparseToMatrix(matrix1, rows1, cols1, sparse1);

    printf("Enter the number of rows of second sparse matrix: ");
    scanf("%d", &rows2);
    printf("Enter the number of columns of second sparse matrix: ");
    scanf("%d", &cols2);
    printf("Enter the second sparse matrix:\n");
    readSparse(sparse2, rows2, cols2);
    count2 = sparseToMatrix(matrix2, rows2, cols2, sparse2);

    printf("\nFirst resultant matrix\n");
    displayMatrix(matrix1, count1, rows1, cols1);

    printf("\nSecond resultant matrix\n");
    displayMatrix(matrix2, count2, rows2, cols2);

    if (rows1 != rows2 || cols1 != cols2) {
        printf("\nMatrices dimensions do not match for addition.\n");
        return 1;
    }

    int i = 1, j = 1, k = 1;
    result[0][0] = rows1;
    result[0][1] = cols1;

    while (i < count1 && j < count2) {
        if (matrix1[i][0] == matrix2[j][0] && matrix1[i][1] == matrix2[j][1]) {
            int sumVal = matrix1[i][2] + matrix2[j][2];
            if (sumVal != 0) {
                result[k][0] = matrix1[i][0];
                result[k][1] = matrix1[i][1];
                result[k][2] = sumVal;
                k++;
            }
            i++; j++;
        }
        else if (matrix1[i][0] < matrix2[j][0] || 
                 (matrix1[i][0] == matrix2[j][0] && matrix1[i][1] < matrix2[j][1])) {
            result[k][0] = matrix1[i][0];
            result[k][1] = matrix1[i][1];
            result[k][2] = matrix1[i][2];
            k++; i++;
        }
        else {
            result[k][0] = matrix2[j][0];
            result[k][1] = matrix2[j][1];
            result[k][2] = matrix2[j][2];
            k++; j++;
        }
    }

    while (i < count1) {
        result[k][0] = matrix1[i][0];
        result[k][1] = matrix1[i][1];
        result[k][2] = matrix1[i][2];
        k++; i++;
    }

    while (j < count2) {
        result[k][0] = matrix2[j][0];
        result[k][1] = matrix2[j][1];
        result[k][2] = matrix2[j][2];
        k++; j++;
    }

    result[0][2] = k - 1;

    printf("\nResultant matrix after addition\n");
    displayMatrix(result, k, rows1, cols1);

    int transposed[MAX][3];
    transposeMatrix(result, transposed);

    printf("\nTranspose of the resultant matrix\n");
    displayMatrix(transposed, transposed[0][2] + 1, transposed[0][0], transposed[0][1]);

    return 0;
}
