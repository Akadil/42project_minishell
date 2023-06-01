/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tokens_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 19:06:23 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/01 19:10:09 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_list.h"
#include <stdio.h>

char	*ft_check_parenthesis_left(t_list *node, int *p_count);
char	*ft_check_parenthesis_right(t_list *node, int *p_count);

char	*ft_check_parenthesis(t_list *node, int *p_count)
{
	if (node->type == 4)
		return (ft_check_parenthesis_left(node, p_count));
	else
		return (ft_check_parenthesis_right(node, p_count));
	return (NULL);
}

char	*ft_check_parenthesis_left(t_list *node, int *p_count)
{
	(*p_count)++;
	if (!node->next)
		return ("newline");
	if (node->next->type == 5)
		return ((char *)node->next->content);
	if (node->prev && node->prev->type == 11)
		return ((char *)node->next->content);
	if (node->prev && (node->prev->type == 10 || node->prev->type == 1))
		return ((char *)node->content);
	if (1 <= node->next->type && node->next->type <= 3)
		return ((char *)node->next->content);
	return (NULL);
}

char	*ft_check_parenthesis_right(t_list *node, int *p_count)
{
	(*p_count)--;
	if (*p_count == -1)
		return ((char *)node->content);
	if (!node->prev)
		return ((char *)node->content);
	if (node->next && node->next->type == 4)
		return ((char *)node->next->content);
	if (node->next && node->next->type != 2 && node->next->type != 3
		&& node->next->type != 5)
		return ((char *)node->next->content);
	if (node->next && node->next->type == 1)
		return ((char *)node->next->content);
	return (NULL);
}
