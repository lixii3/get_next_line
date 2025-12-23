/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmongili <lmongili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 15:40:30 by lmongili          #+#    #+#             */
/*   Updated: 2025/12/23 17:00:21 by lmongili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	if (s == NULL)
		return (0);
	while (*s != 0)
	{
		s++;
		size++;
	}
	return (size);
}

char	*ft_strchr(const char *s, int c)
{
	if (c == 0)
		return ((char *)(s + ft_strlen(s)));
	if (!s)
		return (NULL);
	while (*s != 0)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void		*p;
	size_t		i;

	
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > __SIZE_MAX__ / size)
		return (NULL);
	p = malloc(nmemb * size);
	if (!p)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		((char *)p)[i] = 0;
		i++;
	}
	return (p);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	size_t	sublen;
	char	*sub;
	size_t	i;

	slen = ft_strlen(s);
	if (!s || slen < start)
		return (ft_calloc(1, 1));
	if (slen - start > len)
		sublen = len;
	else
		sublen = slen - start;
	sub = (char *)malloc((sublen + 1) * sizeof(char));
	i = 0;
	while (i < len && s[start] != 0)
	{
		sub[i] = s[start];
		start++;
		i++;
	}
	return (sub[i] = 0, sub);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*join;
	size_t	i;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	if (!s1 && !s2)
		return (malloc(0));
	join = (char *) malloc((s1len + s2len + 1) * sizeof(char));
	if (!join)
		return (NULL);
	i = 0;
	while (i < s1len)
	{
		join[i] = s1[i];
		i++;
	}
	while (i < s2len + s1len)
	{
		join[i] = s2[i - s1len];
		i++;
	}
	return (join[i] = 0, join);
}
