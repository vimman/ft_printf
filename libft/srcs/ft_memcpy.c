/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdurot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 15:19:28 by qdurot            #+#    #+#             */
/*   Updated: 2017/05/02 20:56:13 by qdurot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*csrc;
	unsigned char		*cdst;
	unsigned long int	*ldst;
	unsigned long int	*lsrc;

	lsrc = (unsigned long int *)src;
	ldst = (unsigned long int *)dst;
	while (n >= sizeof(long int))
	{
		*ldst++ = *lsrc++;
		n -= 8;
	}
	csrc = (unsigned char *)lsrc;
	cdst = (unsigned char *)ldst;
	while (n--)
	{
		*cdst++ = *csrc++;
	}
	return (dst);
}
