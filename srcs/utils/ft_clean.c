/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:30:59 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/28 19:02:07 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_data.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

/*
		Close all file descriptors if open

		Add condition that if it is 0, 1, then skip
*/
void	ft_clean_fds(t_cmd *cmd)
{
	if (cmd->in_fd != -1 && cmd->in_fd != 0)
		close(cmd->in_fd);
	if (cmd->out_fd != -1 && cmd->out_fd != 1)
		close(cmd->out_fd);
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
	if (cmds->params)
		ft_lstclear(&cmds->params, &free);
	if (cmds->redir)
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

void	ft_clean_darray(char **trash)
{
	int	i;

	i = 0;
	while (trash[i])
	{
		free (trash[i]);
		i++;
	}
	free (trash);
}

void	ft_clean_env(t_list *env)
{
	ft_lstclear_safe(&env, &free);
}