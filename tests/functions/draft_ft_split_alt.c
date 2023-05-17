/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draft_ft_split_alt.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:58:23 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/11 15:28:06 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "linked_list.h"

int is_token_part_spec(char  *mode, char c)
{
    if (*mode == 0)
    {
        if (c == '\"')
            *mode = 'd';
        else
            *mode = 's';
    }
    else if (*mode == 'd')
    {
        if (c == '\"')
            *mode = 0;
    }
    else
    {
        if (c == '\'')
            *mode = 0;
    }
    return (1);
}

int is_token_part(char c, int check_mode)
{
    static char  mode;

    if (check_mode == 1)
        return(mode = 0);
    if (mode == 'd' || (c == '\"' && mode == 0))
        return (is_token_part_spec(&mode, c));
    if (mode == 's' || (c == '\'' && mode == 0))
        return (is_token_part_spec(&mode, c));
    if (c == '('  || c ==  ')')
        return (0);
    if (c == '|' || c == '&')
        return (0);
    if (c == ' ' || c == '\f' || c == '\n')
        return (0);
    if (c == '\r' || c == '\t' || c == '\v')
        return (0);
    return (1);
}

void    ft_add_word(t_list **head, char *str, int beg, int end)
{
    t_list  *node;
    t_list  *temp;
    char        *content;
    int         i;

    if (beg == end && str[beg] == '|')
    {
        node = ft_lstlast(*head);
    }

    content = (char *)malloc(sizeof(char) * (end - beg + 1));
    if (!content)
        printf("Error! improve");
    i = 0;
    while (i < end - beg)
    {
        content[i] = str[i + beg];
        i++;
    }

}

/*
    Description:    The lexical analyzer or tokenization.
                    Here firstly, I will divide the string to tokens, and
                    secondly, give each of them some type

*/
t_list  *ft_tokenization(char *s)
{
    t_list  *head;
    int i_beg;
    int i_end;

    head = NULL;
    i_beg = 0;
    while (s[i_beg])
    {
        i_end = i_beg;
        while (s[i_end] && is_token_part(s[i_end], 0))
            i_end++;
        ft_add_word(&head, s, i_beg, i_end);
        i_beg = i_end + 1;
    }
    if (is_token_part(0, 1) != 0)
        printf("Error! improve!");
    return (head);
}
