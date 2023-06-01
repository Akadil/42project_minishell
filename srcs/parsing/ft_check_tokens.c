/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:42:20 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/01 19:08:22 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"
#include "libft.h"
#include "struct_data.h"
#include "struct_list.h"

char	*ft_check_parenthesis(t_list *node, int *p_count);

char	*ft_check_operator2(t_list *node)
{
	if (node->prev == NULL)
		return ((char *)node->content);
	if (node->next == NULL)
		return ("newline");
	if (1 <= node->next->type && node->next->type <= 3)
		return ((char *)node->next->content);
	if (node->next->type == 5)
		return ((char *)node->next->content);
	if (node->type == 1 && node->next->type == 4)
		return (node->next->content);
	return (NULL);
}

char	*ft_check_redirection(t_list *node)
{
	if (!node->next)
		return ("newline");
	if (node->next->type != 10)
		return ((char *)node->next->content);
	return (NULL);
}

int	ft_check_tokens(t_list *node)
{
	char	*error;
	int		p_count;

	p_count = 0;
	error = NULL;
	while (node)
	{
		if (1 <= node->type && node->type <= 3)
			error = ft_check_operator2(node);
		else if (node->type == 4 || node->type == 5)
			error = ft_check_parenthesis(node, &p_count);
		else if (6 <= node->type && node->type <= 9)
			error = ft_check_redirection(node);
		if (error)
		{
			ft_merror("bash: syntax error near unexpected token `%s'\n", error);
			return (0);
		}
		node = node->next;
	}
	if (p_count != 0)
		return (ft_merror("bash: unclosed parenthesis\n", NULL), 0);
	return (1);
}
