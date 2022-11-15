#include <stdio.h>
#include <stdlib.h>

#include "list.c"

int main(void)
{
	struct list *list = NULL;
	const void *val = malloc(sizeof(const void *) * 100);
	size_t data_size = 100;
	list = list_prepend(list, val, data_size);
	list = list_prepend(list, val, data_size);
	printf("%ld \n", list_length(list));
	list_destroy(list);
}
