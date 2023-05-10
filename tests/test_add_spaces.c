/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_add_spaces.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 00:59:57 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/11 01:24:29 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <readline/history.h>
#include <stdio.h>
#include <stdlib.h>

char    *ft_add_spaces(char *str);

int main(void)
{
    char *str;

    while (1)
    {   
        str = readline("Enter the string: ");
        if (!str)
            break ;
        if (!*str)
        {
            free(str);
            continue;
        }
        str = ft_add_spaces(str);
        printf("New string: %s\n", str);
        
        // str = readline("Enter the string: ");
        
    }

    return (0);
}