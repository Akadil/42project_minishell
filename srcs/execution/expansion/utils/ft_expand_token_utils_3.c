/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_token_utils_3.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:09:54 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/23 16:10:14 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int  ft_skip(char const *str, int i, char c)
{
    if (c == '\'')
    {
        i++;
        while (str[i] && str[i] != '\'')
            i++;
        if (str[i] == '\'')
            i++;
    }
    else if (c == '\"')
    {
        i++;
        while (str[i] && str[i] != '\"')
            i++;
        if (str[i] == '\"')
            i++;
    }
    else
        while (str[i] && str[i] == ' ')
            i++;
    return (i);
}