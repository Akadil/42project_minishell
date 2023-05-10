/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draft_ft_split_alt.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akadilkalimoldayev <akadilkalimoldayev@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:58:23 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/06 17:06:58 by akadilkalim      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

typedef struct s_list_alt
{
    char                *content;
    int                 type;
    struct s_list_alt   *next;
}                       t_list_alt;

int is_token_part_spec(char  *mode, char c)
{
    static  int p_counter;

    if (*mode == 0)
    {
        if (c == '\"')
            *mode = 'd';
        else if (c == '\'')
            *mode = 's';
        else
        {
            p_counter++;
            *mode = 'p';
        }
    }
    else if (*mode == 'd')
    {
        if (c == '\"')
            *mode = 0;
    }
    else if (*mode == 's')
    {
        if (c == '\'')
            *mode = 0;
    }
    else
    {
        if (c == '(')
            p_counter++;
        else if(c == ')')
        {
            p_counter--;
            if (p_counter == 0)
                *mode = 0;
        }
    }
    return (1);
}

int is_token_part(char c, int check_mode)
{
    static char  mode;

    if (check_mode == 1)
        return(mode);
    if (mode == 'd' || (c == '\"' && mode == 0))
        return (is_token_part_spec(&mode, c));
    if (mode == 's' || (c == '\'' && mode == 0))
        return (is_token_part_spec(&mode, c));
    if (mode == 'p' || (c == '(' && mode == 0))
        return (is_token_part_spec(&mode, c));
    if (c == ' ' || c == '\f' || c == '\n')
        return (0);
    if (c == '\r' || c == '\t' || c == '\v')
        return (0);
    return (1);
}

void    ft_add_word(t_list_alt **head, char *str, int beg, int end)
{
    t_list_alt  *node;
    t_list_alt  *temp;
    char        *content;
    int         i;

    node = (t_list_alt *)malloc(sizeof(t_list_alt));
    if (!node)
        printf("Error ! remove");
    content = (char *)malloc(sizeof(char) * (end - beg + 1));
    if (!content)
        printf("Error! improve");
    i = 0;
    while (i < end - beg)
    {
        content[i] = str[i + beg];
        i++;
    }
    content[i] = '\0';
    node->content = content;
    node->type = -1;
    node->next = NULL;
    if (*head == NULL)
        *head = node;
    else
    {
        temp = *head;
        while (temp->next)
            temp = temp->next;
        temp->next = node;
    }
}

/*
    Description:
        Same as ft_split, but 
            1. separates into new structure, not char *
            2. Separates not only by spaces, but 
                a) double quotes
                b) single quotes
                c) parenthesis

    Status:
        1. Checked, working
        2. have unprotected mallocs
        3. Unclosed quotes not handled

    Further:
        1. Derivate the functions
        2. Make an expansion
        3. Remove the quotes

*/
t_list_alt  *ft_split_alt(char *s)
{
    t_list_alt  *head;
    int i_beg;
    int i_end;

    head = NULL;
    i_beg = 0;
    while (s[i_beg])
    {
        i_end = i_beg;
        while (s[i_end] && is_token_part(s[i_end], 0))
            i_end++;
        if (i_beg != i_end)
            ft_add_word(&head, s, i_beg, i_end);
        i_beg = i_end + 1;
    }
    if (is_token_part(0, 1) != 0)
        printf("Error! improve!");
    return (head);
}
