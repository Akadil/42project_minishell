/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:25:54 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/20 19:39:30 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "struct_list.h"
#include "struct_data.h"
#include "libft.h"
#include "ft_error.h"

t_list  *ft_find_next_parenthesis(t_list *first)
{
    t_list  *next_p;
    int     count_p;

    count_p = 1;
    next_p = first->next;
    while (next_p)
    {
        if (next_p->type == RIGHT_P && count_p == 1)
            break;
        if (next_p->type == RIGHT_P)
            count_p--;
        if (next_p->type == LEFT_P)
            count_p++;
        next_p = next_p->next;
    }
    return (next_p);
}

/*
    ret: 1 means cleaned, 0 means no
    int ft_clean_onion()
*/
int ft_clean_onion(t_list **token)
{
    t_list  *first;
    t_list  *i_token;
    int     res;

    first = *token;
    res = 0;
    while (first->type == LEFT_P)
    {
        i_token = ft_find_next_parenthesis(first);
        if (!i_token->next)
        {
            res = 1;
            i_token->prev->next = NULL;
            free(i_token);
            *token = (*token)->next;
            free(first);
            first = *token;
            first->prev = NULL;
        }
        else
            break;
    }
    return (res);
}

/*
    Before adding the:
        node->elems = token;
    i have to remove all onion layers
*/
t_node  *ft_treenode_new(t_list *token, t_node *parent, int type)
{
    t_node  *node;
    int     is_micro;

    node = (t_node *)malloc(sizeof(t_node));
    if (!node)
        return (NULL);                                              // handle this case
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
                if ((*token)->type == LEFT_P)
                    p_count++;
                if ((*token)->type == RIGHT_P)
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
    int     is_micro;

    is_micro = ft_clean_onion(&token);
    left = ft_retrieve_left_tokens(&token);
    if (!token)
        return (ft_treenode_new(left, parent, 0));      // Skip this malloc
    right = token->next;
    right->prev = NULL;
    token->next = NULL;
    node = ft_treenode_new(token, parent, 1);           // return NULL? without any steps
    if (!node)
        return (NULL);
    if (!parent)
        node->is_micro = 0;
    else if (is_micro == 1)
        node->is_micro = parent->is_micro + 1;
    else
        node->is_micro = parent->is_micro;
    node->left = ft_make_tree(left, node);              // 
    if (!node->left)
    {
        ft_clean_tree(node);
        return (NULL);
    }
    node->right = ft_make_tree(right, node);
    if (!node->right)
    {
        ft_clean_tree(node);
        return (NULL);
    }
    return (node);
}


