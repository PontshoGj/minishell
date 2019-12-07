/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 07:44:26 by pmogwere          #+#    #+#             */
/*   Updated: 2019/05/28 16:37:33 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	hol;
	char	*d;
	char	*e;

	i = 0;
	hol = 0;
	d = (char *)s;
	e = (char *)malloc(sizeof(char));
	while (d[i] != '\0')
	{
		if (d[i] == (char)c)
		{
			e = &d[i];
			hol++;
		}
		i++;
	}
	if (hol > 0)
		return (e);
	if (d[i] == (char)c)
		return (&d[i]);
	free(e);
	return (NULL);
}
