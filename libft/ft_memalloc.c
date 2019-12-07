/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 14:56:37 by pmogwere          #+#    #+#             */
/*   Updated: 2019/06/12 14:19:57 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void	*s;

	s = (void *)malloc(size);
	if (s == NULL)
	{
		return (NULL);
	}
	ft_memset(s, 0, size);
	return (s);
}
