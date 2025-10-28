#include <fcntl.h>
#include <stdio.h>
#include "get_next_line_bonus.h"
int main()
{
	int fd = (open("a.txt", O_RDONLY));
	int fd2 = (open("b.txt", O_RDONLY));
	int fd3 = (open("c.txt", O_RDONLY));

	char *a = NULL;

	while(a == get_next_line(fd))
		printf("1 -> %s", a);
	printf("2a -> %s", get_next_line(fd));
	free(get_next_line(fd));
	printf("3a -> %s", get_next_line(fd));
	free(get_next_line(fd));
	printf("1c -> %s", get_next_line(fd3));
	free(get_next_line(fd3));
	printf("2c -> %s", get_next_line(fd3));
	free(get_next_line(fd3));
	printf("1b -> %s", get_next_line(fd2));
	free(get_next_line(fd2));
	printf("2b -> %s", get_next_line(fd2));
	free(get_next_line(fd2));
	printf("3c -> %s", get_next_line(fd3));
	free(get_next_line(fd3));
	printf("4c -> %s", get_next_line(fd3));
	free(get_next_line(fd3));
	printf("4a -> %s", get_next_line(fd));
	free(get_next_line(fd));

	close(fd);
	close(fd2);
	close(fd3);
}

/*c2r3s7% valgrind --leak-check=full ./a.out
==134509== Memcheck, a memory error detector
==134509== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==134509== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==134509== Command: ./a.out
==134509== 
2a -> 2a
3a -> 4a
1c -> 1c
2c -> 3c
1b -> 1b
2b -> 3b
3c -> 5c
4c -> 7c
4a -> 6a==134509== 
==134509== HEAP SUMMARY:
==134509==     in use at exit: 48 bytes in 11 blocks
==134509==   total heap usage: 64 allocs, 53 frees, 1,466 bytes allocated
==134509== 
==134509== 3 bytes in 1 blocks are definitely lost in loss record 1 of 11
==134509==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==134509==    by 0x401A82: ft_substr (in /sgoinfre/bshbool/get_next_line/a.out)
==134509==    by 0x4016A1: extract_line (in /sgoinfre/bshbool/get_next_line/a.out)
==134509==    by 0x401484: get_next_line (in /sgoinfre/bshbool/get_next_line/a.out)
==134509==    by 0x40137A: main (in /sgoinfre/bshbool/get_next_line/a.out)
==134509== 
==134509== 4 bytes in 1 blocks are definitely lost in loss record 2 of 11
==134509==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==134509==    by 0x401A82: ft_substr (in /sgoinfre/bshbool/get_next_line/a.out)
==134509==    by 0x4016A1: extract_line (in /sgoinfre/bshbool/get_next_line/a.out)
==134509==    by 0x401484: get_next_line (in /sgoinfre/bshbool/get_next_line/a.out)
==134509==    by 0x4011E8: main (in /sgoinfre/bshbool/get_next_line/a.out)
==134509== 
==134509== 4 bytes in 1 blocks are definitely lost in loss record 3 of 11
==134509==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==134509==    by 0x401A82: ft_substr (in /sgoinfre/bshbool/get_next_line/a.out)
==134509==    by 0x4016A1: extract_line (in /sgoinfre/bshbool/get_next_line/a.out)
==134509==    by 0x401484: get_next_line (in /sgoinfre/bshbool/get_next_line/a.out)
==134509==    by 0x40121A: main (in /sgoinfre/bshbool/get_next_line/a.out)
==134509== 
==134509== 4 bytes in 1 blocks are definitely lost in loss record 4 of 11
==134509==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==134509==    by 0x401A82: ft_substr (in /sgoinfre/bshbool/get_next_line/a.out)
==134509==    by 0x4016A1: extract_line (in /sgoinfre/bshbool/get_next_line/a.out)
==134509==    by 0x401484: get_next_line (in /sgoinfre/bshbool/get_next_line/a.out)
==134509==    by 0x401246: main (in /sgoinfre/bshbool/get_next_line/a.out)
==134509== 
==134509== 4 bytes in 1 blocks are definitely lost in loss record 5 of 11
==134509==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==134509==    by 0x401A82: ft_substr (in /sgoinfre/bshbool/get_next_line/a.out)
==134509==    by 0x4016A1: extract_line (in /sgoinfre/bshbool/get_next_line/a.out)
==134509==    by 0x401484: get_next_line (in /sgoinfre/bshbool/get_next_line/a.out)
==134509==    by 0x401272: main (in /sgoinfre/bshbool/get_next_line/a.out)
==134509== 
==134509== 4 bytes in 1 blocks are definitely lost in loss record 6 of 11
==134509==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==134509==    by 0x401A82: ft_substr (in /sgoinfre/bshbool/get_next_line/a.out)
==134509==    by 0x4016A1: extract_line (in /sgoinfre/bshbool/get_next_line/a.out)
==134509==    by 0x401484: get_next_line (in /sgoinfre/bshbool/get_next_line/a.out)
==134509==    by 0x40129E: main (in /sgoinfre/bshbool/get_next_line/a.out)
==134509== 
==134509== 4 bytes in 1 blocks are definitely lost in loss record 7 of 11
==134509==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==134509==    by 0x401A82: ft_substr (in /sgoinfre/bshbool/get_next_line/a.out)
==134509==    by 0x4016A1: extract_line (in /sgoinfre/bshbool/get_next_line/a.out)
==134509==    by 0x401484: get_next_line (in /sgoinfre/bshbool/get_next_line/a.out)
==134509==    by 0x4012CA: main (in /sgoinfre/bshbool/get_next_line/a.out)
==134509== 
==134509== 4 bytes in 1 blocks are definitely lost in loss record 8 of 11
==134509==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==134509==    by 0x401A82: ft_substr (in /sgoinfre/bshbool/get_next_line/a.out)
==134509==    by 0x4016A1: extract_line (in /sgoinfre/bshbool/get_next_line/a.out)
==134509==    by 0x401484: get_next_line (in /sgoinfre/bshbool/get_next_line/a.out)
==134509==    by 0x4012F6: main (in /sgoinfre/bshbool/get_next_line/a.out)
==134509== 
==134509== 4 bytes in 1 blocks are definitely lost in loss record 9 of 11
==134509==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==134509==    by 0x401A82: ft_substr (in /sgoinfre/bshbool/get_next_line/a.out)
==134509==    by 0x4016A1: extract_line (in /sgoinfre/bshbool/get_next_line/a.out)
==134509==    by 0x401484: get_next_line (in /sgoinfre/bshbool/get_next_line/a.out)
==134509==    by 0x401322: main (in /sgoinfre/bshbool/get_next_line/a.out)
==134509== 
==134509== 4 bytes in 1 blocks are definitely lost in loss record 10 of 11
==134509==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==134509==    by 0x401A82: ft_substr (in /sgoinfre/bshbool/get_next_line/a.out)
==134509==    by 0x4016A1: extract_line (in /sgoinfre/bshbool/get_next_line/a.out)
==134509==    by 0x401484: get_next_line (in /sgoinfre/bshbool/get_next_line/a.out)
==134509==    by 0x40134E: main (in /sgoinfre/bshbool/get_next_line/a.out)
==134509== 
==134509== LEAK SUMMARY:
==134509==    definitely lost: 39 bytes in 10 blocks
==134509==    indirectly lost: 0 bytes in 0 blocks
==134509==      possibly lost: 0 bytes in 0 blocks
==134509==    still reachable: 9 bytes in 1 blocks
==134509==         suppressed: 0 bytes in 0 blocks
==134509== Reachable blocks (those to which a pointer was found) are not shown.
==134509== To see them, rerun with: --leak-check=full --show-leak-kinds=all
==134509== 
==134509== For lists of detected and suppressed errors, rerun with: -s
==134509== ERROR SUMMARY: 10 errors from 10 contexts (suppressed: 0 from 0)
*/