/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:04:10 by akadilkalim       #+#    #+#             */
/*   Updated: 2023/05/15 16:02:36 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_parsing.h"

void    line_parsing(t_data *data, char *cmd_line)
{
    char    *str;
    t_list  *head;
	t_node	*node;

    str = ft_add_spaces(cmd_line);
    head = ft_tokenization(str);
    ft_assign_types(head);
	ft_check_tokens(head);
	// Check for correct position of each element
	// This should be inside of ft_assign_types
	/*
		At least:
				1. (). There should be no "no operators" around them
				2. Think of the redirections for above case
	*/
	node = ft_make_tree(head, NULL);
	ft_preprocess(node);
}