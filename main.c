/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:31:49 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/11 15:25:21 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int main(int argc, char **argv, char **env)
{
    t_data  *data;
    char    *command;

    data = NULL;
    command = NULL;
    ft_initialization(argc, argv, env, data);
    while (1)
    {
        command = readline("$");
        ft_parsing(data, command);
        ft_execution(data);
        free (command);
    }
}