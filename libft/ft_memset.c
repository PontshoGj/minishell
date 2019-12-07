/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 07:27:15 by pmogwere          #+#    #+#             */
/*   Updated: 2019/05/22 12:50:58 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *str, int c, size_t len)
{
	unsigned char	*stred;
	size_t			i;

	stred = (unsigned char *)str;
	i = 0;
	if (len != 0)
	{
		while (len-- != 0)
		{
			stred[i++] = (unsigned char)c;
		}
	}
	return (str);
}
