/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 22:25:11 by ahmaidi           #+#    #+#             */
/*   Updated: 2021/11/29 16:36:19 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_line(char *s)
{
	int		i;
	char	*line;

	i = 0;
	if (ft_strchr(s, '\n'))
	{
		while (s[i] != '\n')
			i++;
		line = ft_substr(s, 0, i + 1);
		return (line);
	}
	line = ft_strdup(s);
	free(s);
	s = NULL;
	return (line);
}

char	*get_stock(char	*s)
{
	int		i;
	char	*temp;

	if (!s)
		return (NULL);
	i = 0;
	if (!ft_strchr(s, '\n'))
		return (NULL);
	while (s[i] != '\n')
		i++;
	if (s[i + 1] == '\0')
	{
		free(s);
		return (NULL);
	}
	temp = s;
	s = ft_substr(s, i + 1, ft_strlen(s)- i);
	free(temp);
	return (s);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*stock;
	int			read_f;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_f = 1;
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	while (read_f > 0 && !ft_strchr(stock, '\n'))
	{
		read_f = read(fd, buffer, BUFFER_SIZE);
		if (read_f == -1)
		{
			free(stock);
			stock = NULL;
		}
		if (read_f > 0)
			stock = ft_strjoin(stock, buffer);
	}
	free(buffer);
	if (!stock)
		return (NULL);
	line = get_line(stock);
	stock = get_stock(stock);
	return (line);
}
int main()
{
	int	fd;

	fd = open("file1", O_RDONLY);
	printf("line  %s",get_next_line(fd));
	// printf("line2  %s",get_next_line(fd));
	
	//while(1);
}