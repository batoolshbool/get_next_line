/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshbool <bshbool@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 10:03:28 by bshbool           #+#    #+#             */
/*   Updated: 2025/09/19 13:17:42 by bshbool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	ssize_t	fileread;
	size_t	BUFFER_SIZE;
	char	buffer[BUFFER_SIZE];

	fileread = read(fd, buffer, BUFFER_SIZE);
	if (fileread < 0)
		return (NULL);
}
