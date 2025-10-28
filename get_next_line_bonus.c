/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshbool <bshbool@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 10:00:40 by bshbool           #+#    #+#             */
/*   Updated: 2025/10/28 10:56:27 by bshbool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*freeing(char *malloced, char *buffer)
{
	free(malloced);
	if (buffer)
		free(buffer);
	return (NULL);
}

static char	*read_and_save(int fd, char *buffer)
{
	char	*malloced;
	ssize_t	readd;
	char	*temp;

	malloced = malloc(BUFFER_SIZE + 1);
	if (!malloced)
		return (NULL);
	readd = 1;
	while ((!buffer || !ft_strchr(buffer, '\n')) && readd > 0)
	{
		readd = read(fd, malloced, BUFFER_SIZE);
		if (readd < 0)
			return (freeing(malloced, buffer));
		malloced[readd] = '\0';
		temp = buffer;
		buffer = ft_strjoin(temp, malloced);
		free(temp);
		if (!buffer)
			return (freeing(malloced, buffer));
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
	static char	*buffer[OPEN_MAX];
	char		*returned_line ;

	returned_line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0
		|| read(fd, 0, 0) < 0 || fd >= OPEN_MAX)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	buffer[fd] = read_and_save(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	returned_line = extract_line(buffer[fd]);
	buffer[fd] = clear_buffer(buffer[fd]);
	return (returned_line);
}

// #include <fcntl.h>
// #include <stdio.h>
// #include "get_next_line.h"
// int main()
// {
// 	int fd = (open("a.txt", O_RDONLY));
// 	int fd2 = (open("b.txt", O_RDONLY));
// 	int fd3 = (open("c.txt", O_RDONLY));

// 	char *a = NULL;

// 	while(a == get_next_line(fd))
// 		printf("1 -> %s", a);
// 	printf("2a -> %s", get_next_line(fd));
// 	printf("3a -> %s", get_next_line(fd));
// 	printf("1c -> %s", get_next_line(fd3));
// 	printf("2c -> %s", get_next_line(fd3));
// 	printf("1b -> %s", get_next_line(fd2));
// 	printf("2b -> %s", get_next_line(fd2));
// 	printf("3c -> %s", get_next_line(fd3));
// 	printf("4c -> %s", get_next_line(fd3));
// 	printf("4a -> %s", get_next_line(fd));
// }