/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_tree_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:27:24 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/01 18:28:58 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_data.h"
#include "struct_list.h"
#include <stdlib.h>
#include <stdio.h>

t_list	*ft_find_next_parenthesis(t_list *first)
{
	t_list	*next_p;
	int		count_p;

	count_p = 1;
	next_p = first->next;
	while (next_p)
	{
		if (next_p->type == RIGHT_P && count_p == 1)
			break ;
		if (next_p->type == RIGHT_P)
			count_p--;
		if (next_p->type == LEFT_P)
			count_p++;
		next_p = next_p->next;
	}
	return (next_p);
}

/*
    ret: 1 means cleaned, 0 means no
    int ft_clean_onion()
*/
int	ft_clean_onion(t_list **token)
{
	t_list	*first;
	t_list	*i_token;
	int		res;

	first = *token;
	res = 0;
	while (first->type == LEFT_P)
	{
		i_token = ft_find_next_parenthesis(first);
		if (!i_token->next)
		{
			res = 1;
			i_token->prev->next = NULL;
			free(i_token);
			*token = (*token)->next;
			free(first);
			first = *token;
			first->prev = NULL;
		}
		else
			break ;
	}
	return (res);
}
