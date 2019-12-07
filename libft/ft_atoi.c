/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 14:22:53 by pmogwere          #+#    #+#             */
/*   Updated: 2019/09/14 13:50:27 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		calcnum(char *str)
{
	int			i;
	long int	ret;

	i = 0;
	ret = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return ((int)ret);
		if (ft_isdigit(str[i]))
			ret = (((ret * 100) + (((int)str[i] - 48) * 10)) / 10);
		i++;
	}
	return ((int)ret);
}

static int		chkdigi(char *str)
{
	int			i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isalpha(str[i++]))
			return (1);
	}
	return (0);
}

static int		chklong(char *str)
{
	if (ft_strlen(str) > 19 && chkdigi(str) == 0)
		return (1);
	return (0);
}

int				ft_atoi(const char *str)
{
	int			i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-')
		{
			if (chklong((char *)&str[i++]) > 0)
				return (0);
			return (calcnum((char *)&str[i]) * -1);
		}
		if (ft_isdigit(str[i]) || str[i] == '+')
		{
			if (str[i] == '+')
				i++;
			if (chklong((char *)&str[i]) > 0)
				return (-1);
			return (calcnum((char *)&str[i]));
		}
		if (str[i] == '\e' || ft_isalpha(str[i]) || str[i] == '\200')
			return (0);
		i++;
	}
	return (0);
}
