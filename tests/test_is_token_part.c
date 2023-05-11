/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_is_token_part.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 21:13:55 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/05 23:28:32 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

/*
    to check:       cc -g -Wall -Wextra -Werror test_is_token_part.c ../../srcs/parsing/ft_split_alt.c -lreadline && ./a.out && rm a.out
*/

int is_token_part(char c);

int main(void)
{
    int i;
    char *str;

    str = readline("Type the string: ");

    while (str)
    {
        write(1, &"--------------------------------------\n", 40);
        write(1, &"\n", 1);
        i = 0;
        while (str[i])
        {
            if (is_token_part(str[i]) == 1)
                write(1, &str[i], 1);
            else
                write(1, &"---", 3);
            i++;
        }
        write(1, &"\n\n\n", 3);
        str = readline("Type the string: ");
        
    }
    return (0);
}