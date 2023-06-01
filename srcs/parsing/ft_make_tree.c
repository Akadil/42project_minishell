/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:25:54 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/01 18:44:54 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"
#include "libft.h"
#include "struct_data.h"
#include "struct_list.h"
#include <stdio.h>

t_list	*ft_find_next_parenthesis(t_list *first);
int		ft_clean_onion(t_list **token);

/*
    Before adding the:
        node->elems = token;
    i have to remove all onion layers
*/
t_node	*ft_treenode_new(t_list *token, t_node *parent, int type)
{
	t_node	*node;
	int		is_micro;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	is_micro = ft_clean_onion(&token);
	if (!parent)
		node->is_micro = 0;
	else if (is_micro == 1)
		node->is_micro = parent->is_micro + 1;
	else
		node->is_micro = parent->is_micro;
	node->elems = token;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
	node->type = type;
	node->cmds = NULL;
	node->count_cmd = 0;
	node->exit_code = 0;
	return (node);
}

void	ft_cut_token(t_list *token)
{
	t_list	*temp;

	if (token)
	{
		temp = token->prev;
		if (temp)
			temp->next = NULL;
		token->prev = NULL;
	}
}

t_list	*ft_retrieve_left_tokens(t_list **token)
{
	t_list	*left;
	int		p_count;

	p_count = 0;
	left = *token;
	while (*token && (*token)->type != 2 && (*token)->type != 3)
	{
		if ((*token)->type == 4)
		{
			p_count = 1;
			*token = (*token)->next;
			while ((*token)->type != 5 || p_count != 1)
			{
				if ((*token)->type == LEFT_P)
					p_count++;
				if ((*token)->type == RIGHT_P)
					p_count--;
				*token = (*token)->next;
			}
		}
		*token = (*token)->next;
	}
	ft_cut_token(*token);
	return (left);
}

t_list	*ft_retrieve_right_tokens(t_list **token)
{
	t_list	*right;

	if (!(*token))
		return (NULL);
	right = (*token)->next;
	if (right)
		right->prev = NULL;
	(*token)->next = NULL;
	return (right);
}

/*
    Here, I have to add a point,
	where I am saying if the left or right side is the whole

    Also, the whole is not working!
*/
t_node	*ft_make_tree(t_list *token, t_node *parent)
{
	t_node	*node;
	t_list	*left;
	t_list	*right;
	int		is_micro;

	is_micro = ft_clean_onion(&token);
	left = ft_retrieve_left_tokens(&token);
	if (!token)
		return (ft_treenode_new(left, parent, 0));
	right = ft_retrieve_right_tokens(&token);
	node = ft_treenode_new(token, parent, 1);
	if (!node)
		return (NULL);
	if (!parent)
		node->is_micro = 0;
	else
		node->is_micro = parent->is_micro + is_micro;
	node->left = ft_make_tree(left, node);
	if (!node->left)
		return (ft_clean_tree(node), NULL);
	node->right = ft_make_tree(right, node);
	if (!node->right)
		return (ft_clean_tree(node), NULL);
	return (node);
}
