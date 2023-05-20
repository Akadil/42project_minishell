/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:31:49 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/20 19:44:28 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int main(int argc, char **argv, char **env)
{
    t_data  data;
    char    *command;

    command = NULL;
    ft_init_data(argc, argv, env, &data);
    while (1)
    {
        command = readline("$");
        if (ft_parsing(&data, command) == 0)
            ft_execution(data);
        free (command);
    }
}