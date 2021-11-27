/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 22:25:14 by ahmaidi           #+#    #+#             */
/*   Updated: 2021/11/27 00:47:26 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	i;

	i = 0;
	p = (void *)malloc(count * size);
	if (!p)
		return (NULL);
	while (i < (count * size))
	{
		((char *)p)[i] = 0;
		i++;
	}
	return (p);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str_join;
	size_t			s1_len;
	size_t			s2_len;
	unsigned int	i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str_join = (char *)ft_calloc(sizeof(char), (s1_len + s2_len + 1));
	if (!str_join)
		return (NULL);
	while (i < s1_len)
	{
		str_join[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < s2_len)
	{
		str_join[i + s1_len] = s2[i];
		i++;
	}
	free((char *)s1);
	return (str_join);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if ((char)c)
	{
		while (s[i] != '\0')
		{
			if (s[i] == (char)c)
				return ((char *)s + i);
			i++;
		}
		return (NULL);
	}
	else
		return ((char *)s + ft_strlen(s));
}

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*cpy;
	int		i;

	len = ft_strlen(s1);
	cpy = (char *) malloc (sizeof(char) * (len + 1));
	i = 0;
	if (!cpy)
		return (NULL);
	while (i < len)
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
