#include <stdio.h>
#include <stdlib.h>

#include "null_terminated_arrays.c"

int main(void)
{
	const char test[4][10] = {
		"1", 
		"2", 
		"3", 
		NULL
       	};
	test = reverse_array(test);
	for (size_t i = 0; i < 4; i++)
	{
		printf("%s \n", test[i]);
	}
	return 0;
}

