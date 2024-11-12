#include <stdio.h>    //ASSI1
#include <stdlib.h>

struct stud {
    int rn;
    char name[10];
    int marks;
};

void accept(struct stud s[], int n) {
    int i;
    printf("\nEnter Students' roll number, name, and marks:\n");
    for (i = 0; i < n; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll Number: ");
        scanf("%d", &s[i].rn);
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Marks: ");
        scanf("%d", &s[i].marks);
    }
}

void display(struct stud s[], int n) {
    int i;
    printf("\nStudents Data:\n");
    printf("Roll Number\tName\tMarks\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%s\t%d\n", s[i].rn, s[i].name, s[i].marks);
    }
}

void bubblesort(struct stud s[], int n) {
    int i, j;
    struct stud temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (s[j].rn > s[j + 1].rn) {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

void selectionsort(struct stud s[], int n) {
    int i, j, minpos;
    struct stud temp;
    for (i = 0; i < n - 1; i++) {
        minpos = i;
        for (j = i + 1; j < n; j++) {
            if (s[j].rn < s[minpos].rn) {
                minpos = j;
            }
        }
        if (minpos != i) {
            temp = s[i];
            s[i] = s[minpos];
            s[minpos] = temp;
        }
    }
}

void insert_sort(struct stud arr[], int n) {
    int i, j;
    struct stud key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j].rn > key.rn) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void shell_sort(struct stud arr[], int n) {
    int gap, i, j;
    struct stud temp;
    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            temp = arr[i];
            for (j = i; j >= gap && arr[j - gap].rn > temp.rn; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main() {
    int n;
    int choice;
    struct stud s[10];

    printf("\nEnter the number of students: ");
    scanf("%d", &n);
    accept(s, n);
    display(s, n);

    do {
        printf("\n1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Shell Sort\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bubblesort(s, n);
                printf("\nData sorted using Bubble Sort:\n");
                display(s, n);
                break;

            case 2:
                selectionsort(s, n);
                printf("\nData sorted using Selection Sort:\n");
                display(s, n);
                break;

            case 3:
                insert_sort(s, n);
                printf("\nData sorted using Insertion Sort:\n");
                display(s, n);
                break;

            case 4:
                shell_sort(s, n);
                printf("\nData sorted using Shell Sort:\n");
                display(s, n);
                break;

            case 5:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Wrong option. Please enter a number between 1 and 5.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}
