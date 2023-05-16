/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_add_spaces.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 00:59:57 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/16 16:05:06 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <readline/history.h>
#include <stdio.h>
#include <stdlib.h>

/*
    File location:  srcs/parsing/ft_add_spaces.c

    Possible tests:
            - < Makefile ( cat | ls )
            - (cat|ls)

    Tester:         make test_add_spaces
    Debuger:        make debug_add_spaces
*/

char    *ft_add_spaces(char *str);

int main(void)
{
    char *str;

    while (1)
    {   
        str = readline("Enter the string: ");
        printf("\n");
        if (!str)
            break ;
        if (!*str)
        {
            free(str);
            continue;
        }
        str = ft_add_spaces(str);
        printf("New string: %s\nFirst char: %c\n\n", str, str[0]);
        
        // str = readline("Enter the string: ");
        
    }

    return (0);
}