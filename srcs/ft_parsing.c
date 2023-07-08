/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:04:10 by akadilkalim       #+#    #+#             */
/*   Updated: 2023/07/08 19:31:52 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_parsing.h"
#include "struct_data.h"

/*
	I want to restructure it. I want to make a clean, and it should work
	So I have to pass only specific information
*/
int	ft_parsing(char *command, t_list *env, t_data *data)
{
	t_list	*head;
	char	*cmd_line;
	int		code;

	data->node = NULL;
	cmd_line = ft_add_spaces(command);
	if (!cmd_line)
		return (data->exit_code = 255, 255);
	head = ft_tokenization(cmd_line, env, data);
	free(cmd_line);
	if (!head)
		return (data->exit_code = 255, 255);
	ft_assign_types(head);
	if (ft_check_tokens(head) == 0)
		return (data->exit_code = 2, ft_clean_tokens(&head, &free), 2);
	// code = ft_extend_wildcard(&head);
	// if (code == 0)
		// return (data->exit_code = code, ft_clean_tokens(&head, &free), code);
	code = ft_open_heredocs(head, env);
	if (code != 0)
		return (data->exit_code = code, ft_clean_tokens(&head, &free), code);
	data->node = ft_make_tree(head, NULL);
	if (!data->node)
		return (data->exit_code = 255, ft_clean_tokens(&head, &free), 255);
	return (0);
}
