/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 22:17:11 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/31 17:59:57 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "struct_list.h"

void	ft_execute_env(t_list *env)
{
	while (env)
	{
		ft_printf("%s\n", (char *)env->content);
		env = env->next;
	}
}
