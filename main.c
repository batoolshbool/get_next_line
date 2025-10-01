#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
int main()
{
	int fd =open("file.txt",O_RDONLY);
	char *u=get_next_line(fd);
	u=get_next_line(fd);
	u=get_next_line(fd);
	printf("%s",u);
	free(u);
	close(fd);
}