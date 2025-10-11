#include <fcntl.h>
#include <stdio.h>
#include "get_next_line_bonus.h"

int main()
{
	int a = (open("a.txt", O_RDONLY));
	int b = (open("b.txt", O_RDONLY));
	int c = (open("c.txt", O_RDONLY));

	printf("1a -> %s", get_next_line(a));
	printf("2a -> %s", get_next_line(a));
	printf("1c -> %s", get_next_line(c));
	printf("2c -> %s", get_next_line(c));
	printf("1b -> %s", get_next_line(b));
	printf("2b -> %s", get_next_line(b));
	printf("3c -> %s", get_next_line(c));
	printf("4c -> %s", get_next_line(c));
	printf("3a -> %s", get_next_line(a));
}