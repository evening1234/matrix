#include <iostream>
#include <cstdio>
#include <ctime>
#include <unistd.h>

int **readMatrix(const char *fileName) {
    int c, r;
    int **matrix = (int **) malloc(sizeof(int *) * r);
    FILE *file = fopen(fileName, "r");
    fscanf(file, "%d %d", &r, &c);
    for (int i = 0; i < r; i++) {
        matrix[i] = (int *) malloc(sizeof(int) * c);
        for (int j = 0; j < c; j++) {
            fscanf(file, "%d ", &(matrix[i][j]));
        }
    }
    fclose(file);
    printf("\n");
    return matrix;
}

void saveMatrix(int r, int c, int **matrix, const char *fileName) {
    FILE *file = fopen(fileName, "w");
    fprintf(file, "%d %d\n", r, c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", matrix[i][j]);
            fprintf(file, "%d ", matrix[i][j]);
        }
        printf("\n");
        fprintf(file, "\n");
    }
    printf("\n");

    fclose(file);
}

int **generateMatrix(int r, int c) {
    int **matrix = (int **) malloc(sizeof(int *) * r);
    for (int i = 0; i < r; i++) {
        matrix[i] = (int *) malloc(sizeof(int) * c);
        for (int j = 0; j < c; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
    return matrix;
}

int **multiply(int **matrix1, int **matrix2, int r, int c) {
    int **result = (int **) malloc(sizeof(int *) * r);
    for (int i = 0; i < r; i++) {
        result[i] = (int *) malloc(sizeof(int) * c);
        for (int j = 0; j < c; j++) {
            int sum = 0;
            for (int k = 0; k < r; k++) {
                sum += matrix1[i][k] * matrix2[k][j];
            }
            result[i][j] = sum;
        }
    }
    return result;
}

void freeMatrix(int **matrix, int c) {
    for (int i = 0; i < c; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int r1, c1, r2, c2;

    printf("podaj ilość wierszy pierwszej macierzy: ");
    scanf("%d", &r1);
    printf("podaj ilość kolumn pierwszej macierzy: ");
    scanf("%d", &c1);
    printf("podaj ilość wierszy drugiej macierzy: ");
    scanf("%d", &r2);
    printf("podaj ilość kolumn drugiej macierzy: ");
    scanf("%d", &c2);
    printf("\n");

    srand(time(NULL));

    if (c1 != r2) {
        printf("nie można mnożyć");
    } else {
        int **matrix1 = generateMatrix(r1, c1);
        int **matrix2 = generateMatrix(r2, c2);
        saveMatrix(r1, c1, matrix1, "matrix1.txt");
        saveMatrix(r2, c2, matrix2, "matrix2.txt");
//        freeMatrix(matrix1, c1);
//        freeMatrix(matrix2, c2);

        matrix1 = readMatrix("matrix1.txt");
        matrix2 = readMatrix("matrix2.txt");

        int **matrix = multiply(matrix1, matrix2, r1, c2);
        saveMatrix(r1, c2, matrix, "result.txt");

        freeMatrix(matrix, c2);
        freeMatrix(matrix1, c1);
        freeMatrix(matrix2, c2);
    }

    return 0;
}
