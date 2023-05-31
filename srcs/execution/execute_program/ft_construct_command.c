/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_construct_command.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:52:21 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/31 17:58:40 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"
#include "libft.h"
#include "struct_list.h"
#include <stdio.h>

/**

	* @brief           Do I have reallocate the memmory for this command? or 
						can keep
 *                  it like this?
 * 
 * @param params 
 * @return char** 
 */
char	**ft_construct_command(t_list *params)
{
	char	**returner;
	int		size;
	int		i;

	size = ft_lstsize(params);
	returner = (char **)malloc(sizeof(char *) * (size + 1));
	if (!returner)
		return (ft_error_exit(-1), NULL);
	i = 0;
	while (i < size)
	{
		returner[i] = (char *)params->content;
		params = params->next;
		i++;
	}
	returner[i] = NULL;
	return (returner);
}
