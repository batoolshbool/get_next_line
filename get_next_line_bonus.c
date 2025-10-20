/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshbool <bshbool@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 10:00:40 by bshbool           #+#    #+#             */
/*   Updated: 2025/10/20 14:12:17 by bshbool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

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
		{
			free(malloced);
			free(buffer); 
			return (NULL);
		}
		malloced[readd] = '\0';
		temp = buffer;
		buffer = ft_strjoin(temp, malloced);
		free(temp);
		if (!buffer)
		{
			free(malloced);
			return (NULL);
		}
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

// char	*get_next_line(int fd)
// {
// 	static char	*buffer[OPEN_MAX];
// 	char		*returned_line = NULL;

// 	if (fd < 0 || BUFFER_SIZE <= 0
// 	|| read(fd, 0, 0) < 0 || fd >= OPEN_MAX)
// 	{
// 		free(buffer[fd]);
// 		buffer[fd] = NULL;
// 		return (NULL);
// 	}
// 	buffer[fd] = read_and_save(fd, buffer[fd]);
// 	if(!buffer[fd])
// 		return (NULL);
// 	returned_line = extract_line(buffer[fd]);
// 	buffer[fd] = clear_buffer(buffer[fd]);
// 	printf("\n\nmeow\n\n");
// 	return (returned_line);
// }

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*returned_line = NULL;

	// Debugging prints to check conditions
	printf("Entering get_next_line for fd: %d\n", fd);

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 || fd >= OPEN_MAX) {
		printf("Invalid fd or buffer size\n");
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}

	// Debugging print to check if read_and_save is working correctly
	printf("Before read_and_save for fd: %d\n", fd);
	printf("Buffer[fd] before read: %s\n", buffer[fd] ? buffer[fd] : "NULL");
	buffer[fd] = read_and_save(fd, buffer[fd]);
	printf("Buffer[fd] after read: %s\n", buffer[fd] ? buffer[fd] : "NULL");

	if (!buffer[fd]) {
		printf("Error reading from fd %d\n", fd);
		return (NULL);
	}

	// Debugging to check if extract_line works correctly
	returned_line = extract_line(buffer[fd]);
	if (!returned_line) {
		printf("Error: extract_line failed\n");
		return (NULL);
	}

	// Final printf to check if we get here
	printf("\n\nmeow\n\n");
	fflush(stdout);

	// Debugging buffer after clearing
	printf("Buffer[fd] after clear: %s\n", buffer[fd] ? buffer[fd] : "NULL");
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
// 	printf("2 -> %s", get_next_line(fd));
// 	printf("3 -> %s", get_next_line(fd));
// 	printf("4 -> %s", get_next_line(fd3));
// 	printf("5 -> %s", get_next_line(fd3));
// 	printf("6 -> %s", get_next_line(fd2));
// 	printf("7 -> %s", get_next_line(fd2));
// 	printf("8 -> %s", get_next_line(fd3));
// 	printf("9 -> %s", get_next_line(fd3));
// 	printf("10 -> %s", get_next_line(fd));
// }