/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdurot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 20:54:41 by qdurot            #+#    #+#             */
/*   Updated: 2017/05/01 17:54:08 by qdurot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	size_t	i;
	char	*ret;
	int		sign;

	i = 0;
	if (!(ret = (char *)malloc(sizeof(char) * 12)))
		return (0);
	if (n == 0)
		return (ft_strdup("0"));
	sign = (n < 0) ? 1 : 0;
	while (n != 0)
	{
		ret[i++] = (sign) ? (-1 * (n % 10)) + '0' : (n % 10) + '0';
		n /= 10;
	}
	if (sign)
		ret[i++] = '-';
	ret[i] = '\0';
	return (ft_strrev(ret));
}
