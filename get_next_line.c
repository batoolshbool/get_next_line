/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshbool <bshbool@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 10:03:28 by bshbool           #+#    #+#             */
/*   Updated: 2025/10/01 13:37:14 by bshbool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_and_save(int fd, char *buffer)
{
	char	*malloced;
	ssize_t	readd;
	char	*temp;

	malloced = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!malloced)
		return (NULL);
	readd = 1;
	while ((!buffer || !ft_strchr(buffer, '\n')) && readd > 0)
	{
		readd = read(fd, malloced, BUFFER_SIZE);
		if (readd == -1)
		{
			free(malloced);
			return (NULL);
		}
		malloced[readd] = '\0';
		temp = buffer;
		buffer = ft_strjoin(temp, malloced);
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
	return (returned_line);
}
/*c1r4s14% valgrind ./a.out
==721657== Memcheck, a memory error detector
==721657== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==721657== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==721657== Command: ./a.out
==721657== 
line 3
==721657== 
==721657== HEAP SUMMARY:
==721657==     in use at exit: 23 bytes in 3 blocks
==721657==   total heap usage: 13 allocs, 10 frees, 1,138 bytes allocated
==721657== 
==721657== LEAK SUMMARY:
==721657==    definitely lost: 16 bytes in 2 blocks
==721657==    indirectly lost: 0 bytes in 0 blocks
==721657==      possibly lost: 0 bytes in 0 blocks
==721657==    still reachable: 7 bytes in 1 blocks
==721657==         suppressed: 0 bytes in 0 blocks
==721657== Rerun with --leak-check=full to see details of leaked memory
==721657== 
==721657== For lists of detected and suppressed errors, rerun with: -s
==721657== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
*/