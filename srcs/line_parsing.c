/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:04:10 by akadilkalim       #+#    #+#             */
/*   Updated: 2023/05/11 18:43:04 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_parsing.h"

void    line_parsing(t_data *data, char *cmd_line)
{
    char    *str;
    t_list  *head;

    str = ft_add_spaces(cmd_line);
    head = ft_tokenization(str);
    ft_assign_types(head);
	// Check for correct position of each element
	/*
		At least:
				1. (). There should be no "no operators" around them
				2. Think of the redirections for above case
	*/
	ft_make_tree(head);
}