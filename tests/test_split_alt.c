/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_split_alt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 23:15:38 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/05 23:32:18 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

/*
    This checker is for srcs/parsing/ft_split_alt.c

    to check:
                cc -g -Wall -Wextra -Werror test_split_alt.c ../srcs/parsing/ft_split_alt.c -lreadline && ./a.out && rm a.out
*/

/* ------------------------------------------------------------------------- */
/*                               Header names                                */
/* ------------------------------------------------------------------------- */

typedef struct s_list_alt
{
    char                *content;
    int                 type;
    struct s_list_alt   *next;
}                       t_list_alt;

t_list_alt    *ft_split_alt(char *s);
void    print_tokens(t_list_alt *token);


/* ------------------------------------------------------------------------- */
/*                               Tester                                      */
/* ------------------------------------------------------------------------- */
int main(void)
{
    t_list_alt  *tokens;
    char *str;

    str = readline("Type the string: ");

    while (str)
    {
        write(1, &"--------------------------------------\n", 40);
        write(1, &"\n", 1);
        
        tokens = ft_split_alt(str);
        print_tokens(tokens);

        write(1, &"\n\n", 3);
        str = readline("Type the string: ");
        
    }
    return (0);
}


/* ------------------------------------------------------------------------- */
/*                               Helper functions                            */
/* ------------------------------------------------------------------------- */
void    print_tokens(t_list_alt *token)
{
    while (token)
    {
        printf("%s\n", token->content);
        token = token->next;
    }
}