/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 22:52:03 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/28 23:55:21 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_data.h"
#include "struct_list.h"
#include "ft_clean.h"
#include <stdlib.h>

int    ft_builtin_exit(t_list **env, t_node *node, char *str)
{
    int num;

    num = ft_atoi(str) % 256;
    if (num < 0)
        num + 256;
    ft_clean_tree(node);
    ft_clean_env(*env);
    return (num);
}