#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

int main()
{
	char *s;

	s = strdup("h");
	s = "test";
	printf("firtst = %s\n", s);
	// free(s);
	s = "ahmed sidi hamada";
	printf("second = %s\n", s);
}