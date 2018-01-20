/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdurot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 15:19:34 by qdurot            #+#    #+#             */
/*   Updated: 2017/05/02 20:57:29 by qdurot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	while (len % 8)
	{
		((unsigned char *)b)[--len] = (unsigned char)c;
	}
	while (len)
	{
		((unsigned char *)b)[--len] = (unsigned char)c;
		((unsigned char *)b)[--len] = (unsigned char)c;
		((unsigned char *)b)[--len] = (unsigned char)c;
		((unsigned char *)b)[--len] = (unsigned char)c;
		((unsigned char *)b)[--len] = (unsigned char)c;
		((unsigned char *)b)[--len] = (unsigned char)c;
		((unsigned char *)b)[--len] = (unsigned char)c;
		((unsigned char *)b)[--len] = (unsigned char)c;
	}
	return (b);
}
