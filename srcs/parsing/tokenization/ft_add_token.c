/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:48:41 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/23 16:54:43 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"
#include "libft.h"
#include "struct_list.h"
#include <stdlib.h>

t_list	*ft_expand_token(char *str, t_list *env);

t_list	*ft_add_token(char *str, int i_beg, int i_end, t_list *env)
{
	char *new_str;
	t_list *node;
	int i;

	if (i_beg == i_end)
		i_end++;
	new_str = (char *)malloc(sizeof(char) * (i_end - i_beg + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < i_end - i_beg)
	{
		new_str[i] = str[i + i_beg];
		i++;
	}
	new_str[i] = '\0';
	node = ft_expand_token(new_str, env);
	free(new_str);
	if (!node)
		return (NULL);
	return (node);
}