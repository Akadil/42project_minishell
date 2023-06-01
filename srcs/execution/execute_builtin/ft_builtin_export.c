/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_export.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 21:45:25 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/01 18:03:50 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"
#include "libft.h"
#include "struct_data.h"
#include "struct_list.h"
#include <stdlib.h>

void	ft_print_export(t_list *env);
void	ft_remove_if_exist(t_list **env, char *new_value);

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
	ft_remove_if_exist(env, new_value);
	ft_lstadd_front(env, token);
	return (0);
}

void	ft_remove_if_exist(t_list **env, char *new_value)
{
	t_list	*token;
	t_list	*temp;
	char	*str;
	int		i;

	token = *env;
	while (token)
	{
		i = 0;
		str = (char *)token->content;
		while (str[i] && new_value[i] && str[i] != '=')
			i++;
		temp = token->next;
		if (str[i] == '=' || str[i] == '\0')
			if (new_value[i] == '=' || new_value[i] == '\0')
				if (ft_strncmp(str, new_value, i) == 0)
					ft_lstremove(env, token, &free);
		token = temp;
	}
}
