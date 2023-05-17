/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tokenization.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:11:39 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/17 17:34:52 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include "struct_list.h"

/*
    tester:     make test_tokenization
      
*/

t_list    *ft_tokenization(char *str);
void    print_tokens(t_list *token);
char    *ft_add_spaces(char *str);

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
        printf("%s\n", (char *)token->content);
        token = token->next;
    }
}