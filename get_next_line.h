#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#define BUFFER_SIZE 42
#include <stdlib.h>
#include <unistd.h>

char *get_next_line(int fd);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
void	*ft_memmove(void *dest, const void *src, size_t n);
#endif