/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 09:06:43 by pmogwere          #+#    #+#             */
/*   Updated: 2019/06/12 14:20:49 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*temp;

	if (!(temp = (t_list *)malloc(sizeof(temp))))
		return (NULL);
	if ((void *)content == NULL || content_size == 0)
	{
		temp->content = NULL;
		temp->content_size = 0;
		temp->next = NULL;
		return (temp);
	}
	else
	{
		temp->content_size = (size_t)malloc(content_size);
		if ((temp->content = malloc(content_size + 1)) && temp->content_size)
		{
			temp->content = ft_memcpy(temp->content, content, content_size);
			temp->content_size = content_size;
			temp->next = NULL;
			return (temp);
		}
	}
	return (NULL);
}
