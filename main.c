#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line_bonus.h"

int main()
{
    int a = open("a.txt", O_RDONLY);
    int b = open("b.txt", O_RDONLY);
    int c = open("c.txt", O_RDONLY);
    char *line_a, *line_b, *line_c;

    if (a < 0 || b < 0 || c < 0) {
        perror("Error opening file");
        return 1;
    }

    // Read the first line from all three files
    line_a = get_next_line(a);
    line_b = get_next_line(b);
    line_c = get_next_line(c);

    // Continue reading lines from each file until all files reach EOF
    while (line_a || line_b || line_c) {
        // Read and print from file a
        if (line_a) {
            printf("a -> %s", line_a);
            free(line_a);  // Free after printing
            line_a = get_next_line(a);  // Get next line from file a
        }

        // Read and print from file b
        if (line_b) {
            printf("b -> %s", line_b);
            free(line_b);  // Free after printing
            line_b = get_next_line(b);  // Get next line from file b
        }

        // Read and print from file c
        if (line_c) {
            printf("c -> %s", line_c);
            free(line_c);  // Free after printing
            line_c = get_next_line(c);  // Get next line from file c
        }
    }

    // Close the files after reading
    close(a);
    close(b);
    close(c);

    return 0;
}
