/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmongili <lmongili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 15:41:15 by lmongili          #+#    #+#             */
/*   Updated: 2025/12/23 20:24:46 by lmongili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free(char **rook, char cases, char *buffer)
{
	char	*temp;

	if (cases == 'j')
	{
		temp = *rook;
		*rook = ft_strjoin(*rook, buffer);
		free(temp);
		return;
	}
	if (cases == 'y')
	{
		if (!(*rook))
		{
			free(*rook);
			*rook = NULL;
		}
		return;
	}
	if (cases == 'b' && !(*rook))
	{
		free(*rook);
		return;
	}
	free(*rook);
	*rook = NULL;
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

void	ft_removeline(char **rook)
{
	char	*newline;
	char *temp;
	
	temp = *rook;
	newline = ft_strchr(*rook, '\n');
	if (!newline || ft_strlen(newline) == 1)
	{
		*rook = NULL;
		free(temp);
		return;
	}
	*rook = ft_substr(newline, 1, ft_strlen(newline) - 1);
	free(temp);
}

static	char	*ft_helping_ft(int *r, char **rook, char **buffer, int *fd)
{
	char	*line;

	line = NULL;
	while (*r != 0 && ft_get_nl_index(*rook) == -1)
	{
		ft_free(&(*rook), 'j', *buffer);
		if (ft_get_nl_index(*rook) == -1)
		{
			free(*buffer);
			*buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
			*r = read(*fd, *buffer, BUFFER_SIZE);
		}
	}
	if (ft_get_nl_index(*rook) != -1)
	{
		line = ft_substr(*rook, 0, ft_get_nl_index(*rook) + 1);
		ft_removeline(&(*rook));
		ft_free(&(*rook), 'y', *buffer);
	}
	else if (ft_get_nl_index(*rook) == -1 && *r == 0)
	{
		line = ft_substr(*rook, 0, ft_strlen(*rook));
		ft_free(&(*rook), 'n', *buffer);
	}
	return (line);
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
		line = ft_substr(rook, 0, ft_get_nl_index(rook) + 1);
		ft_removeline(&rook);
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
		return (free(buffer), NULL);
	line = ft_helping_ft(&r, &rook, &buffer, &fd);
	return (free(buffer), line);
}

int main(void)
{
	char *line;

	int fd = open("ILoveYou_Fontains_DC.txt", 'r');
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
}