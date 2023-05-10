/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenization_copy.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:49:06 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/10 23:52:34 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int     ft_isspace(char c)
{
    if (c == ' ' || c == '\f' || c == '\n')
        return (1);
    if (c == '\r' || c == '\t' || c == '\v')
        return (1);
    return (0);
}

int     ft_istoken(char c, int checker)
{
    static char mode;

    if (checker == 1)
    {
        if (mode == 0)
            return (1);
        mode = 0;
        return (0);
    }
    if (mode == 'd' || (c == '\"' && mode == 0))
    {
        if (mode == 0)
            mode = 'd';
        else if (c == '\"')
            mode = 0;
        return (1);
    }
    if (mode == 's' || (c == '\'' && mode == 0))
    {
        if (mode == 0)
            mode = 's';
        else if (c == '\'')
            mode = 0;
        return (1);
    }
    if (c == '|' || c == '&' || c == '(' || c == ')')
        return (0);
    if (c == '<' || c == '>')
        return (0);
    if (c == ' ' || c == '\f' || c == '\n')
        return (0);
    if (c == '\r' || c == '\t' || c == '\v')
        return (0);
    return (1);
}

void    ft_addword(t_list **head, char *str, int i_beg, int i_end)
{
    char    *new_str;
    t_list  *node;
    int     i;

    if (i_beg == i_end && str[i_beg] == '|')
    {
        node = ft_lstlast(*head);
        if (node && ft_strcmp((char *)(node->content), "|") == 0)
        {
            new_str = (char *)malloc(sizeof(char) * (3));
            if (!new_str)
                printf("Error! free damn everything. return 0, and in the main add if condition");
            new_str[0] = '|';
            new_str[1] = '|';
            new_str[2] = '\0';
            free (node->content);
            node->content = new_str;
            return ;
        }
    }
    if (i_beg == i_end && str[i_beg] == '&')
    {
        node = ft_lstlast(*head);
        if (node && ft_strcmp((char *)(node->content), "&") == 0)
        {
            new_str = (char *)malloc(sizeof(char) * (3));
            if (!new_str)
                printf("Error! free damn everything. return 0, and in the main add if condition");
            new_str[0] = '&';
            new_str[1] = '&';
            new_str[2] = '\0';
            free (node->content);
            node->content = new_str;
            return ;
        }
    }
    if (i_beg == i_end && str[i_beg] == '<')
    {
        node = ft_lstlast(*head);
        if (node && ft_strcmp((char *)(node->content), "<") == 0)
        {
            new_str = (char *)malloc(sizeof(char) * (3));
            if (!new_str)
                printf("Error! free damn everything. return 0, and in the main add if condition");
            new_str[0] = '<';
            new_str[1] = '<';
            new_str[2] = '\0';
            free (node->content);
            node->content = new_str;
            return ;
        }
    }
    if (i_beg == i_end && str[i_beg] == '>')
    {
        node = ft_lstlast(*head);
        if (node && ft_strcmp((char *)(node->content), ">") == 0)
        {
            new_str = (char *)malloc(sizeof(char) * (3));
            if (!new_str)
                printf("Error! free damn everything. return 0, and in the main add if condition");
            new_str[0] = '>';
            new_str[1] = '>';
            new_str[2] = '\0';
            free (node->content);
            node->content = new_str;
            return ;
        }
    }
    if (i_beg == i_end)
        i_end++;
    new_str = (char *)malloc(sizeof(char) * (i_end - i_beg + 1));
    if (!new_str)
        printf("Error! free damn everything. return 0, and in the main add if condition");
    i = 0;
    while (i < i_end - i_beg)
    {
        new_str[i] = str[i + i_beg];
        i++;
    }
    new_str[i] = '\0';
    node = ft_lstnew(new_str, 0);
    if (!node)
        printf("Error! free the str, and all previous ones");
    ft_lstadd_back(head, node);
}

/*
    I have to merge 2 functions

    Because now "cat|ls" is not working
*/

t_list    *ft_tokenization(char *str)
{
    t_list  *head;
    int     i_beg;
    int     i_end;

    i_beg = 0;
    head = NULL;
    while (str[i_beg])
    {
        if (ft_isspace(str[i_beg]) == 1)
        {
            i_beg++;
            continue;
        }
        i_end = i_beg;
        while (str[i_end] && str[i_end] && ft_istoken(str[i_end], 0))
            i_end++;
        ft_addword(&head, str, i_beg, i_end);
        i_beg = i_end + 1;
    }
    if (ft_istoken(0, 1) == 0)
        printf("Error, syntax error. unclosed quotes");
    return (head);
}