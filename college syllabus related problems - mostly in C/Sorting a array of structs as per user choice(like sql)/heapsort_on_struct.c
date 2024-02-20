#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct student {
  int roll_no;
  char name[50];
  int marks;
};

void heapify(struct student arr[], int n, int i, int option) {
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;

  if (option == 1) { // sort based on roll no
    if (l < n && arr[l].roll_no > arr[largest].roll_no) {
      largest = l;
    }

    if (r < n && arr[r].roll_no > arr[largest].roll_no) {
      largest = r;
    }
  } else if (option == 2) { // sort based on name
    if (l < n && strcmp(arr[l].name, arr[largest].name) > 0) {
      largest = l;
    }

    if (r < n && strcmp(arr[r].name, arr[largest].name) > 0) {
      largest = r;
    }
  } else if (option == 3) { // sort based on marks
    if (l < n && arr[l].marks > arr[largest].marks) {
      largest = l;
    }

    if (r < n && arr[r].marks > arr[largest].marks) {
      largest = r;
    }
  }

  if (largest != i) {
    struct student temp = arr[i];
    arr[i] = arr[largest];
    arr[largest] = temp;

    heapify(arr, n, largest, option);
  }
}

void heapsort(struct student arr[], int n, int option) {
  for (int i = n / 2 - 1; i >= 0; i--) {
    heapify(arr, n, i, option);
  }

  for (int i = n - 1; i >= 0; i--) {
    struct student temp = arr[0];
    arr[0] = arr[i];
    arr[i] = temp;

    heapify(arr, i, 0, option);
  }
}

int main() {
  int n, option;

  //clrscr(); // clear the console

  printf("Enter the number of students: ");
  scanf("%d", &n);

  struct student arr[n];

  for (int i = 0; i < n; i++) {
    printf("Enter roll no. for student %d: ", i + 1);
    scanf("%d", &arr[i].roll_no);
    printf("Enter name for student %d: ", i + 1);
    getchar(); // consume newline character
    fgets(arr[i].name, 50, stdin);
    arr[i].name[strcspn(arr[i].name, "\n")] = '\0'; // remove newline character
    printf("Enter marks for student %d: ", i + 1);
    scanf("%d", &arr[i].marks);
  }

  printf("Enter the option for sorting (1 for roll no., 2 for name, 3 for marks): ");
  scanf("%d", &option);

  heapsort(arr, n, option);

  printf("Sorted collection:\n");
  for (int i = 0; i < n; i++) {
    printf("%d\t%s\t%d\n", arr[i].roll_no, arr[i].name, arr[i].marks);
  }

  //getch(); // wait for a key press before exiting
  return 0;
}
