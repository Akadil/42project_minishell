/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:04:10 by akadilkalim       #+#    #+#             */
/*   Updated: 2023/05/23 18:34:21 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parsing.h"


/*
	I want to restructure it. I want to make a clean, and it should work
	So I have to pass only specific information
*/
t_node	*ft_parsing(char *command, t_list *env)
{
	t_node	*node;
    t_list  *head;
	char	*cmd_line;

    cmd_line = ft_add_spaces(command);
	if (!cmd_line)
		return (NULL);
	head = ft_tokenization(cmd_line, env);
	free(cmd_line);
	if (!head)
		return (NULL);
    ft_assign_types(head);
	if (ft_check_tokens(head) == 0)
	{
		ft_clean_tokens(&head);
		return (NULL);
	}
	node = ft_make_tree(head, NULL);
	if (!node)
	{
		ft_clean_tokens(&head);
		return (NULL);
	}
	return (node);
}