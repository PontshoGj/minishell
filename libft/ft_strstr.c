/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 10:41:43 by pmogwere          #+#    #+#             */
/*   Updated: 2019/05/31 15:01:25 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	int		ret;
	char	*c;

	i = 0;
	ret = 0;
	c = (char *)haystack;
	if (needle == NULL && haystack == NULL)
		return ("");
	if (ft_strcmp(needle, "") == 0)
		return ((char *)haystack);
	while (c[i] != '\0')
	{
		if (c[i] == needle[0])
		{
			ret = ft_strncmp(&c[i], needle, ft_strlen(needle));
			if (ret == 0)
				return (&c[i]);
		}
		i++;
	}
	return (NULL);
}
