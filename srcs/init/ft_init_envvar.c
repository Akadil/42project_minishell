/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_envvar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:05:34 by akadilkalim       #+#    #+#             */
/*   Updated: 2023/05/31 19:06:05 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"
#include "libft.h"
#include "struct_data.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief 		Initilize the environment variables.
 * 
 * @example		They are going to be saved inside of linked list, where:
 * 
 * 					list->content	- full string (ex. "USER=akalimol")
 *        			list->type      - default or not
 * 
 * @param data_env 	Address of env data. &data->env
 * @param env 		environment variables passed from program
 * 
 * @return int 		0	- if everything ok
 * 					-1	- if malloc failed
 */
int	ft_init_env(t_list **data_env, char **env)
{
	t_list	*token;
	char	*str;
	int		i;

	i = 0;
	while (env[i])
	{
		str = ft_strdup(env[i]);
		if (!str)
		{
			ft_lstclear(data_env, &free);
			ft_error();
			return (-1);
		}
		token = ft_lstnew(str, 0);
		if (!token)
		{
			free(str);
			ft_lstclear(&token, &free);
			return (ft_error(), -1);
		}
		ft_lstadd_back(data_env, token);
		i++;
	}
	return (0);
}
