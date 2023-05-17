/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_split_alt_general.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 22:03:40 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/05 23:34:14 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

/*
    to check:       cc -g -Wall -Wextra -Werror test_split_alt_general.c ../../srcs/parsing/ft_split_alt.c -lreadline
*/

void    ft_split_alt(char *s);

int main(void)
{
    char *str;

    str = readline("Type the string: ");

    while (str)
    {
        write(1, &"--------------------------------------\n", 40);
        write(1, &"\n", 1);
        
        ft_split_alt(str);

        write(1, &"\n\n", 3);
        str = readline("Type the string: ");
        
    }
    return (0);
}

void    ft_add_word_draft(char *str, int end, int beg)
{
    char *s;
    int i;

    s = (char *)malloc(sizeof(char) * (end - beg + 1));

    i = 0;
    while (i < end - beg)
    {
        s[i] = str[beg + i];
        i++;
    }
    s[i] = '\0';
    printf("%s\n", s);
}