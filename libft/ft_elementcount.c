/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elementcount.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 12:11:18 by pmogwere          #+#    #+#             */
/*   Updated: 2019/06/26 10:41:50 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_elementcount(char *s, char c)
{
	size_t	count;
	size_t	result;
	size_t	i;

	count = 0;
	result = 0;
	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			while (s[i] != '\0' && s[i] != c)
			{
				count++;
				i++;
			}
			result += count / count;
		}
		else
			i++;
	}
	return (result);
}
