/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 13:44:03 by pmogwere          #+#    #+#             */
/*   Updated: 2019/06/26 13:52:34 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	a;

	d = (unsigned char *)s;
	a = (unsigned char)c;
	while (n-- > 0)
	{
		if (*d == a)
			return (d);
		d++;
	}
	return (NULL);
}
