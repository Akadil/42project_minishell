/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_assgn_types.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:13:46 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/15 14:26:30 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include "linked_list.h"

/*
    tester: 
            cc -g -I includes -Wall -Wextra -Werror tests/test_assgn_types.c srcs/parsing/ft_add_spaces.c srcs/parsing/ft_tokenization.c srcs/parsing/ft_assign_types.c -lreadline -Llibft -lft; ./a.out; rm a.out

    Possible tests:

            1. (cat|ls)&&pwd
            2. (cat|ls -la < Makefile > outfile.txt)&&pwd
            
*/

t_list    *ft_tokenization(char *str);
void    print_tokens(t_list *token);
char    *ft_add_spaces(char *str);
void    ft_assign_types(t_list *node);

int main(void)
{
    char    *str;
    t_list  *head;

    head = NULL;
    str = readline("Type the string: ");
    while (str)
    {
        write(1, &"--------------------------------------\n", 40);
        write(1, &"\n", 1);
        
        str = ft_add_spaces(str);

        head = ft_tokenization(str);
        ft_assign_types(head);
        print_tokens(head);
        
        write(1, &"\n", 1);
        str = readline("Type the string: ");
        
    }

    return (0);
}

void    print_tokens(t_list *token)
{
    while (token)
    {
        printf("%s -> %d\n", (char *)token->content, token->type);
        token = token->next;
    }
}