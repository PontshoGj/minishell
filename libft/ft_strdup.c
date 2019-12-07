/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 13:46:18 by pmogwere          #+#    #+#             */
/*   Updated: 2019/06/27 17:12:52 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*c;

	if (!(c = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1)) || s1 == NULL)
		return (0);
	return (ft_strcpy(c, s1));
}
