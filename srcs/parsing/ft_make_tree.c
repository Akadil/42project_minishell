/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:25:54 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/18 17:25:05 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "struct_list.h"
#include "struct_data.h"
#include "libft.h"

int ft_isoperator(char *s)
{
    if (ft_strcmp(s, "&&") == 0)
        return (1);
    if (ft_strcmp(s, "||") == 0)
        return (1);
    return (0);
}

/*
    Before adding the:
        node->elems = token;
    i have to remove all onion layers
*/
t_node  *ft_treenode_new(t_list *token, t_node *parent, int type)
{
    t_node  *node;

    node = (t_node *)malloc(sizeof(t_node));
    if (!node)
        return (NULL);                                              // handle this case
    node->elems = token;
    node->parent = parent;
    node->left = NULL;
    node->right = NULL;
    node->type = type;
    if (!parent)
        node->is_micro = 0;
    else
        node->is_micro = parent->is_micro + 1;
    return (node);
}

/*
    ret: 1 means cleaned, 0 means no
    int ft_clean_onion()
*/

int ft_clean_onion(t_list **token)
{
    t_list  *last;
    t_list  *first;
    int     res;

    res = 0;
    first = *token;
    last = ft_lstlast(*token);
    while (last->type == 5 && first->type == 4)
    {
        res++;
        last->prev->next = NULL;
        free(last);
        last = ft_lstlast(*token);
        *token = (*token)->next;
        free(first);
        first = *token;
        first->prev = NULL;
    }
    return (res);
}

int ft_is_same_node(t_list  *node_1, t_list *node_2)
{
    t_list  *last;
    t_list  *first;
    int     node_2_size;
    int     node_1_size;

    node_1_size = ft_lstsize(node_1);
    node_2_size = ft_lstsize(node_2);
    first = node_2;
    last = ft_lstlast(node_2);
    while (last->type == 5 && first->type == 4)
    {
        last->prev->next = NULL;
        last = ft_lstlast(node_2);
        node_2 = node_2->next;
        first = node_2;
        first->prev = NULL;
        node_2_size = node_2_size - 2;
    }
    if (node_2_size == node_1_size)
        return (1);
    return (0);
}

t_list  *ft_retrieve_left_tokens(t_list **token)
{
    t_list  *left;
    t_list  *temp;
    int     p_count;

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
                if ((*token)->type == 4)
                    p_count++;
                if ((*token)->type == 5)
                    p_count--;
                *token = (*token)->next;
            }
        }
        *token = (*token)->next;
    }
    if (*token)
    {
        temp = (*token)->prev;
        temp->next = NULL;
        (*token)->prev = NULL;
    }
    return (left);
}

/*
    Here, I have to add a point, where I am saying if the left or right side is the whole

    Also, the whole is not working!
*/
t_node  *ft_make_tree(t_list *token, t_node *parent)
{
    t_node  *node;
    t_list  *left;
    t_list  *right;

    ft_clean_onion(&token);
    left = ft_retrieve_left_tokens(&token);
    if (!token)
        return (ft_treenode_new(left, parent, 0));
    right = token->next;
    right->prev = NULL;
    token->next = NULL;
    node = ft_treenode_new(token, parent, 1);
    node->left = ft_make_tree(left, node);
    node->right = ft_make_tree(right, node);
    return (node);
}


