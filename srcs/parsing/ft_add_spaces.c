/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_spaces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 00:12:17 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/20 18:59:41 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_add_spaces.h"

/**
 * @brief Add space between meta characters
 * 
 * Example:
 *          Before:  (cat||ls)|pwd
 *          After:   ( cat || ls ) | pwd
 * 
 * helper functions: ./utils/ft_add_spaces_utils.c
 *  - ft_size()				    - Calculates the overall size of the string with 
 * 							      spaces
 *  - ft_is_metacharacter()    - checks if the character is meta
 *  - ft_put()                 - concantenates the meta characters with spaces
 *  - ft_remove_extra...()     - removes preeceding, succeeding, and duplicating
 *                       	     spaces  
 * 
 * @param str   string to proceed
 * @return      string with spaces
 */

// The problem with a quotes. All metas inside of them, should be skipped.
char    *ft_add_spaces(char *str)
{
    char    *string;
    char    *meta;
    int     i;
    int     j;

    string = (char *)ft_calloc(sizeof(char), ft_size(str) + 2);
    if (!string)
        return (ft_free(str));
    i = 0;
    j = 0;
    while (str[i])
    {
        if (ft_isspace(str[i]) == 1)
            string[j++] = ' ';
        else if ((meta = ft_is_metacharacter(str[i], str[i + 1])))
            ft_put(string, &j, &i, meta);
        else
            string[j++] = str[i];
        i++;
    }
    ft_remove_extra_spaces(string);
    free(str);
    return (string);
}
