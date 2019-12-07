/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 12:39:19 by pmogwere          #+#    #+#             */
/*   Updated: 2019/06/26 13:48:05 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*placestring(char *str, size_t i)
{
	char	*s;

	if (!(s = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	s = ft_strncpy(s, str, i);
	s[i] = '\0';
	return (s);
}

char		**ft_strsplit(char const *s, char c)
{
	size_t	i;
	char	**strarry;
	char	**arryreturn;

	i = ft_elementcount((char *)s, c);
	strarry = (char **)malloc(sizeof(char *) * (i + 1));
	arryreturn = strarry;
	if (strarry == NULL || s == NULL)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			i = ft_strlenc((char *)s, c);
			*strarry++ = placestring((char *)s, i);
			s = s + i;
		}
		else
			s++;
	}
	*strarry = 0;
	return (arryreturn);
}
