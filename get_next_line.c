#include "get_next_line.h"

int	ft_containsnl(char *buffer)
{
	int		i;

	i = 0;
	if (!buffer)
		return (-1);
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1); //non trova \n
}
char	*ft_removeline(char *rook)
{
	rook = ft_strchr(rook, '\n' + 0);
	if (ft_strlen(rook) == 1)//se contiene solo \n
		return (NULL);
	return (&rook[1]);
}

char *get_next_line(int fd)
{
	int			r;
	static char	*rook = NULL;
	char		*buffer;
	char		*line;

	line = NULL;
	while (!rook || ft_containsnl(rook) == -1)//continua finche rook non contiene un \n
	{
		buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
		r = read(fd, buffer, BUFFER_SIZE);
		if (ft_containsnl(buffer) != -1)
		{
			//salvo la riga fino al primo \n
			line = ft_substr(buffer, 0, ft_containsnl(buffer) + 1);
			//appendo a rook i caratteri rimanenti dopo \n
			if (!rook)
				rook = ft_substr(buffer, ft_containsnl(buffer) + 1, ft_strlen(buffer) - ft_containsnl(buffer));
			else
				rook = ft_strjoin(rook, &buffer[ft_containsnl(buffer) + 1]);
			free(buffer);
			if (!rook)
			{
				if (line)
					free(line);
				return (NULL);
			}
		}
		else
			rook = ft_strjoin(rook, buffer);
	}
	if (ft_containsnl(rook) != -1)//se rook contiene un newline
	{
		if (r == 0 && rook)
		{
			if (ft_containsnl(rook) == -1)
			{
				line = ft_strdup(rook);
				if (rook)
				free(rook);
				return (line);
			}
		}
		line = ft_substr((const char *)rook,0, ft_containsnl(rook));
		rook = ft_removeline(rook);
	}
	return (line);
}

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
int main(void)
{
	int fd = open("/home/lmongili/cc/get_next_line/file.txt", 'r');
	char *line = get_next_line(fd);
	line = get_next_line(fd);
	printf("%s", line);
	return (0);
}