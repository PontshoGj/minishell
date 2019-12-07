/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 12:09:34 by pmogwere          #+#    #+#             */
/*   Updated: 2019/07/31 12:31:12 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			hex(char *str, int base)
{
	int		i;
	size_t	j;
	int		f;

	i = 0;
	j = 0;
	f = 0;
	while (str[f] != 0)
		f++;
	f -= 1;
	while (f >= 0)
	{
		if (str[f] >= 'a' && str[f] <= 'f')
			i += ((str[f] - 97) + 10) * ft_pow(j, base);
		else if (str[f] >= 'A' && str[f] <= 'F')
			i += ((str[f] - 65) + 10) * ft_pow(j, base);
		else
			i += (str[f] - 48) * ft_pow(j, base);
		j++;
		f--;
	}
	return (i);
}

int			ft_atoi_base(const char *str, int str_base)
{
	int		i;

	while (*str <= 32)
		str++;
	i = (*str == '-' || *str == '+') ? -1 : 1;
	(*str == '-' || *str == '+') ? ++str : 0;
	if (*str == '-' || *str == '+' || *str <= 32)
		return (0);
	else
		return (hex((char *)str, str_base) * i);
}
