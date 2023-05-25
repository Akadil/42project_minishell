/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:31:49 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/25 11:18:13 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int main(int argc, char **argv, char **env)
{
    t_data  data;
    t_node  *cmd;
    char    *command;

    command = NULL;
    ft_init_data(argc, argv, env, &data);
    while (1)
    {
        command = readline("$");
		if (!command)
			break;
        cmd = ft_parsing(command, data.env);
        if (cmd)
        {
        	ft_execution(&data, cmd);
        	ft_clean_tree(cmd);
        }
        // if (cmd)
		// {
        //     printf("My command\n");
		// 	ft_clean_tree(cmd);
		// }
		// else
        //     printf("not exist\n");
    }
	ft_clean_tokens(&data.env, NULL);
    return (0);
}