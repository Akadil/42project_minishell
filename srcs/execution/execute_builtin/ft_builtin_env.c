/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 22:17:11 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/29 00:09:45 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_list.h"
#include "libft.h"

void    ft_execute_env(t_list *env)
{
    while (env)
    {
        ft_printf("%s\n", (char *)env->content);
        env = env->next;
    }
}