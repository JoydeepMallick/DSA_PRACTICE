
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
  int roll_no;
  char name[50];
  int marks;
};


//assume last element as pivot 
int partition(struct student arr[], int low, int high, int option) {
  struct student pivot = arr[high];
  int i = low - 1;

  for (int j = low; j < high; j++) {
    if (option == 1) { // sort based on roll no
      if (arr[j].roll_no <= pivot.roll_no) {
        i++;
        struct student temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    } else if (option == 2) { // sort based on name
      if (strcmp(arr[j].name, pivot.name) <= 0) {
        i++;
        struct student temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    } else if (option == 3) { // sort based on marks
      if (arr[j].marks <= pivot.marks) {
        i++;
        struct student temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }

  struct student temp = arr[i + 1];
  arr[i + 1] = arr[high];
  arr[high] = temp;

  return i + 1;
}

void quicksort(struct student arr[], int low, int high, int option) {
  if (low < high) {
    int pi = partition(arr, low, high, option);

    quicksort(arr, low, pi - 1, option);
    quicksort(arr, pi + 1, high, option);
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
    arr[i].name[strcspn(arr[i].name, "\n")] = '\0'; // remove newline character
    printf("Enter marks for student %d: ", i + 1);
    scanf("%d", &arr[i].marks);
  }

  printf("Enter the option for sorting (1 for roll no., 2 for name, 3 for marks): ");
  scanf("%d", &option);

  quicksort(arr, 0, n - 1, option);

  printf("Sorted collection:\n");
  for (int i = 0; i < n; i++) {
    printf("%d\t%s\t%d\n", arr[i].roll_no, arr[i].name, arr[i].marks);
  }

  return 0;
}
