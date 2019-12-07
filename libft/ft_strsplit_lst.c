/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:55:25 by pmogwere          #+#    #+#             */
/*   Updated: 2019/06/27 17:04:22 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_strsplit_lst(char const *s, char c)
{
	char	**str;
	t_list	*elem;
	t_list	*adds;
	size_t	i;

	str = ft_strsplit(s, c);
	if (!(elem = ft_lstnew(str[0], ft_strlen(str[0]))))
		return (0);
	i = 1;
	while (i < ft_elementcount((char *)s, c))
	{
		if (!(adds = ft_lstnew(str[i], ft_strlen(str[i]))))
			return (0);
		ft_lstadd(&elem, adds);
		i++;
	}
	ft_strdel(str);
	return (elem);
}
