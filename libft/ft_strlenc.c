/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlenc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 12:35:02 by pmogwere          #+#    #+#             */
/*   Updated: 2019/06/14 12:48:42 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlenc(char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s++ != c)
			count++;
		else
			return (count);
	}
	return (count);
}
