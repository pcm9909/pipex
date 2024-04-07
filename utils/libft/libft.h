# ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

void *ft_memcpy(void *dst, const void *src, size_t n);
size_t ft_strlen(const char *str);
size_t ft_strlcpy(char *dst, const char *src, size_t size);
size_t ft_strlcat(char *dst, const char *src, size_t size);
int ft_strncmp(const char *str1, const char *str2, size_t len);
char *ft_strdup(const char *str);
char *ft_substr(char const *s, unsigned int start, size_t len);
char *ft_strjoin(char const *s1, char const *s2);
char **ft_split(char const *s, char c);
void ft_putstr_fd(char *s, int fd);

#endif