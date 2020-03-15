#include <cstdio>
#include <cstdlib>

#define ARRAY_SIZE 10000

int* binary_search(const int* list, int size, int value) {

  int msize = size;
  int base = 0;

  while (msize > 1) {
    int half = msize / 2;
    int mid = base + half;

    // mid está sempre entre 0 e size, significa que mid >= 0 e < size.
    // mid >= 0: por definição
    // mid < size: mid = size / 2 + size / 4 + size / 8 ...
    base = list[mid] > value ? base : mid;
    msize -= half;
  }

  // base está sempre entre 0 e size devido a base <= mid.
  int found = list[base];

  return const_cast<int *>(found == value ? &list[base] : NULL);
}

int main() {
  int value = 9030;

  int* array = (int*) malloc(sizeof(int) * ARRAY_SIZE);

  if (array == NULL) {
    fprintf(stderr, "Não foi possível alocar a memória para: %d", ARRAY_SIZE);

    exit(1);
  }

  for(int i = 0; i < ARRAY_SIZE; i++) {
    array[i] = i;
  }

  int* found = binary_search(array, ARRAY_SIZE, value);

  if (found == NULL) {
    fprintf(stderr, "Não encontrou o valor: %d", value);

    exit(1);
  }

  printf("Encontrou o valor: %d", *found);

}