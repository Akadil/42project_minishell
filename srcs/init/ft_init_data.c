/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akadilkalimoldayev <akadilkalimoldayev@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:59:31 by akadilkalim       #+#    #+#             */
/*   Updated: 2023/05/09 18:49:07 by akadilkalim      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include <stdio.h>

void    ft_init_data(int argc, char **argv, char **env, t_data *data)
{
    if (argc != 1)
        printf("Error, wrong arguments !");
    
    data->env = NULL;
    ft_init_env(data, env);   
}
