// Write a program to implement Quick Sort.
// Quick sort in C

#include <stdio.h>
void s(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int p(int a[], int l, int h) {
  int p = a[h];
  int i = (l - 1);
  for (int j = l; j < h; j++) {
    if (a[j] <= p) {
      i++;
      s(&a[i], &a[j]);
    }
  }
  s(&a[i + 1], &a[h]);
  return (i + 1);
}

void qs(int a[], int l, int h) {
  if (l < h) {
    int pi = p(a, l, h);
    qs(a, l, pi - 1);
    qs(a, pi + 1, h);
  }
}
void pa(int a[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", a[i]);
  }
  printf("\n");
}
int main() {
  int data[] = {8, 7, 2, 1, 0, 9, 6};
  int n = sizeof(data) / sizeof(data[0]);
  qs(data, 0, n - 1);
  printf("Sorted is ");
  pa(data, n);
}