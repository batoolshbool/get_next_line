#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"
int main()
{
	int fd = (open("a.txt", O_RDONLY));
	int fd2 = (open("b.txt", O_RDONLY));
	int fd3 = (open("c.txt", O_RDONLY));

	char *a = NULL;

	while(a == get_next_line(fd))
		printf("1 -> %s", a);
	printf("2a -> %s", get_next_line(fd));
	printf("3a -> %s", get_next_line(fd));
	printf("1c -> %s", get_next_line(fd3));
	printf("2c -> %s", get_next_line(fd3));
	printf("1b -> %s", get_next_line(fd2));
	printf("2b -> %s", get_next_line(fd2));
	printf("3c -> %s", get_next_line(fd3));
	printf("4c -> %s", get_next_line(fd3));
	printf("4a -> %s", get_next_line(fd));
}