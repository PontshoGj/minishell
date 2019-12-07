/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 10:49:36 by pmogwere          #+#    #+#             */
/*   Updated: 2019/06/27 09:43:58 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (ft_strlen(s1) == ft_strlen("") && ft_strlen(s2) != ft_strlen(""))
		return (-1);
	while (n-- != 0 && s1 != 0 && s2 != 0)
	{
		if (s1[i] == 0 || s2[i] == 0)
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (s1[i] != s2[i])
		{
			if ((unsigned char)s1[i] - (unsigned char)s2[i] > 0)
				return (1);
			else
				return (-1);
		}
		i++;
	}
	return (0);
}
