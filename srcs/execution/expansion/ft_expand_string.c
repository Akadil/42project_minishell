/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:24:59 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/23 17:51:11 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_expand_string.h"

/**
 * @brief           Expand the string if any expansions. Ignores the quotes
 * 
 * @param str   -   string to extend 
 * @param env   -   environment variables
 * @return char*    expanded string. NULL if malloc failed
 * 
 * ----------------------------------------------------------------------------
 * @example         "Login: $USER, Home: "$HOME"" -> 
 *                  "Login: akalimol, Home: "$HOME""
 * 
 * @def     ft_strchr_alt()	- the same, just ignores the quotes
 * @def		ft_find_key()	- returns the position of the end of expansion var
 * 								or its length
 * @def		ft_find_value()	- find the value of expansion variable
 * @def		ft_strjoin_big()- joins beginning, the expansion value and end of 
 * 								string
 * 
 * 	functions located in a ./utils/${filename}_utils.c file
 */
char  *ft_expand_string(char *str, t_list *env)
{
    char    *temp;
    char    *value;
    int     pos_key;

    temp = ft_strchr_alt(str, '$');
    if (!temp)
        return (str);
    while (temp)
    {
        pos_key = ft_find_key(temp + 1);
        value = ft_find_value(temp + 1, pos_key, env);
        str = ft_strjoin_big(str, value, temp + pos_key + 1);
        if (!str)
            return (NULL);                          // Protect it 
        temp = ft_strchr_alt(str, '$');
    }
    return (str);
}
