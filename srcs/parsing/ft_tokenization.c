/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenization.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:49:06 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/16 17:03:11 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "includes/ft_tokenization.h"

t_list    *ft_tokenization(char *str)
{
    t_list  *token;
    int     i_beg;
    int     i_end;
    int     result;

    i_beg = 0;
    i_end = 0;
    token = NULL;
    while (str[i_beg])
    {
        i_end = i_beg;
        while (str[i_end] && ft_is_token(str[i_end], 0))
            i_end++;
        result = ft_add_token(&token, str, i_beg, i_end);
        if (result == 0)
            return (ft_token_error(token));
        i_beg = i_end + 1;
    }
    if (ft_is_token(0, 1) == 0)
        return (ft_token_perror("BASH: unclosed quotes", token));
    return (token);
}