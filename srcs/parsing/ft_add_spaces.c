/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_spaces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 00:12:17 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/31 21:33:12 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"
#include "includes/ft_add_spaces.h"

/**
 * @brief Add space between meta characters
 * 
 * @example:
 *          Before:  (cat||ls)|pwd
 *          After:   ( cat || ls ) | pwd
 * 
 * helper functions: ./utils/ft_add_spaces_utils.c
 *  - ft_size()					
						- Calculates the overall size of the string with 
 * 									spaces
 *  - ft_is_metacharacter()    - checks if the character is meta
 *  - ft_put()                 - concantenates the meta characters with spaces
 *  - ft_remove_extra...()     - removes preeceding, succeeding, and duplicating
 *                       			spaces  
 * 
 * @param str   string to proceed
 * @return      string with spaces
 */

// The problem with a quotes. All metas inside of them, should be skipped.
char	*ft_add_spaces(char *str)
{
	char	*string;
	char	*meta;
	int		i;
	int		j;
	int		size;

	size = ft_size(str) + 1;
	string = (char *)ft_calloc(sizeof(char), size + 1);
	if (!string)
		return (ft_error(), free(str), NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		meta = ft_is_metacharacter(str[i], str[i + 1]);
		if (ft_isspace(str[i]) == 1)
			string[j++] = ' ';
		else if (meta)
			ft_put(string, &j, &i, meta);
		else
			string[j++] = str[i];
		i++;
	}
	ft_remove_extra_spaces(string, size + 1);
	return (free(str), string);
}
