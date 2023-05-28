/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 22:52:03 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/29 00:49:22 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_data.h"
#include "struct_list.h"
#include "ft_clean.h"
#include "libft.h"
#include <stdlib.h>

int    ft_execute_exit(t_list **env, t_node *node, t_list *token)
{
    int num;

    if (!token)
        return (0);
    num = ft_atoi((char *)token->content) % 256;
    if (num < 0)
        num = num + 256;
    ft_clean_tree(node);
    ft_clean_env(*env);
    return (num);
}