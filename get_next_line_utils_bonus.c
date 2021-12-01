/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 22:25:14 by ahmaidi           #+#    #+#             */
/*   Updated: 2021/12/01 18:07:10 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str_join;
	size_t			len;
	unsigned int	i;

	if (!s1 && s2)
		return (ft_strdup(s2));
	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	str_join = (char *)malloc(sizeof(char) * (len + 1));
	if (!str_join)
		return (NULL);
	while (s1[i])
	{
		str_join[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str_join[i + ft_strlen(s1)] = s2[i];
		i++;
	}
	str_join[i + ft_strlen(s1)] = '\0';
	free((char *)s1);
	return (str_join);
}

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if ((char)c)
	{
		if (!s)
			return (0);
		while (s[i] != '\0')
		{
			if (s[i] == (char)c)
				return (1);
			i++;
		}
	}
	return (0);
}

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*cpy;
	int		i;

	len = ft_strlen(s1);
	cpy = (char *) malloc(sizeof(char) * (len + 1));
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*substr;
	unsigned int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	else
	{
		while (i < len && s[i + start])
		{
			substr[i] = s[i + start];
			i++;
		}
		substr[i] = '\0';
	}
	return (substr);
}
