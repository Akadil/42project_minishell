/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:59:31 by akadilkalim       #+#    #+#             */
/*   Updated: 2023/05/20 19:48:05 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_data.h"
#include <stdio.h>

void    ft_init_data(int argc, char **argv, char **env, t_data *data)
{
    if (argc != 1)
        printf("Error, wrong arguments !");
    
    data->env = NULL;
    ft_init_env(&data->env, env);
    data->node = NULL;
    data->exit_code == 0;
}
