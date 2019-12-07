/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 08:16:22 by pmogwere          #+#    #+#             */
/*   Updated: 2019/06/26 12:48:38 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcat(char *restrict s1, const char *restrict s2)
{
	size_t	i;
	size_t	holds1;

	i = 0;
	holds1 = ft_strlen(s1);
	while (s2[i] != '\0')
		s1[holds1++] = s2[i++];
	s1[holds1] = '\0';
	return (s1);
}
