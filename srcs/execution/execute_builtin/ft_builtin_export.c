/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_export.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 21:45:25 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/29 00:03:25 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_data.h"
#include "ft_error.h"
#include "libft.h"
#include "struct_list.h"

int    ft_builtin_export(char *key_value, t_list **env)
{
	t_list	*token;
	char	*new_value;

	new_value = ft_strdup(key_value);
	if (!new_value)
		return (-1);
	token = ft_lstnew(key_value, 1);
	if (!token)
		return (-1);
	ft_lstadd_front(env, token);
	return (0);
}
