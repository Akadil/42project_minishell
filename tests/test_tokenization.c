/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tokenization.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:11:39 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/10 21:54:51 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include "linked_list.h"

/*
    Tester: cc -g -I includes -Wall -Wextra -Werror tests/test_tokenization.c srcs/parsing/ft_tokenization.c -lreadline -Llibft -lft; ./a.out; rm a.out 
*/

t_list    *ft_tokenization(char *str);
void    print_tokens(t_list *token);

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
        
        head = ft_tokenization(str);
        print_tokens(head);
        
        write(1, &"\n\n", 3);
        str = readline("Type the string: ");
        
    }

    return (0);
}

void    print_tokens(t_list *token)
{
    while (token)
    {
        printf("%s\n", (char *)token->content);
        token = token->next;
    }
}