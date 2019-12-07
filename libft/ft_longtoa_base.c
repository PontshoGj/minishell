/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longtoa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 13:43:01 by pmogwere          #+#    #+#             */
/*   Updated: 2019/09/14 13:44:32 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*bigrsmallhexlong(char s)
{
	if (s == 'X')
		return ("0123456789ABCDEF");
	return ("0123456789abcdef");
}

char			*ft_longtoa_base(long long i, int base, char h)
{
	char		*s;
	char		*str;
	int			neg;
	long long	len;

	s = bigrsmallhexlong(h);
	len = ft_lenlong_base(i, base);
	neg = 1;
	if (i < 0)
	{
		neg *= -1;
		i *= -1;
		(base == 10) ? len++ : 0;
	}
	str = (char *)malloc(sizeof(char) * len);
	str[len--] = 0;
	while (i)
	{
		str[len--] = s[i % base];
		i /= base;
	}
	(neg < 0 && base == 10) ? str[0] = '-' : 0;
	return (str);
}
