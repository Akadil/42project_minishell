/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_token_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:00:31 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/23 12:01:02 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_list.h"
#include <stdio.h>

t_list	*ft_free_expand_token(char **words, t_list **head)
{
	int	i;

	i = 0;
	while (words[i])
	{
		free (words[i]);
		i++;
	}
	free (words);
	ft_lstclear(head, NULL);
	return (NULL);
}