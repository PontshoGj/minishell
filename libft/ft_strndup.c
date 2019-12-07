/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 13:46:18 by pmogwere          #+#    #+#             */
/*   Updated: 2019/06/24 14:39:38 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup(const char *s, size_t j)
{
	size_t	i;
	char	*c;

	i = 0;
	c = (char *)malloc(sizeof(char) * j + 1);
	if (c == NULL)
		return (NULL);
	while (s[i] != '\0' && j-- > 0)
	{
		c[i] = s[i];
		i++;
	}
	c[i] = '\0';
	return (c);
}
