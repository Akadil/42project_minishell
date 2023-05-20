/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:04:10 by akadilkalim       #+#    #+#             */
/*   Updated: 2023/05/20 19:06:20 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parsing.h"

/*
	I want to restructure it. I want to make a clean, and it should work
	So I have to pass only specific information
*/
int    ft_parsing(t_data *data, char *command)
{
    t_list  *head;
	t_node	*node;
	char	*cmd_line;

    cmd_line = ft_add_spaces(command);
	if (!cmd_line)
		return (-1);
	head = ft_tokenization(cmd_line);
	free(cmd_line);
	if (!head)
		return (-1);
    ft_assign_types(head);
	if (ft_check_tokens(head) == 0)
		ft_clean_exit(data);
	// Check for correct position of each element
	// This should be inside of ft_assign_types
	/*
		At least:
				1. (). There should be no "no operators" around them
				2. Think of the redirections for above case
	*/
	node = ft_make_tree(head, NULL);
}