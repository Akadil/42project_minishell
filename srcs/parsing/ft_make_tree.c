/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:25:54 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/11 19:03:47 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "linked_list.h"
#include "data.h"
#include "libft.h"

int ft_isoperator(char *s)
{
    if (ft_strcmp(s, "&&") == 0)
        return (1);
    if (ft_strcmp(s, "||") == 0)
        return (1);
    if (ft_strcmp(s, "|") == 0)
        return (1);
}

t_node  *ft_treenode_new(t_list *token, t_node *parent)
{
    t_node  *node;

    node = (t_node *)malloc(sizeof(t_node));
    if (!node)
        printf("handle, but it is going to be really hard!");
    node->elems = token;
    node->in_fd = 0;
    node->out_fd = 1;
    node->parent = parent;
    node->left = NULL;
    node->right = NULL;
    node->exit_code = 0;
}

t_node  *ft_make_tree(t_list *token, t_node *parent)
{
    t_node  *node;
    t_list  *left;
    t_list  *right;

    left = NULL;
    right = NULL;
    while (token && ft_isoperator(token->content) == 0)
    {
        if (ft_strcmp(token->content, "(") == 0)
        {
            token = token->next;
            while (ft_strcmp(token->content, ")") != 0)
            {
                ft_lstadd_back(&left, ft_lstnew(token->content, token->type));
                token = token->next;
            }
        }
        else
            ft_lstadd_back(&left, ft_lstnew(token->content, token->type));
        token = token->next;
    }
    if (ft_lstsize(left) == ft_lstsize(token))
    {
        node = ft_treenode_new(left, parent);
        return (node);
    }
    node = ft_treenode_new(ft_lstnew(token->content, token->type), parent);

    node->left = ft_make_tree(left, node);
    node->right = ft_make_tree(token->next, node);
    return (node);
}