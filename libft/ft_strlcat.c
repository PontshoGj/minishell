/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 08:23:50 by pmogwere          #+#    #+#             */
/*   Updated: 2019/06/23 16:11:20 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	lendst;
	size_t	holdst;

	i = 0;
	lendst = ft_strlen(dst);
	holdst = lendst + ft_strlen(src);
	if (size == 0)
		return (ft_strlen(src));
	if (lendst >= size)
		return (ft_strlen(src) + size);
	while (lendst < size - 1 && src[i] != 0)
		dst[lendst++] = src[i++];
	dst[lendst] = '\0';
	return (holdst);
}
