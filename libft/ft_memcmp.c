/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 13:16:23 by pmogwere          #+#    #+#             */
/*   Updated: 2019/05/28 11:01:23 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*c;
	unsigned char	*d;

	i = 0;
	d = (unsigned char *)s1;
	c = (unsigned char *)s2;
	while (n-- != 0)
	{
		if (d[i] != c[i])
			return (d[i] - c[i]);
		i++;
	}
	return (0);
}
