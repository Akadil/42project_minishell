/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_export.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 21:45:25 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/26 13:20:58 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_data.h"
#include "ft_error.h"
#include "libft.h"
#include "struct_list.h"

char	*ft_strdup_alt(t_data *data, char *s);

void    ft_builtin_export(char *key_value, t_list **env)
{
	t_list	*token;
	char	*new_value;

	new_value = ft_strdup(key_value);
	ft_remove_dquotes(new_value);
	token = ft_lstnew(key_value, 0);
	ft_lstadd_front(env, token);
}
