/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_upper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 10:15:37 by pmogwere          #+#    #+#             */
/*   Updated: 2019/06/27 10:40:39 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_str_to_upper(char *s)
{
	char	*g;
	char	*c;

	if (!(g = (char *)malloc(sizeof(char) * ft_strlen(s) + 1)) && !s)
		return (0);
	c = g;
	while (*s)
	{
		if (ft_isalpha(*s))
			*g++ = ft_toupper(*s);
		else
			*g++ = *s;
		s++;
	}
	*g = '\0';
	return (c);
}
