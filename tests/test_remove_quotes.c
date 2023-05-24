/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_remove_quotes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 04:38:00 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/24 04:41:59 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

/*
    Test the char string
*/

void ft_char_string(char *str)
{
    char    mode;
    int     i;
    int     j;

    i = 0;
    j = 0;
    mode = '\0';
    while (str[i])
    {
        if (mode == '\0' && str[i] == '\'')
            mode = 's';
        else if (mode == 's' && str[i] == '\'')
            mode = '\0';
        else if (mode == '\0' && str[i] == '\"')
            mode = 'd';
        else if (mode == 'd' && str[i] == '\"')
            mode = '\0';
        else
            str[j++] = str[i];
        i++;
    }
    while (j != i)
        str[j++] = '\0';
}

int main(void)
{
    char *str;

    str = strdup("\"Ak'ad'il\" 'Kaliolda\"yev'");

    printf("Before: %s\n", str);
    ft_char_string(str);
    printf("After: %s\n", str);
    return (0);
}