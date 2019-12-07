/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 11:08:51 by pmogwere          #+#    #+#             */
/*   Updated: 2019/06/27 17:23:42 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		ret;
	char	*c;

	i = 0;
	ret = 0;
	c = (char *)haystack;
	if ((needle == NULL && haystack == NULL))
		return (NULL);
	if (ft_strcmp(needle, "") == 0)
		return ((char *)haystack);
	while (c[i] != '\0')
	{
		if (ft_strlen(needle) > len--)
			return (NULL);
		if (c[i] == needle[0])
		{
			ret = ft_strncmp(&c[i], needle, ft_strlen(needle));
			if (ret == 0)
				return ((char *)&c[i]);
		}
		i++;
	}
	return (NULL);
}
