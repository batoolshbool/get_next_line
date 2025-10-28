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

/*c2r3s7% valgrind --leak-check=full ./a.out
==132360== Memcheck, a memory error detector
==132360== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==132360== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==132360== Command: ./a.out
==132360== 
2a -> 2a
3a -> 3a
1c -> 1c
2c -> 2c
1b -> 1b
2b -> 2b
3c -> 3c
4c -> 4c
4a -> 4a
==132360== 
==132360== HEAP SUMMARY:
==132360==     in use at exit: 60 bytes in 13 blocks
==132360==   total heap usage: 36 allocs, 23 frees, 1,286 bytes allocated
==132360== 
==132360== 4 bytes in 1 blocks are definitely lost in loss record 1 of 13
==132360==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==132360==    by 0x4019D2: ft_substr (in /sgoinfre/bshbool/get_next_line/a.out)
==132360==    by 0x4015F1: extract_line (in /sgoinfre/bshbool/get_next_line/a.out)
==132360==    by 0x4013D4: get_next_line (in /sgoinfre/bshbool/get_next_line/a.out)
==132360==    by 0x4011D8: main (in /sgoinfre/bshbool/get_next_line/a.out)
==132360== 
==132360== 4 bytes in 1 blocks are definitely lost in loss record 2 of 13
==132360==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==132360==    by 0x4019D2: ft_substr (in /sgoinfre/bshbool/get_next_line/a.out)
==132360==    by 0x4015F1: extract_line (in /sgoinfre/bshbool/get_next_line/a.out)
==132360==    by 0x4013D4: get_next_line (in /sgoinfre/bshbool/get_next_line/a.out)
==132360==    by 0x40120A: main (in /sgoinfre/bshbool/get_next_line/a.out)
==132360== 
==132360== 4 bytes in 1 blocks are definitely lost in loss record 3 of 13
==132360==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==132360==    by 0x4019D2: ft_substr (in /sgoinfre/bshbool/get_next_line/a.out)
==132360==    by 0x4015F1: extract_line (in /sgoinfre/bshbool/get_next_line/a.out)
==132360==    by 0x4013D4: get_next_line (in /sgoinfre/bshbool/get_next_line/a.out)
==132360==    by 0x401226: main (in /sgoinfre/bshbool/get_next_line/a.out)
==132360== 
==132360== 4 bytes in 1 blocks are definitely lost in loss record 4 of 13
==132360==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==132360==    by 0x4019D2: ft_substr (in /sgoinfre/bshbool/get_next_line/a.out)
==132360==    by 0x4015F1: extract_line (in /sgoinfre/bshbool/get_next_line/a.out)
==132360==    by 0x4013D4: get_next_line (in /sgoinfre/bshbool/get_next_line/a.out)
==132360==    by 0x401242: main (in /sgoinfre/bshbool/get_next_line/a.out)
==132360== 
==132360== 4 bytes in 1 blocks are definitely lost in loss record 5 of 13
==132360==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==132360==    by 0x4019D2: ft_substr (in /sgoinfre/bshbool/get_next_line/a.out)
==132360==    by 0x4015F1: extract_line (in /sgoinfre/bshbool/get_next_line/a.out)
==132360==    by 0x4013D4: get_next_line (in /sgoinfre/bshbool/get_next_line/a.out)
==132360==    by 0x40125E: main (in /sgoinfre/bshbool/get_next_line/a.out)
==132360== 
==132360== 4 bytes in 1 blocks are definitely lost in loss record 6 of 13
==132360==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==132360==    by 0x4019D2: ft_substr (in /sgoinfre/bshbool/get_next_line/a.out)
==132360==    by 0x4015F1: extract_line (in /sgoinfre/bshbool/get_next_line/a.out)
==132360==    by 0x4013D4: get_next_line (in /sgoinfre/bshbool/get_next_line/a.out)
==132360==    by 0x40127A: main (in /sgoinfre/bshbool/get_next_line/a.out)
==132360== 
==132360== 4 bytes in 1 blocks are definitely lost in loss record 7 of 13
==132360==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==132360==    by 0x4019D2: ft_substr (in /sgoinfre/bshbool/get_next_line/a.out)
==132360==    by 0x4015F1: extract_line (in /sgoinfre/bshbool/get_next_line/a.out)
==132360==    by 0x4013D4: get_next_line (in /sgoinfre/bshbool/get_next_line/a.out)
==132360==    by 0x401296: main (in /sgoinfre/bshbool/get_next_line/a.out)
==132360== 
==132360== 4 bytes in 1 blocks are definitely lost in loss record 8 of 13
==132360==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==132360==    by 0x4019D2: ft_substr (in /sgoinfre/bshbool/get_next_line/a.out)
==132360==    by 0x4015F1: extract_line (in /sgoinfre/bshbool/get_next_line/a.out)
==132360==    by 0x4013D4: get_next_line (in /sgoinfre/bshbool/get_next_line/a.out)
==132360==    by 0x4012B2: main (in /sgoinfre/bshbool/get_next_line/a.out)
==132360== 
==132360== 4 bytes in 1 blocks are definitely lost in loss record 9 of 13
==132360==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==132360==    by 0x4019D2: ft_substr (in /sgoinfre/bshbool/get_next_line/a.out)
==132360==    by 0x4015F1: extract_line (in /sgoinfre/bshbool/get_next_line/a.out)
==132360==    by 0x4013D4: get_next_line (in /sgoinfre/bshbool/get_next_line/a.out)
==132360==    by 0x4012CE: main (in /sgoinfre/bshbool/get_next_line/a.out)
==132360== 
==132360== 4 bytes in 1 blocks are definitely lost in loss record 10 of 13
==132360==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==132360==    by 0x4019D2: ft_substr (in /sgoinfre/bshbool/get_next_line/a.out)
==132360==    by 0x4015F1: extract_line (in /sgoinfre/bshbool/get_next_line/a.out)
==132360==    by 0x4013D4: get_next_line (in /sgoinfre/bshbool/get_next_line/a.out)
==132360==    by 0x4012EA: main (in /sgoinfre/bshbool/get_next_line/a.out)
==132360== 
==132360== LEAK SUMMARY:
==132360==    definitely lost: 40 bytes in 10 blocks
==132360==    indirectly lost: 0 bytes in 0 blocks
==132360==      possibly lost: 0 bytes in 0 blocks
==132360==    still reachable: 20 bytes in 3 blocks
==132360==         suppressed: 0 bytes in 0 blocks
==132360== Reachable blocks (those to which a pointer was found) are not shown.
==132360== To see them, rerun with: --leak-check=full --show-leak-kinds=all
==132360== 
==132360== For lists of detected and suppressed errors, rerun with: -s
==132360== ERROR SUMMARY: 10 errors from 10 contexts (suppressed: 0 from 0)
*/