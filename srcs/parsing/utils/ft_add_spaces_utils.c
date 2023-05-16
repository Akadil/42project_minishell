/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_spaces_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:42:57 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/16 16:15:23 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char    *ft_is_metacharacter(char c1, char c2)
{
    if (c1 == '|' && c2 == '|')
        return ("||");
    if (c1 == '|')
        return ("|"); 
    if (c1 == '&' && c2 == '&')
        return ("&&"); 
    if (c1 == '(')
        return ("("); 
    if (c1 == ')')
        return (")"); 
    if (c1 == '<' && c2 == '<')
        return ("<<");
    if (c1 == '<')
        return ("<"); 
    if (c1 == '>' && c2 == '>')
        return (">>");
    if (c1 == '>')
        return (">");
    return (NULL);
}

void    ft_put(char *string, int *j, int *i, char *meta)
{
    int size;

    size = 0;
    string[*j] = ' ';
    *j = *j + 1;
    while (meta && meta[size])
    {
        string[*j] = meta[size];
        *j = *j + 1;
        size++;
    }
    string[*j] = ' ';
    *j = *j + 1;
    if (size == 2)
        *i = *i + 1;
}

void    ft_remove_extra_spaces(char* str)
{
    int i;
    int j;
    int len;
    
    len = ft_strlen(str);
    i = 0;
    while (str[i] && str[i] == ' ')
        i++;
    ft_strlcpy(str, &str[i], len + 1);
    i = len - 1;
    while (i >= 0 && str[i] == ' ')
    {
        str[i] = '\0';
        i--;
    }
    i = 0;
    j = 0;
    while (i < len)
    {
        if (!(str[i] == ' ' && str[i + 1] == ' '))
            str[j++] = str[i];
        i++;
    }
    str[j] = '\0';
}

int     ft_size(char *str)
{
    int i;
    int size;

    i = 0;
    size = 0;
    while (str[i])
    {
        if (ft_is_metacharacter(str[i], str[i + 1]) != 0)
            size++;
        i++;
    }
    return (i + size * 2);
}

char    *ft_free(char *str)
{
    free (str);
    return (NULL);
}
