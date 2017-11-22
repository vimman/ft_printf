#include <stdarg.h>
#include <stdio.h>
#include "../../42/libft/libft.h"

int is_flag(char c)
{
	if (ft_strchr("diuoxXcsSp%%C", c) == 1)
		return (1);
	else if(ft_strchr("hljztL", c) == 1)
		return (2);
	else if(ft_strchr("-+#. *", c) == 1 || ft_isdigit(c))
		return (3);
	return (0);
}

void ft_check(char *format, t_data *data)
{
    int i;

    i = 0;
    while (is_flag(format[i]) == 3)
    {
      if(format[i] == '-')
        data->left = 1;
      if(format[i] == '+')
        data->signe = 1;
      if(format[i] == '#')
        data->diese = 1;
      if(format[i] == ' ')
        data->space = 1;
      if(format[i] == '.')
      {
        data->preci == ft_itoa(&format[++i]); /* ATTENTION !!! 123 OR * faire appel a va_arg*/
        i += ft_nblen(&format[i]) - 1; /* ATTENTION retrouver la fonction qui calcule la longueur du nombre*/
      }
      if(ft_isdigit(format[i]))
      {
        data->width = ft_itoa(&format[i]);
        i += ft_nblen(&format[i]) - 1;
      }
      i++;
    }
    else if (is_flag(format[i]) == 2)
    {
      data->types = format[i];
      if (format[i] == 'h' || format[i] == 'l')
        if (format[i + 1] == format[i])
          data->type += format[++i];
    }
    if(is_flag(format[i]) == 1)
      data->spec = format[i];
}
