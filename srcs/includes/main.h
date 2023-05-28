/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akadilkalimoldayev <akadilkalimoldayev@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 13:24:48 by akadilkalim       #+#    #+#             */
/*   Updated: 2023/05/27 21:22:05 by akadilkalim      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "struct_data.h"
# include "ft_clean.h"

void    ft_init_data(int argc, char **argv, char **env, t_data *data);
t_node  *ft_parsing(char *command, t_list *env);
void    ft_execution(t_data *data, t_node *node);

#endif