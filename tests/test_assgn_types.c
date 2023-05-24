/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_assgn_types.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:13:46 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/24 03:55:09 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include "struct_list.h"
#include "libft.h"

/*
    tester: 
            cc -g -I includes -Wall -Wextra -Werror tests/test_assgn_types.c srcs/parsing/ft_add_spaces.c srcs/parsing/ft_tokenization.c srcs/parsing/ft_assign_types.c -lreadline -Llibft -lft; ./a.out; rm a.out

    Possible tests:

            1. (cat|ls)&&pwd
            2. (cat|ls -la < Makefile > outfile.txt)&&pwd
            3. cat$b"$USER"'$HOME'
            
*/

t_list    *ft_tokenization(char *str, t_list *env);
void    print_tokens(t_list *token);
char    *ft_add_spaces(char *str);
void    ft_assign_types(t_list *node);

int main(void)
{
    char    *str;
    t_list  *head;
    t_list  *env_var;
    
    env_var = ft_lstnew("HOME=/my_home", 0);
    ft_lstadd_back(&env_var, ft_lstnew("USER=akalimol", 0));
    ft_lstadd_back(&env_var, ft_lstnew("a=z", 0));
    ft_lstadd_back(&env_var, ft_lstnew("b= ", 0));
    ft_lstadd_back(&env_var, ft_lstnew("c= -la", 0));
    ft_lstadd_back(&env_var, ft_lstnew("d=-la ", 0));
    ft_lstadd_back(&env_var, ft_lstnew("e=main.c error.c", 0));

    head = NULL;
    str = readline("Type the string: ");
    while (str)
    {
        write(1, &"--------------------------------------\n", 40);
        write(1, &"\n", 1);
        
        str = ft_add_spaces(str);

        head = ft_tokenization(str, env_var);
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