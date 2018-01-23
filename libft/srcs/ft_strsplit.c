/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdurot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 20:19:10 by qdurot            #+#    #+#             */
/*   Updated: 2017/04/30 19:02:49 by qdurot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_field(char const *s, char c)
{
	size_t	i;
	size_t	read;
	size_t	field;

	i = 0;
	read = 0;
	field = 0;
	while (s[i])
	{
		if (s[i] == c)
			read = 0;
		else if (!(s[i] == c) && read == 0)
		{
			read = 1;
			field++;
		}
		i++;
	}
	return (field);
}

static size_t	ft_field_len(char const *s, char c)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (s[k] == c)
		k++;
	while (s[k + i] && (s[k + i] != c))
		i++;
	return (k + i);
}

static char		*ft_add_to_tab(char *tab, char const *field, char c)
{
	size_t	i;
	size_t	k;
	size_t	len;

	i = 0;
	k = 0;
	while (field[i] == c)
		i++;
	len = ft_field_len(&field[i], c);
	i = 0;
	if (!(tab = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		if (field[k] != c)
			tab[i++] = field[k];
		k++;
	}
	tab[i] = '\0';
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	fields;
	char	**tab;

	i = 0;
	j = 0;
	if (!s || !c)
		return (NULL);
	fields = ft_count_field(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (fields + 1))))
		return (0);
	while (j < fields)
	{
		tab[j] = ft_add_to_tab(tab[j], &s[i], c);
		j++;
		i += ft_field_len(&s[i], c);
	}
	tab[j] = NULL;
	return (tab);
}
