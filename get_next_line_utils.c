#include "get_next_line.h"

ft_strcpy(const char* src, char* dst)
{
  int i;

  i = 0;
  while (src[i] != '\0')
  {
    dst[i] = src[i];
    i++;
  }
  dst[i] = '\0';
}

ft_strcat(const char* src, char* dst)
{
  int i;
  int j;

  i = 0;
  j = 0;
  while (dst[i] != '\0')
    i++;
  while (src[j] != '\0')
  {
    dst[i] = src[j];
    i++;
    j++;
  }
  dst[i] = '\0';
}

ft_strjoin(const char* src1, const char* src2){
  char* dst;
  int i;
  int j;

  i = 0;
  j = 0;
  while (src1[i] != '\0')
    i++;
  while (src2[j] != '\0')
    j++;
  dst = (char*)malloc(sizeof(char) * (i + j + 1));
  ft_strcpy(src1, dst);
  ft_strcat(src2, dst);
  return dst;
}

char *ft_calloc(size_t count, size_t size)
{
  char *str;
  int i;

  i = 0;
  str = (char *)malloc(sizeof(char) * (count * size));
  if (str == NULL)
    return (NULL);
  while (i < count * size)
  {
    str[i] = '\0';
    i++;
  }
  return str;
}

ft_has_new_line(char *str)
{
  int i;

  i = 0;
  while (str[i] != '\0')
  {
    if (str[i] == '\n')
      return (i);
    i++;
  }
  return (-1);
}