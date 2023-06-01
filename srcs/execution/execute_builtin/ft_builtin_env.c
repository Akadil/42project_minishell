/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 22:17:11 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/01 15:18:05 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "struct_list.h"

void	ft_execute_env(t_list *env)
{
	while (env)
	{
		if (ft_strchr((char *)env->content, '='))
			ft_printf("%s\n", (char *)env->content);
		env = env->next;
	}
}
