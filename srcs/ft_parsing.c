/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:04:10 by akadilkalim       #+#    #+#             */
/*   Updated: 2023/05/16 17:54:21 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_parsing.h"

void    ft_parsing(t_data *data, char *cmd_line)
{
    t_list  *head;
	t_node	*node;

    cmd_line = ft_add_spaces(cmd_line);
	if (!cmd_line)
		ft_error_clean_exit(data);
    head = ft_tokenization(cmd_line);
	if (!head)
	{
		free (cmd_line);
		ft_clean_exit(data);
	}
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
}