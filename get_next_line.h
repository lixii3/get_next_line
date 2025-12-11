#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

char *get_next_line(int fd);
char	*ft_strdup(const char *s);

#endif