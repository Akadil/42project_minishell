/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:29:42 by akalimol          #+#    #+#             */
/*   Updated: 2022/12/03 12:29:44 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*returner;

	returner = (t_list *)malloc(sizeof(t_list));
	if (!returner)
		return (NULL);
	returner->content = content;
	returner->next = NULL;
	return (returner);
}
