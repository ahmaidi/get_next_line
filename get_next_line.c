/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 22:25:11 by ahmaidi           #+#    #+#             */
/*   Updated: 2021/11/27 01:27:44 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*check_stock(char **line, char **stock)
{
	char	*p_of_n;
	char	*temp;

	temp = NULL;
	if (!*stock)
		return (NULL);
	p_of_n = ft_strchr(*stock, '\n');
	if (p_of_n)
	{
		*line = ft_strdup("");
		temp = ft_strdup(++p_of_n);
		*p_of_n = '\0';
		*line = ft_strjoin(*line, *stock);
		free (*stock);
		*stock = ft_strdup(temp);
		free(temp);
	}
	else if (*stock)
	{
		*line = ft_strdup(*stock);
		free(*stock);
		*stock = NULL;
	}
	return (p_of_n);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*stock;
	char		*line;
	char		*p_of_n;

	if (fd < 0 || BUFFER_SIZE == 0)
		return (NULL);
	p_of_n = NULL;
	line = NULL;
	p_of_n = check_stock(&line, &stock);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	while (!p_of_n && read(fd, buffer, BUFFER_SIZE))
	{
		if (!line)
			line = ft_strdup("");
		p_of_n = ft_strchr(buffer, '\n');
		if (p_of_n)
		{
			stock = ft_strdup(++p_of_n);
			*p_of_n = '\0';
		}
		line = ft_strjoin(line, buffer);
	}
	free(buffer);
	return (line);
}
int main()
{
	char *line;
	int fd;
	fd = open("file1",O_RDONLY);
	while((line = get_next_line(fd)))
	{
		printf("%s",line);
	}
}