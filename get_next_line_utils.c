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
	sub[i] = 0;
	return (sub);
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
	join[i] = 0;
	return (join);
}

static char	**ft_free(char **spltd)
{
	int	i;

	i = -1;
	while (spltd[++i] != NULL)
		free(spltd[i]);
	free(spltd);
	return (NULL);
}

static char	*find_word(char const *s, char c)
{
	char	*word;
	size_t	i;
	size_t	j;

	i = -1;
	if (!*s)
		return (NULL);
	if (*s == c)
		return (find_word(s + 1, c));
	while (++i < ft_strlen((const char *)s))
	{
		if (((char *)s)[i] == c)
			break ;
	}
	j = i;
	word = ft_calloc((i + 1), sizeof(char));
	i = -1;
	if (!word)
		return (NULL);
	while (++i < j)
		word[i] = ((char *)s)[i];
	return (word);
}

static	size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	w;
	char	*sub;

	i = -1;
	if (ft_strchr(s, c) == NULL && *s)
		return (1);
	else if (ft_strchr(s, c) == NULL && !*s)
		return (0);
	w = 0;
	while (s[++i] && i < ft_strlen((char *)s))
	{
		if (s[i] != c && i == 0)
			w++;
		else if (s[i] == c)
		{
			sub = ft_strchr((const char *)&s[i], c) + 1;
			if (*sub && *sub != c)
				w++;
		}
	}
	return (w);
}

char	**ft_split(char const *s, char c)
{
	char	**spltd;
	size_t	i;
	size_t	j;

	spltd = ft_calloc((count_words(s, c) + 1), sizeof(char *));
	if (!spltd)
		return (NULL);
	i = 0;
	j = 0;
	while (i < count_words(s, c))
	{
		while (s[j] == c)
			j++;
		spltd[i] = find_word(&s[j], c);
		if (!spltd[i])
			return (ft_free(spltd));
		j += ft_strlen(spltd[i]);
		i++;
	}
	return (spltd);
}
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (src < dest)
	{
		i = n - 1;
		while (i >= 0 && ((unsigned char *)dest)[i])
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}
char	*ft_strdup(const char *s)
{
	size_t	slen;
	char	*dupe;
	size_t	i;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	dupe = (char *)malloc((slen + 1) * sizeof(char));
	if (!dupe)
		return (malloc(0));
	i = 0;
	while (i < slen)
	{
		dupe[i] = s[i];
		i++;
	}
	dupe[i] = 0;
	return (dupe);
}