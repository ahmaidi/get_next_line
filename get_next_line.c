/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 22:25:11 by ahmaidi           #+#    #+#             */
/*   Updated: 2021/11/29 22:54:50 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_line(char **s)
{
	int		i;
	char	*line;
	char	*tmp;

	i = 0;
	while ((*s)[i] != '\n')
		i++;
	line = ft_substr(*s, 0, i + 1);
	tmp = *s;
	*s = ft_substr(*s, i + 1, ft_strlen(*s) - i);
	free(tmp);
	return (line);
}

char	*get_stock(char	**s)
{
	char	*ligne;

	if (*s && **s != '\0')
	{
		ligne = *s;
		*s = NULL;
		return (ligne);
	}
	else
	{
		free(*s);
		*s = NULL;
		return (NULL);
	}
}

static char	*free_it(char *buffer, char *stock)
{
	free(buffer);
	free(stock);
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*stock;
	int			read_f;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(stock, '\n'))
	{
		read_f = read(fd, buffer, BUFFER_SIZE);
		if (read_f < 0)
			return (free_it(buffer, stock));
		if (read_f == 0)
			break ;
		buffer[read_f] = 0;
		stock = ft_strjoin(stock, buffer);
	}
	free(buffer);
	if (ft_strchr(stock, '\n'))
		return (get_line(&stock));
	return (get_stock(&stock));
}

// int main()
// {
// 	int	fd;
// 	char *line;
	
// 	fd = open("file1", O_RDONLY);
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		printf("line  %s",line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
	

// }