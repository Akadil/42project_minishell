/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_echo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 23:21:31 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/29 00:45:24 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_list.h"
#include "libft.h"

void    ft_execute_echo(t_list *token)
{
    int     is_n;

    is_n = 0;
    if (token && ft_strcmp((char *)token->content, "-n") == 0)
    {
        is_n = 1;
        token = token->next;
    }
    while (token)
    {   
        ft_printf("%s", (char *)token->content);
        if (token->next)
            ft_printf(" ");
        token = token->next;
    }
    if (is_n == 0)
        ft_printf("\n");
}