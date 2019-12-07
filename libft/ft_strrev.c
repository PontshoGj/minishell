/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 14:32:43 by pmogwere          #+#    #+#             */
/*   Updated: 2019/06/14 15:36:15 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrev(char *str)
{
	size_t	i;
	char	*s;
	char	*c;

	if (!str)
		return (NULL);
	i = ft_strlen(str);
	if (!(s = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	c = s;
	i--;
	while ((int)i > -1)
		*s++ = str[(int)i--];
	*s = '\0';
	return (c);
}
