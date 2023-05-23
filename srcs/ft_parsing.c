/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:04:10 by akadilkalim       #+#    #+#             */
/*   Updated: 2023/05/23 16:20:25 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parsing.h"
#include "ft_clean.h"

/*
	I want to restructure it. I want to make a clean, and it should work
	So I have to pass only specific information
*/
int    ft_parsing(t_data *data, char *command)
{
    t_list  *head;
	char	*cmd_line;

    cmd_line = ft_add_spaces(command);
	if (!cmd_line)
		return (-1);
	head = ft_tokenization(cmd_line, data->env);
	free(cmd_line);
	if (!head)
		return (-1);
    ft_assign_types(head);
	if (ft_check_tokens(head) == 0)
	{
		ft_clean_tokens(&head);
		return (-1);
	}
	data->node = ft_make_tree(head, NULL);
	if (!data->node)
	{
		ft_clean_tokens(&head);
		return (-1);
	}
	return (0);
}