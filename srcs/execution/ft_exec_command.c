/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:52:57 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/25 12:27:58 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_data.h"

void    ft_exec_command(t_data *data, t_node *node)
{
    int i_cmd;
    int is_success;

    i_cmd = 0;
    is_success = 0;
    while (i_cmd < node->count_cmd)
    {
        is_success = ft_prepare_pipe(node, i_cmd);
        if (is_success == 1)
            ft_execute(data, i_cmd);
        i_cmd++;
    }
}
