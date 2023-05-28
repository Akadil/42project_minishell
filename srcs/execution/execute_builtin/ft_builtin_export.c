/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_export.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 21:45:25 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/29 01:17:24 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"
#include "libft.h"
#include "struct_data.h"
#include "struct_list.h"

void	ft_print_export(t_list *env)
{
	while (env)
	{
		ft_printf("export %s\n", (char *)env->content);
		env = env->next;
	}
}

int	ft_execute_export(t_list *params, t_list **env)
{
	t_list	*token;
	char	*new_value;

	if (!params)
		return (ft_print_export(*env), 0);
	new_value = ft_strdup((char *)params->content);
	if (!new_value)
		return (-1);
	token = ft_lstnew(new_value, 1);
	if (!token)
		return (-1);
	ft_lstadd_front(env, token);
	return (0);
}
