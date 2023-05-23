/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:30:59 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/23 18:48:28 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_data.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

/*
		Close all file descriptors if open
*/
void	ft_clean_fds(t_data *my_data)
{
	(void)my_data;
	printf("ft_clean_fds() is on construction :( \n");
}

/*
		Free my data
*/
void	ft_clean_data(t_data *my_data)
{
	(void)my_data;
    printf("ft_clean_data() is on construction :( \n");
}

/*
		Delete temporary created file for here_doc
*/
void	ft_clean_heredoc(t_data *my_data)
{
	(void)my_data;
	printf("ft_clean_heredoc() is on construction :( \n");
}

void	ft_clean_full(t_data *my_data)
{
	(void)my_data;
	printf("ft_clean_full() is on construction :( \n");
}

void	ft_clean_tokens(t_list **token, void (*del)(void*))
{
	ft_lstclear(token, del);
}

void	ft_clean_cmds(t_cmd	**cmds_p)
{
	t_cmd	*cmds;

	cmds = *cmds_p;
	ft_lstclear(&cmds->params, &free);
	ft_lstclear(&cmds->redir, &free);
	free (cmds);
}

void	ft_clean_tree(t_node *node)
{
	if (node->left)
		ft_clean_tree(node->left);
	if (node->right)
		ft_clean_tree(node->right);
	ft_lstclear(&node->elems, &free);
	if (node->cmds)
		ft_clean_cmds(&node->cmds);
	free (node);
}