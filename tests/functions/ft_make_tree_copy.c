/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:25:54 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/18 17:09:31 by akalimol         ###   ########.fr       */
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
    node->is_micro = 0;
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

/*
    Here, I have to add a point, where I am saying if the left or right side is the whole

    Also, the whole is not working!
*/
t_node  *ft_make_tree(t_list *token, t_node *parent)
{
    t_node  *node;
    t_list  *left;
    t_list  *right;
    t_list  *temp;
    int     p_count;

    left = NULL;
    right = NULL;
    ft_clean_onion(&token);

    temp = token;
    p_count = 0;
    while (temp && ft_isoperator(temp->content) == 0)
    {
        if (ft_strcmp(temp->content, "(") == 0)
        {
            ft_lstadd_back(&left, ft_lstnew(temp->content, temp->type));
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
            ft_lstadd_back(&left, ft_lstnew(temp->content, temp->type));
        }
        else
            ft_lstadd_back(&left, ft_lstnew(temp->content, temp->type));
        temp = temp->next;
    }
    ft_clean_onion(&left);
    // The next step inside of the if statement I have to call another function
    // to compare the length, my kostil is not working
    // if (ft_lstsize(left) == ft_lstsize(token) - p_count * 2)
    if (ft_is_same_node(left, token) == 1)
    {
        node = ft_treenode_new(left, parent);
        node->type = 0;
        return (node);
    }
    node = ft_treenode_new(ft_lstnew(temp->content, temp->type), parent);
    node->type = 1;
    node->left = ft_make_tree(left, node);
    // here I have to clean the right side too
    // If it was cleaned, then set the value of the whole to 1
    node->right = ft_make_tree(temp->next, node);
    return (node);
}
