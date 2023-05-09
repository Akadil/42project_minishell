/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akadilkalimoldayev <akadilkalimoldayev@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 14:39:44 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/09 16:49:10 by akadilkalim      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*returner;
	t_list	*temp;

	if (!lst || !f || !del)
		return (NULL);
	returner = NULL;
	while (lst)
	{
		temp = ft_lstnew((*f)(lst->content), 0);
		if (!temp)
		{
			ft_lstclear(&returner, del);
			return (NULL);
		}
		ft_lstadd_back(&returner, temp);
		lst = lst->next;
	}
	return (returner);
}
