/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_safe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akadilkalimoldayev <akadilkalimoldayev@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:44:29 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/09 16:51:42 by akadilkalim      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear_safe(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (lst && del)
	{
		temp = *lst;
		while (temp)
		{
			temp = (*lst)->next;
			if ((*lst)->type != 0)
				ft_lstdelone(*lst, del);
			*lst = temp;
		}
	}
}
