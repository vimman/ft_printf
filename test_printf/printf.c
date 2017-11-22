#include <stdarg.h>
#include <stdio.h>
#include "../../42/libft/libft.h"

typedef struct s_data
{
  int start;
  int end;
  char spec; /* format*/
  char left; /* flag - si 1: ecrire a gauche */
  char sign; /* flag + si 1: mettre le signe selon positif/negatif*/
  char space; /* flag espace : on met l'espace que si on a pas le signe*/
  char diese; /*0 or 0x selon si c en octal ou hexadecimal*/
  char zero; /* espaces remplaces par des zero*/
  int width; /* largeur de ma string renvoyee*/
  int preci; /* longueur max de l'argument ou bien remplace les espaces par des zeros pour les nombres*/
  int types;
}               t_data;

void ft_putformat(const char *format, int start, int end)
{
  write(1, &format[start], (end - start + 1));
}

void ft_init(t_data *data)
{
  data->start = 0;
  data->end = 0;
}

int ft_printf(const char *format, ...)
{
  t_data *data;
  if (!(data = (t_data*)malloc(sizeof(t_data) * 1)))
    return (-1);
  ft_init(data);
  va_list(ap);
  va_start(ap, format);
  while (format[data->end])
  {
    if (format[data->end] == '%')
    {
      ft_putformat(format, data->start, data->end - 1);
      ft_check(&format[data->end], data);
      data->start = data->end;
    }
    data->end++;
  }
  ft_putformat(format, data->start, data->end);
  va_end(ap);
  return (0);
}

int main()
{
  ft_printf("Bonjour %s comment ca va %s? Verif");
}
