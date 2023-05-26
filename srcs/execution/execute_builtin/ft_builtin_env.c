/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 22:17:11 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/26 13:22:31 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_list.h"
#include "libft.h"

void    ft_builtin_env(t_list *env)
{
    while (env)
    {
        ft_printf("%s\n", (char *)env->content);
        env = env->next;
    }
}