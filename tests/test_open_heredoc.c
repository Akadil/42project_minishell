/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_open_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 05:14:50 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/24 17:36:20 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_list.h"
#include "libft.h"
#include <stdio.h>

/*
    Test:
            cc -g3 -I includes -Wall -Werror -Wextra tests/test_open_heredoc.c srcs/parsing/ft_open_heredocs.c srcs/execution/expansion/ft_expand_string.c srcs/execution/expansion/utils/ft_expand_string_utils.c srcs/execution/expansion/utils/ft_expand_string_utils_2.c srcs/parsing/tokenization/ft_remove_quotes.c srcs/utils/ft_clean.c srcs/utils/ft_error_1.c srcs/utils/ft_error_2.c  -Llibft -lft -lreadline

    Result:
        1. Perfectly working. But not integrated the ft_expand of the string
*/

int ft_open_heredocs(t_list *head, t_list *env);

int main(void)
{
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
    ft_lstadd_back(&head, ft_lstnew(ft_strdup("EOF"), 8));
    ft_lstadd_back(&head, ft_lstnew(ft_strdup("Finir"), 8));

    ft_open_heredocs(head, env_var);

    char    *str;

    printf("------------------- Print ------------------\n");
    str = get_next_line(*((int *)head->content), 0);
    while (str)
    {
        printf("%s\n", str);
        str = get_next_line(*((int *)head->content), 0);
    }

    str = get_next_line(*((int *)head->next->content), 0);
    while (str)
    {
        printf("%s\n", str);
        str = get_next_line(*((int *)head->next->content), 0);
    }

    return (0);
}