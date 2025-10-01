/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshbool <bshbool@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 10:03:28 by bshbool           #+#    #+#             */
/*   Updated: 2025/10/01 12:02:51 by bshbool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_and_save(int fd, char *buffer)
{
	char	*malloced;
	ssize_t	readd;
	char	*temp;

	readd = 1;
	malloced = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!malloced)
		return (NULL);
	while ((!buffer || !ft_strchr(buffer, '\n')) && readd > 0)
	{
		readd = read(fd, malloced, BUFFER_SIZE);
		if (readd == -1)
		{
			free(malloced);
			free(buffer);
			return (NULL);
		}
		malloced[readd] = '\0';
		temp = buffer;
		buffer = ft_strjoin(temp, malloced);
		if (!buffer)
		free(temp);
	}
	free(malloced);
	return (buffer);
}

static char	*extract_line(char *buffer)
{
	char	*line;
	int		i;

	if (!buffer || !buffer[0])
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = ft_substr(buffer, 0, i);
	return (line);
}

static char	*clear_buffer(char *buffer)
{
	int		i;
	char	*new;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	i++;
	new = ft_substr(buffer, i, ft_strlen(buffer) - i);
	free(buffer);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*returned_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = read_and_save(fd, buffer);
	if (!buffer)
		return (NULL);
	returned_line = extract_line(buffer);
	if (!returned_line)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = clear_buffer(buffer);
	free(buffer);
	//buffer = NULL;
	return (returned_line);
}

/*c1r4s14% valgrind ./a.out
==720561== Memcheck, a memory error detector
==720561== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==720561== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==720561== Command: ./a.out
==720561== 
==720561== Invalid read of size 1
==720561==    at 0x4018CA: ft_strchr (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==    by 0x4012DA: read_and_save (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==    by 0x4011E3: get_next_line (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==    by 0x401981: main (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==  Address 0x4a9d130 is 0 bytes inside a block of size 4 free'd
==720561==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==720561==    by 0x40126B: get_next_line (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==    by 0x401975: main (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==  Block was alloc'd at
==720561==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==720561==    by 0x401802: ft_substr (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==    by 0x40153D: clear_buffer (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==    by 0x401256: get_next_line (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==    by 0x401975: main (in /sgoinfre/bshbool/get_next_line/a.out)
==720561== 
==720561== Invalid read of size 1
==720561==    at 0x4018DC: ft_strchr (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==    by 0x4012DA: read_and_save (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==    by 0x4011E3: get_next_line (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==    by 0x401981: main (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==  Address 0x4a9d130 is 0 bytes inside a block of size 4 free'd
==720561==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==720561==    by 0x40126B: get_next_line (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==    by 0x401975: main (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==  Block was alloc'd at
==720561==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==720561==    by 0x401802: ft_substr (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==    by 0x40153D: clear_buffer (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==    by 0x401256: get_next_line (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==    by 0x401975: main (in /sgoinfre/bshbool/get_next_line/a.out)
==720561== 
==720561== Invalid read of size 1
==720561==    at 0x401595: ft_strlen (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==    by 0x401688: ft_strjoin (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==    by 0x401367: read_and_save (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==    by 0x4011E3: get_next_line (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==    by 0x401981: main (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==  Address 0x4a9d130 is 0 bytes inside a block of size 4 free'd
==720561==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==720561==    by 0x40126B: get_next_line (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==    by 0x401975: main (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==  Block was alloc'd at
==720561==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==720561==    by 0x401802: ft_substr (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==    by 0x40153D: clear_buffer (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==    by 0x401256: get_next_line (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==    by 0x401975: main (in /sgoinfre/bshbool/get_next_line/a.out)
==720561== 
==720561== Invalid read of size 1
==720561==    at 0x4016E2: ft_strjoin (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==    by 0x401367: read_and_save (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==    by 0x4011E3: get_next_line (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==    by 0x401981: main (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==  Address 0x4a9d130 is 0 bytes inside a block of size 4 free'd
==720561==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==720561==    by 0x40126B: get_next_line (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==    by 0x401975: main (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==  Block was alloc'd at
==720561==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==720561==    by 0x401802: ft_substr (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==    by 0x40153D: clear_buffer (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==    by 0x401256: get_next_line (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==    by 0x401975: main (in /sgoinfre/bshbool/get_next_line/a.out)
==720561== 
==720561== Invalid free() / delete / delete[] / realloc()
==720561==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==720561==    by 0x401387: read_and_save (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==    by 0x4011E3: get_next_line (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==    by 0x401981: main (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==  Address 0x4a9d130 is 0 bytes inside a block of size 4 free'd
==720561==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==720561==    by 0x40126B: get_next_line (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==    by 0x401975: main (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==  Block was alloc'd at
==720561==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==720561==    by 0x401802: ft_substr (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==    by 0x40153D: clear_buffer (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==    by 0x401256: get_next_line (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==    by 0x401975: main (in /sgoinfre/bshbool/get_next_line/a.out)
==720561== 
==720561== Invalid read of size 1
==720561==    at 0x4018CA: ft_strchr (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==    by 0x4012DA: read_and_save (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==    by 0x4011E3: get_next_line (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==    by 0x40198D: main (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==  Address 0x4a9d270 is 0 bytes inside a block of size 7 free'd
==720561==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==720561==    by 0x40126B: get_next_line (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==    by 0x401981: main (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==  Block was alloc'd at
==720561==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==720561==    by 0x401802: ft_substr (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==    by 0x40153D: clear_buffer (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==    by 0x401256: get_next_line (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==    by 0x401981: main (in /sgoinfre/bshbool/get_next_line/a.out)
==720561== 
==720561== Invalid read of size 1
==720561==    at 0x4018DC: ft_strchr (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==    by 0x4012DA: read_and_save (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==    by 0x4011E3: get_next_line (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==    by 0x40198D: main (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==  Address 0x4a9d270 is 0 bytes inside a block of size 7 free'd
==720561==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==720561==    by 0x40126B: get_next_line (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==    by 0x401981: main (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==  Block was alloc'd at
==720561==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==720561==    by 0x401802: ft_substr (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==    by 0x40153D: clear_buffer (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==    by 0x401256: get_next_line (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==    by 0x401981: main (in /sgoinfre/bshbool/get_next_line/a.out)
==720561== 
==720561== Invalid read of size 1
==720561==    at 0x4016E2: ft_strjoin (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==    by 0x401367: read_and_save (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==    by 0x4011E3: get_next_line (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==    by 0x40198D: main (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==  Address 0x4a9d270 is 0 bytes inside a block of size 7 free'd
==720561==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==720561==    by 0x40126B: get_next_line (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==    by 0x401981: main (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==  Block was alloc'd at
==720561==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==720561==    by 0x401802: ft_substr (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==    by 0x40153D: clear_buffer (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==    by 0x401256: get_next_line (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==    by 0x401981: main (in /sgoinfre/bshbool/get_next_line/a.out)
==720561== 
==720561== Invalid free() / delete / delete[] / realloc()
==720561==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==720561==    by 0x401387: read_and_save (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==    by 0x4011E3: get_next_line (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==    by 0x40198D: main (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==  Address 0x4a9d270 is 0 bytes inside a block of size 7 free'd
==720561==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==720561==    by 0x40126B: get_next_line (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==    by 0x401981: main (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==  Block was alloc'd at
==720561==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==720561==    by 0x401802: ft_substr (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==    by 0x40153D: clear_buffer (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==    by 0x401256: get_next_line (in /sgoinfre/bshbool/get_next_line/a.out)
==720561==    by 0x401981: main (in /sgoinfre/bshbool/get_next_line/a.out)
==720561== 
line 3
==720561== 
==720561== HEAP SUMMARY:
==720561==     in use at exit: 16 bytes in 2 blocks
==720561==   total heap usage: 13 allocs, 13 frees, 1,138 bytes allocated
==720561== 
==720561== LEAK SUMMARY:
==720561==    definitely lost: 16 bytes in 2 blocks
==720561==    indirectly lost: 0 bytes in 0 blocks
==720561==      possibly lost: 0 bytes in 0 blocks
==720561==    still reachable: 0 bytes in 0 blocks
==720561==         suppressed: 0 bytes in 0 blocks
==720561== Rerun with --leak-check=full to see details of leaked memory
==720561== 
==720561== For lists of detected and suppressed errors, rerun with: -s
==720561== ERROR SUMMARY: 42 errors from 9 contexts (suppressed: 0 from 0)
*/