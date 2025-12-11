#include "get_next_line.h"

int	ft_terminates(char *buffer)
{
	int		i;

	i = -1;
	while (++i < BUFFER_SIZE)
	{
		if (buffer[i] == 0)
			return (i);
	}
	return (-1);
}

char *get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE];
	int		r;
	int		term;
	char	*str;

	r = read(fd, buffer, BUFFER_SIZE);
	if (r == -1)
		return (NULL);
	if (r == 0)
		return (str = ft_strdup((const char *)buffer));
	term = ft_terminates(buffer);
	while (term == -1)
	{
		str = ft_strdup((const char *)buffer);
		r = read(fd, buffer, BUFFER_SIZE);
		if (r == 0)
			break;
		else if (r == -1)
			return (NULL);
	}
		
		r = read(fd, buffer, BUFFER_SIZE);
	return (str = ft_strdup((const char *)buffer));
}