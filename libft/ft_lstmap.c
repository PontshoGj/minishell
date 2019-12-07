/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 13:44:39 by pmogwere          #+#    #+#             */
/*   Updated: 2019/06/23 15:01:00 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*temp;
	t_list	*head;

	if (!f || !lst)
		return (0);
	if (!(temp = f(lst)))
		return (NULL);
	head = temp;
	while (lst->next != NULL)
	{
		lst = lst->next;
		if (!(temp->next = f(lst)))
			return (NULL);
		temp = temp->next;
	}
	return (head);
}
