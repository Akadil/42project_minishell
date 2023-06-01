/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign_types.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:28:25 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/01 20:00:34 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "struct_data.h"
#include "struct_list.h"

void	ft_assign_type(t_list *node, int is_filename);

/*
    Go through each value and assign the values

    if I see <. then no matter what the next token is infile

    I have to update it:
    1. Norminette
*/
void	ft_assign_types(t_list *node)
{
	int	is_filename;

	is_filename = 0;
	while (node)
	{
		ft_assign_type(node, is_filename);
		is_filename = 0;
		if (6 <= node->type && node->type <= 9)
			is_filename = 1;
		node = node->next;
	}
}

void	ft_assign_type(t_list *node, int is_filename)
{
	if (!ft_strcmp(node->content, "|") && node->type == 0)
		node->type = PIPE;
	else if (!ft_strcmp(node->content, "||") && node->type == 0)
		node->type = OR;
	else if (!ft_strcmp(node->content, "&&") && node->type == 0)
		node->type = AND;
	else if (!ft_strcmp(node->content, "(") && node->type == 0)
		node->type = LEFT_P;
	else if (!ft_strcmp(node->content, ")") && node->type == 0)
		node->type = RIGHT_P;
	else if (!ft_strcmp(node->content, "<") && node->type == 0)
		node->type = REDIRECT_IN;
	else if (!ft_strcmp(node->content, "<<") && node->type == 0)
		node->type = HEREDOC;
	else if (!ft_strcmp(node->content, ">") && node->type == 0)
		node->type = REDIRECT_OUT;
	else if (!ft_strcmp(node->content, ">>") && node->type == 0)
		node->type = REDIRECT_OUT2;
	else if (is_filename == 1 && node->type == 0)
		node->type = FILENAME;
	else
		node->type = PARAMETER;
}
