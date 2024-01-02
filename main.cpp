#include <iostream>
#include <cstdio>
#include <ctime>
#include <unistd.h>


using namespace std;

void tablica() {
    int tab[10][5] = {0};
    for (int i = 0; i < 10; i++) {
        printf("%n", *tab);
    }
}


void txt1() {
    int a;
    FILE *f;
    f = fopen("macierz1.txt", "r");
    while (feof(f) != 1) {
        fscanf(f, "%d", &a);
        printf("% d", a);
    }
    fclose(f);
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

void testMatrix() {
    int matrix1[3][4] = {{57, 1, 9, 69},
                         {89, 55, 76, 68},
                         {68, 92, 84, 49}};
    cout<<matrix1<<endl;
    cout<<*matrix1<<endl;
    cout<<**matrix1<<endl; // 57
    cout<<*matrix1[2]<<endl; // 68
    cout<<*(matrix1[2])<<endl; // 68
    cout<<(*matrix1)[2]<<endl; // 9
    cout<<matrix1[2][3]<<endl; // 49

//        57 1 9 69
//        89 55 76 68
//        68 92 84 49

// {{57 1 9 69}, {89 55 76 68}, {68 92 84 49}}
}

int main() {
    int n = 3;
    int m = 4;
    int x = 4;
    int y = 3;
//    printf("podaj ilość wierszy pierwszej macierzy:");
//    scanf("%d",&n);
//    printf("podaj ilość kolumn pierwszej macierzy:");
//    scanf("%d",&m);

//    printf("podaj ilość wierszy drugiej macierzy:");
//    scanf("%d",&x);
//    printf("podaj ilość kolumn drugiej macierzy:");
//    scanf("%d",&y);
    srand(time(NULL));
    if (m != x) {
        printf("nie mozna mnozyc");
    } else {
        int **matrix1 = generateMatrix(n, m);
        int **matrix2 = generateMatrix(x, y);

        saveMatrix(n, m, matrix1, "matrix1.txt");
        saveMatrix(x, y, matrix2, "matrix2.txt");
        free(matrix1);
        free(matrix2); // TODO free memory
    }

    testMatrix();

    return 0;
}
