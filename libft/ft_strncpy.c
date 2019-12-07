/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 14:15:33 by pmogwere          #+#    #+#             */
/*   Updated: 2019/05/28 16:08:56 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	b;

	i = 0;
	b = ft_strlen(src);
	if (sizeof(dst) >= sizeof(src))
	{
		while (len-- > 0)
		{
			if (b-- > 0 && src[i] != '\0')
			{
				dst[i] = src[i];
			}
			else
			{
				dst[i] = '\0';
			}
			i++;
		}
	}
	return (dst);
}
