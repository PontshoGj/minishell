/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 09:53:15 by pmogwere          #+#    #+#             */
/*   Updated: 2019/06/23 14:47:46 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_printnumber(int n, int fd)
{
	if (n == (-2147483647 - 1) || n == 2147483647)
	{
		if (n < -1)
			ft_putstr_fd("-2147483648", fd);
		else
			ft_putstr_fd("2147483647", fd);
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n > 2147483647 || n < (-2147483647 - 1))
		return ;
	if (n == (-2147483647 - 1) || n == 2147483647)
	{
		ft_printnumber(n, fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd((n % 10) + '0', fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}
