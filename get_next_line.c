/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 22:25:11 by ahmaidi           #+#    #+#             */
/*   Updated: 2021/12/01 15:34:55 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_line(char **stock)
{
	int		i;
	char	*line;
	char	*tmp;

	i = 0;
	while ((*stock)[i] != '\n')
		i++;
	line = ft_substr(*stock, 0, i + 1);
	tmp = *stock;
	*stock = ft_substr(*stock, i + 1, ft_strlen(*stock) - i);
	free(tmp);
	return (line);
}

char	*get_stock(char	**stock)
{
	char	*ligne;

	if (*stock && **stock != '\0')
	{
		ligne = *stock;
		*stock = NULL;
		return (ligne);
	}
	else
	{
		free(*stock);
		*stock = NULL;
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
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
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
