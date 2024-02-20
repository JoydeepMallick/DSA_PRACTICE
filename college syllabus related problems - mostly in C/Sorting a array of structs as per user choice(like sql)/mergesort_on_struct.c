
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
  int roll_no;
  char name[50];
  int marks;
};

void merge(struct student arr[], int l, int m, int r, int option) {
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;

  struct student L[n1], R[n2];

  for (i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for (j = 0; j < n2; j++)
    R[j] = arr[m + 1 + j];

  i = 0;
  j = 0;
  k = l;
  while (i < n1 && j < n2) {
    if (option == 1) { // sort based on roll no
      if (L[i].roll_no <= R[j].roll_no) {
        arr[k] = L[i];
        i++;
      } else {
        arr[k] = R[j];
        j++;
      }
    } else if (option == 2) { // sort based on name
      if (strcmp(L[i].name, R[j].name) <= 0) {
        arr[k] = L[i];
        i++;
      } else {
        arr[k] = R[j];
        j++;
      }
    } else if (option == 3) { // sort based on marks
      if (L[i].marks <= R[j].marks) {
        arr[k] = L[i];
        i++;
      } else {
        arr[k] = R[j];
        j++;
      }
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}

void merge_sort(struct student arr[], int l, int r, int option) {
  if (l < r) {
    int m = l + (r - l) / 2;
    merge_sort(arr, l, m, option);
    merge_sort(arr, m + 1, r, option);
    merge(arr, l, m, r, option);
  }
}

int main() {
  int n, option;

  printf("Enter the number of students: ");
  scanf("%d", &n);

  struct student arr[n];

  for (int i = 0; i < n; i++) {
    printf("Enter roll no. for student %d: ", i + 1);
    scanf("%d", &arr[i].roll_no);
    printf("Enter name for student %d: ", i + 1);
    getchar(); // consume newline character
    fgets(arr[i].name, 50, stdin);
    arr[i].name[strcspn(arr[i].name, "\n")] = '\0'; // remove newline character which was stored when enter was pressed
    printf("Enter marks for student %d: ", i + 1);
    scanf("%d", &arr[i].marks);
  }

  printf("Enter the option for sorting (1 for roll no., 2 for name, 3 for marks): ");
  scanf("%d", &option);

  merge_sort(arr, 0, n - 1, option);

  printf("Sorted collection:\n");
  for (int i = 0; i < n; i++) {
    printf("%d\t%s\t%d\n", arr[i].roll_no, arr[i].name, arr[i].marks);
  }
}
