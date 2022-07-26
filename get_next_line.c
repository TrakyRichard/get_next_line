#include "get_next_line.h"

typedef struct s_gnl
{
  char *line;
  char *next_buffer;
} t_gnl;

static char *ft_read(char *res, int fd)
{
  size_t byte_read;
  char *buffer;

  buffer = 1;
  res = ft_calloc(BUFF_SIZE, sizeof(char));
  if (res == NULL)
    return (NULL);
  while (buffer != 0)
  {
    buffer = read(fd, buffer, BUFF_SIZE);
    if (buffer == -1)
      return (NULL);
    res = ft_strjoin(res, buffer);
    if (ft_has_new_line(buffer) > 0)
      break;
  }
  return (res);
}

t_gnl ft_get_line(char *buffer, t_gnl *t_gnl)
{
  int buff_counter;
  int counter;

  buff_counter = 0;
  counter = 0;
  while (buffer[buff_counter] != '\n' && buffer[buff_counter] != '\0')
    buff_counter++;
  t_gnl->line = ft_calloc(buff_counter + 1, sizeof(char));
  if (t_gnl->line == NULL)
    return (*t_gnl);
  buff_counter = 0;
  while (buff_counter > counter++)
  {
    t_gnl->line[counter] = *buffer;
    buffer++;
  }
  t_gnl->line[counter] = '\0';
  return (*t_gnl);
}

char *get_next_line(int fd)
{
  static char *buffer;
  t_gnl t_gnl;
  if (fd < 0 && BUFFER_SIZE < 0)
    return (NULL);
  buffer = ft_read(buffer, fd);
  t_gnl.next_buffer = buffer;
  t_gnl = ft_get_line(buffer, &t_gnl);
  if (t_gnl.line == NULL)
    return (NULL);
  buffer = t_gnl.next_buffer;
  return (t_gnl.line);
}