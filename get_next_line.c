/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmongili <lmongili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 15:41:15 by lmongili          #+#    #+#             */
/*   Updated: 2025/12/20 17:53:18 by lmongili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}

int	ft_get_nl_index(char *buffer)
{
	int		i;

	i = 0;
	if (!buffer || ft_strlen(buffer) == 0)
		return (-1);
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_removeline(char *rook)
{
	char	*newline;

	newline = ft_strchr(rook, '\n');
	if (!newline)
		return (NULL);
	if (ft_strlen(newline) == 1)
		return (NULL);
	return (ft_strdup(&newline[1]));
}

char	*get_next_line(int fd)
{
	int			r;
	static char	*rook = NULL;
	char		*buffer;
	char		*line;

	line = NULL;
	if (ft_get_nl_index(rook) != -1)
	{
		line = ft_substr(rook, 0, ft_get_nl_index(rook));
		rook = ft_removeline(rook);
		if (!rook)
		{
			free(rook);
			rook = NULL;
		}
		return (line);
	}
	buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	r = read(fd, buffer, BUFFER_SIZE);
	if ((r == 0 && !rook) || r == -1)
		return (NULL);
	while (r != 0 && ft_get_nl_index(rook) == -1)
	{
		rook = ft_strjoin(rook, buffer);
		if (ft_get_nl_index(rook) == -1)
		{
			ft_bzero(buffer, BUFFER_SIZE);
			r = read(fd, buffer, BUFFER_SIZE);
		}
	}
	if (ft_get_nl_index(rook) != -1)
	{
		line = ft_substr(rook, 0, ft_get_nl_index(rook));
		rook = ft_removeline(rook);
		if (!rook)
		{
			free(rook);
			rook = NULL;
		}
	}
	else if (ft_get_nl_index(rook) == -1 && r == 0)
	{
		line = ft_strdup(rook);
		free(rook);
		rook = NULL;
	}
	if (!buffer)
		free(buffer);
	return (line);
}

int main(void)
{
	int fd = open("ILoveYou_Fontains_DC.txt", 'r');
	char *line;
	line = get_next_line(fd);
	while(line)
	{
		printf("%s\n", line);
		line = get_next_line(fd);
	}
	free(line);
	return (0);
}