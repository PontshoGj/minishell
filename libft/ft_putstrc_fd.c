/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrc_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 12:31:56 by pmogwere          #+#    #+#             */
/*   Updated: 2019/08/20 12:33:25 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putstrc_fd(char *s, int fd, int size)
{
	size_t	i;

	i = 0;
	if (s != NULL)
	{
		while (s[i] != 0 && size-- > 0)
			ft_putchar_fd(s[i++], fd);
	}
}
