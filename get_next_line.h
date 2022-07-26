#include <unistd.h>

char *get_next_line(int fd);
t_gnl ft_get_line(char *buffer, t_gnl *t_gnl);
static char *ft_read(char *res, int fd);
int ft_strcpy(const char *src, char *dst);
int ft_strcat(const char *src, char *dst);
int ft_strjoin(const char *src1, const char *src2);
char *ft_calloc(size_t count, size_t size);
int ft_has_new_line(char *str);
