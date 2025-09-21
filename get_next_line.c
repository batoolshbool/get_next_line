/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshbool <bshbool@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 10:03:28 by bshbool           #+#    #+#             */
/*   Updated: 2025/09/21 18:15:51 by bshbool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int		fileread;
	char	buffer[BUFFER_SIZE];
	int 	i = 0;

	 char *hi = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	 fileread = read(fd, buffer, BUFFER_SIZE);
	 if (fd < 0 || BUFFER_SIZE <= 0 || !hi)
		return (NULL);
	 while (fileread > 0)
	 {
		hi[i] = fileread;
		if (fileread == '\0' || fileread == '\n')
			return(hi);
		i++;
	 }
	 if (i == 0)
	 	return (NULL);
	hi[i] = '\0';
	 return(hi);
}