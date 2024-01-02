#include <iostream>
#include <cstdio>
#include <ctime>
#include <unistd.h>
using namespace std;
int **reading(const char *fileName) {
    int c,r;
    int **matrix = (int **) malloc(sizeof(int *) * r);
    FILE *file = fopen(fileName, "r");
    fscanf(file, "%d\n",&r);
    fscanf(file, "%d\n",&c);
    for (int i = 0; i < r; i++) {
        matrix[i] = (int *) malloc(sizeof(int *) * c);
        for (int j = 0; j < c; j++) {
            fscanf(file, "%d ", &(matrix[i][j]));
        }
        cout << endl;
    }
    fclose(file);
    return matrix;
}
void saveMatrix(int r, int c, int **matrix, const char *fileName) {
    FILE *file = fopen(fileName, "w");
    fprintf(file, "%d %d\n", r, c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << matrix[i][j] << " ";
            fprintf(file, "%d ", matrix[i][j]);
        }
        cout << endl;
        fprintf(file, "\n");
    }

    fclose(file);
}
int **generateMatrix(int r, int c) {
    int **arr = (int **) malloc(sizeof(int *) * r);
    for (int i = 0; i < r; i++) {
        arr[i] = (int *) malloc(sizeof(int) * c);
        for (int j = 0; j < c; j++) {
            arr[i][j] = rand() % 100;
        }
    }
    return arr;
}
int **last(int **arr1,int **arr2,int c, int r) {
    int **result = (int **) malloc(sizeof(int *) * r);
    for (int i = 0; i < r; i++) {
        result[i] = (int *) malloc(sizeof(int) * c);
        cout<<endl;
        for (int j = 0; j < c; j++) {
            int sum = 0;
            for(int k=0;k<c;k++) {
                sum += arr1[i][k] * arr2[k][j];
                //printf("sum = %d\n", sum);
            }
            result[i][j] = sum;
            //printf("% d", result[i][j]);
        }
    }
    return result;
}
int main() {
    int n;
    int m;
    int x;
    int y;
    printf("podaj ilość wierszy pierwszej macierzy:");
    scanf("%d",&n);
    printf("podaj ilość kolumn pierwszej macierzy:");
    scanf("%d",&m);

    printf("podaj ilość wierszy drugiej macierzy:");
    scanf("%d",&x);
    printf("podaj ilość kolumn drugiej macierzy:");
    scanf("%d",&y);
    cout<<endl;


    srand(time(NULL));
    if (m != x) {
        printf("nie mozna mnozyc");
    } else {
        int **matrix1 = generateMatrix(n, m);
        int **matrix2 = generateMatrix(x, y);
        saveMatrix(n, m, matrix1, "matrix1.txt");
        cout<<endl;
        saveMatrix(x, y, matrix2, "matrix2.txt");
        free(matrix1);
        free(matrix2); // TODO free memory correctly, that is, remove free columns/rows
    }


    int z = m *n;
    int e = x * y;


    int **arr1 = reading("matrix1.txt");
    cout<<endl;
    int **arr2 = reading("matrix2.txt");
    cout<<endl;
    // TODO free result, free intermediete matrixes


    int **matrix = last(arr1,arr2,y,n);
    FILE *file = fopen("last.txt", "w");
    fclose(file);
    saveMatrix(n,x,matrix,"last.txt");



    return 0;
}
