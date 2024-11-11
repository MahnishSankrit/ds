#include <stdio.h>

void accept(int arr[5][5], int m, int n) {
    int i, j;
    printf("Enter the matrix values:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
}

void display(int arr[5][5], int m, int n) {
    int i, j;
    printf("Matrix is:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void displaysm(int arr[15][3], int m, int n) {
    int i, j;
    printf("Sparse Matrix representation:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void compact(int arr[5][5], int m, int n, int b[15][3]) {
    b[0][0] = m;
    b[0][1] = n;
    int k = 1;
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (arr[i][j] != 0) {
                b[k][0] = i;
                b[k][1] = j;
                b[k][2] = arr[i][j];
                k++;
            }
        }
    }
    b[0][2] = k - 1;
}

void simpletranspose(int arr[15][3], int b[15][3]) {
    b[0][0] = arr[0][1];
    b[0][1] = arr[0][0];
    b[0][2] = arr[0][2];

    if (b[0][2] <= 0)
        return;

    int q = 1;
    for (int col = 0; col < arr[0][1]; col++) {
        for (int p = 1; p <= arr[0][2]; p++) {
            if (arr[p][1] == col) {
                b[q][0] = arr[p][1];
                b[q][1] = arr[p][0];
                b[q][2] = arr[p][2];
                q++;
            }
        }
    }
    displaysm(b, q, 3);
}

void fasttranspose(int arr[15][3], int b[15][3]) {
    int i, m, n, pos[15], freq[15];
    for (i = 0; i < arr[0][1]; i++) { // initial positon
        pos[i] = 0;
    }
    for (i = 0; i < 15; i++) { //  initial frequency
        freq[i] = 0;
    }
    for (i = 1; i <= arr[0][2]; i++) {// counting frequency 
        m = arr[i][1];
        freq[m]++;
    }
    pos[0] = 1;
    for (i = 1; i < arr[0][1]; i++) { // sarting poistion for transpose
        pos[i] = pos[i - 1] + freq[i - 1];
    }
    for (i = 1; i <= arr[0][2]; i++) {
        m = arr[i][1];
        n = pos[m];
        pos[m]++;
        b[n][0] = arr[i][1];
        b[n][1] = arr[i][0];
        b[n][2] = arr[i][2];
    }
    b[0][0] = arr[0][1];
    b[0][1] = arr[0][0];
    b[0][2] = arr[0][2];
    displaysm(b, b[0][2] + 1, 3);
}

int main() {
    int m, n, choice;
    int arr[5][5], b[15][3], c[15][3];
    int compact_created = 0;

    printf("Enter the order of the matrix (rows and columns):\n");
    scanf("%d%d", &m, &n);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Accept Matrix\n");
        printf("2. Display Matrix\n");
        printf("3. Compact Matrix\n");
        printf("4. Display Compact Matrix\n");
        printf("5. Simple Transpose\n");
        printf("6. Fast Transpose\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                accept(arr, m, n);
                break;
            case 2:
                display(arr, m, n);
                break;
            case 3:
                compact(arr, m, n, b);
                compact_created = 1;
                printf("Compact matrix created successfully.\n");
                break;
            case 4:
                if (compact_created) {
                    displaysm(b, b[0][2] + 1, 3);
                } else {
                    printf("Compact matrix not created yet.\n");
                }
                break;
            case 5:
                if (compact_created) {
                    printf("Simple Transpose:\n");
                    simpletranspose(b, c);
                } else {
                    printf("Compact matrix not created yet.\n");
                }
                break;
            case 6:
                if (compact_created) {
                    printf("Fast Transpose:\n");
                    fasttranspose(b, c);
                } else {
                    printf("Compact matrix not created yet.\n");
                }
                break;
            case 7:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
