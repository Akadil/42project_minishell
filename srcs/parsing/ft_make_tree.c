/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:25:54 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/12 17:07:08 by akalimol         ###   ########.fr       */
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
    return (0);
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
    return (node);
}

t_node  *ft_make_tree(t_list *token, t_node *parent)
{
    t_node  *node;
    t_list  *left;
    t_list  *right;
    t_list  *temp;
    int     p_count;

    left = NULL;
    right = NULL;
    temp = token;
    p_count = 0;
    while (temp && ft_isoperator(temp->content) == 0)
    {
        if (ft_strcmp(temp->content, "(") == 0)
        {
            p_count = 1;
            temp = temp->next;
            while (ft_strcmp(temp->content, ")") != 0 || p_count != 1)
            {
                if (ft_strcmp(temp->content, "(") == 0)
                    p_count++;
                if (ft_strcmp(temp->content, ")") == 0)
                    p_count--;
                ft_lstadd_back(&left, ft_lstnew(temp->content, temp->type));
                temp = temp->next;
            }
        }
        else
            ft_lstadd_back(&left, ft_lstnew(temp->content, temp->type));
        temp = temp->next;
    }
    if (ft_lstsize(left) == ft_lstsize(token) - p_count * 2)
    {
        node = ft_treenode_new(left, parent);
        return (node);
    }
    node = ft_treenode_new(ft_lstnew(temp->content, temp->type), parent);

    node->left = ft_make_tree(left, node);
    node->right = ft_make_tree(temp->next, node);
    return (node);
}