/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 10:42:52 by pmogwere          #+#    #+#             */
/*   Updated: 2019/07/29 11:00:34 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strspn(const char *s, const char *charset)
{
	size_t	i;
	size_t	j;
	size_t	count;

	j = 0;
	i = 0;
	count = 0;
	while (s[i] != 0)
	{
		while (charset[j] != 0)
		{
			if (s[i] == charset[j])
				count++;
			j++;
		}
		if (count == 0)
			return (i);
		count = 0;
		j = 0;
		i++;
	}
	return (i);
}
