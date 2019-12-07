/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 14:37:33 by pmogwere          #+#    #+#             */
/*   Updated: 2019/09/14 13:51:05 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*lmin(int n)
{
	char	*s;

	if (!(s = (char *)malloc(sizeof(char) * 20)))
		return (NULL);
	if (n == (-2147483647 - 1))
		return (s = ft_strcpy(s, "-2147483648"));
	if (n == 2147483647)
		return (s = ft_strcpy(s, "2147483647"));
	return (s);
}

static char	*ft_assing(int n)
{
	int		i;
	int		j;
	char	*str;

	i = ft_intlen(n);
	j = 0;
	if (!(str = (char *)malloc(sizeof(char) * ft_intlen(n) + 1)))
		return (NULL);
	str[i--] = '\0';
	if (n < 0)
	{
		n *= -1;
		j -= 1;
	}
	while (i >= 0)
	{
		str[i--] = (n % 10) + '0';
		n /= 10;
		if (j < 0)
			str[0] = '-';
	}
	return (str);
}

char		*ft_itoa(int n)
{
	char	*str;

	str = NULL;
	if (!(str = (char *)malloc(sizeof(char) * ft_intlen(n) + 1)))
		return (NULL);
	if ((n == (-2147483647 - 1)) || (n >= 2147483647 || n < (-2147483647 - 1)))
		return (str = lmin(n));
	if (n == 0)
		return (str = ft_strcpy(str, "0"));
	str = ft_assing(n);
	return (str);
}
