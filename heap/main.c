#include <stddef.h>
#include <stdio.h>

#include "heap.h"

/*void procedure(int* arr, unsigned int N)
{
  if (N==0)
    return;
  int t;
  unsigned int n = N, parent = N/2, index, child;
  for (;;) {
    if (parent > 0) {
      t = arr[--parent];
    } else {
      n--;
      if (n == 0)
        return;
      t = arr[n];
      arr[n] = arr[0];
    }
    index = parent;
    child = index * 2 + 1;
    while (child < n) {
      if (child + 1 < n  &&  arr[child + 1] > arr[child])
        child++;
      if (arr[child] <= t)
        break;
      arr[index] = arr[child];
      index = child;
      child = index * 2 + 1;
    }
    arr[index] = t;
  }
}*/

int main(void)
{
    struct heap *test = create_heap();
    add(test, 2);
    add(test, 32);
    add(test, 3);
    add(test, 68);
    add(test, 55);
    add(test, 2);
    add(test, 69);
    print_heap(test);
    pop(test);
    print_heap(test);
    pop(test);
    print_heap(test);
    pop(test);
    print_heap(test);
    pop(test);
    print_heap(test);
    delete_heap(test);
    return 0;
}
