#include <stdio.h>
#include <stdlib.h>

// 再帰関数の例：nの階乗を計算する
int factorial(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * factorial(n-1);
  }
}

// malloc関数とポインタ渡しを用いた関数の例：int型の配列を作成して、その合計を計算する
int sum_array(int* arr, int size) {
  int sum = 0;
  for (int i = 0; i < size; i++) {
    sum += arr[i];
  }
  return sum;
}

int main() {
  // 階乗関数のテスト
  int n = 5;
  printf("%d! = %d\n", n, factorial(n));
  
  // 配列の合計を計算する関数のテスト
  int size = 5;
  int* arr = malloc(sizeof(int) * size);
  for (int i = 0; i < size; i++) {
    arr[i] = i + 1;
  }
  printf("sum of array = %d\n", sum_array(arr, size));
  free(arr); // mallocで確保したメモリを解放する
  
  return 0;
}
