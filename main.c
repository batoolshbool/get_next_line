#include "get_next_line.h"
#include <stdio.h>
 #include <fcntl.h>

int main()
{
	int fd = open("file.txt", O_RDONLY);
	char *hi;
	if (fd < 0)
	{
		printf("error\n");
		return 1;
	}
	while ((hi = get_next_line(fd)) != NULL){
		printf("%s", hi);
		free(hi);}
	close(fd);
	return 0;

}

// #include <stdio.h>
// #include <fcntl.h>    // for open()
// #include <unistd.h>   // for read() and close()
// #include <stdlib.h>   // for exit()

// int main() {
//     int fd;
//     ssize_t bytesRead;
//     char buffer[100];

//     // Open the file for reading
//     fd = open("file.txt", O_RDONLY);
//     if (fd == -1) {
//         perror("Error opening file");
//         exit(EXIT_FAILURE);
//     }

//     // Read up to 100 bytes
//     bytesRead = read(fd, buffer, sizeof(buffer) - 1);
//     if (bytesRead == -1) {
//         perror("Error reading file");
//         close(fd);
//         exit(EXIT_FAILURE);
//     }

//     // Null-terminate the buffer to safely print it as a string
//     buffer[bytesRead] = '\0';

//     printf("Read %zd bytes:\n%s\n", bytesRead, buffer);

//     close(fd);
//     return 0;
// }
