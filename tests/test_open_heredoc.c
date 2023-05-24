/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_open_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 05:14:50 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/24 17:18:53 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_list.h"
#include "libft.h"
#include <stdio.h>

/*
    Test:
        cc -g3 -I includes -Wall -Werror -Wextra tests/test_open_heredoc.c srcs/parsing/ft_open_heredocs.c srcs/utils/ft_clean.c srcs/utils/ft_error_1.c srcs/utils/ft_error_2.c  -Llibft -lft -lreadline

    Result:
        1. Perfectly working. But not integrated the ft_expand of the string
*/

int ft_open_heredocs(t_list *head);

int main(void)
{
    t_list  *head;

    head = NULL;
    ft_lstadd_back(&head, ft_lstnew(ft_strdup("EOF"), 8));
    ft_lstadd_back(&head, ft_lstnew(ft_strdup("Finir"), 8));

    ft_open_heredocs(head);

    return (0);
}