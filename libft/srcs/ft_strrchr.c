/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdurot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 16:53:49 by qdurot            #+#    #+#             */
/*   Updated: 2017/04/16 16:55:40 by qdurot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	cc;

	i = 0;
	cc = (char)c;
	while (s[i])
		i++;
	if (s[i] == c)
		return ((char *)&s[i]);
	else
	{
		while (i)
		{
			if (s[i] == cc)
				return ((char *)&s[i]);
			else
				i--;
		}
		if (s[i] == cc)
			return ((char *)&s[i]);
	}
	return (NULL);
}
