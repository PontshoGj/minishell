/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 13:44:42 by pmogwere          #+#    #+#             */
/*   Updated: 2019/06/11 18:02:18 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*c;

	i = 0;
	d = (unsigned char *)src;
	c = (unsigned char *)dest;
	if (c == NULL && d == NULL)
		return (NULL);
	while (n-- != 0)
	{
		c[i] = d[i];
		i++;
	}
	return (dest);
}
