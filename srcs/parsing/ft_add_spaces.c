/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_spaces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 00:12:17 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/11 01:24:59 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char    *ft_add_spaces(char *str)
{
    char    *string;
    int     i;
    int     size;
    int     j;

    i = 0;
    size = 0;
    while (str[i])
    {
        if (str[i] == '|' || str[i] == '&' || str[i] == '(' || str[i] == ')' || str[i] == '<' || str[i] == '>')
            size++;
        i++;
    }
    string = (char *)malloc(sizeof(char) * (i + size * 2 + 1));
    i = 0;
    j = 0;
    while (str[i])
    {
        if (str[i] == ' ' || str[i] == '\f' || str[i] == '\n')
            string[i] = ' ';
        else if (str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
            string[i] = ' ';
        else if (str[i] == '|' && str[i + 1] == '|')
        {
            string[j++] = ' ';
            string[j++] = '|';
            string[j++] = '|';
            string[j++] = ' ';
            i++;
        }
        else if (str[i] == '|' && str[i + 1] != '|')
        {
            string[j++] = ' ';
            string[j++] = '|';
            string[j++] = ' ';
        }
        else if (str[i] == '<' && str[i + 1] == '<')
        {
            string[j++] = ' ';
            string[j++] = '<';
            string[j++] = '<';
            string[j++] = ' ';
            i++;
        }
        else if (str[i] == '<')
        {
            string[j++] = ' ';
            string[j++] = '<';
            string[j++] = ' ';
        }
        else if (str[i] == '>' && str[i + 1] == '>')
        {
            string[j++] = ' ';
            string[j++] = '>';
            string[j++] = '>';
            string[j++] = ' ';
            i++;
        }
        else if (str[i] == '>')
        {
            string[j++] = ' ';
            string[j++] = '>';
            string[j++] = ' ';
        }
        else if (str[i] == '&' && str[i + 1] == '&')
        {
            string[j++] = ' ';
            string[j++] = '&';
            string[j++] = '&';
            string[j++] = ' ';
            i++;
        }
        else if (str[i] == '(')
        {
            string[j++] = ' ';
            string[j++] = '(';
            string[j++] = ' ';
        }
        else if (str[i] == ')')
        {
            string[j++] = ' ';
            string[j++] = ')';
            string[j++] = ' ';
        }
        else
            string[j++] = str[i];
        i++;
    }
    string[j] = '\0';
    i = 0;
    j = 0;
    while (string[i])
    {
        if (string[i] == ' ' && i != 0 && string[j - 1] == ' ')
            continue;
        else
            string[j++] = string[i];
        i++;
    }
    return (string);
}