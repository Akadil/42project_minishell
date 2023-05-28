/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_command.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:20:12 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/28 18:06:28 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXEC_COMMAND_H
# define FT_EXEC_COMMAND_H

# include "struct_list.h"
# include "struct_data.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "ft_clean.h"
# include "ft_error.h"

int ft_prepare_pipe(t_node *node, int i_cmd);
int ft_execute(t_cmd *cmd, t_list **env, t_node *node);
int ft_is_builtin(t_list *token);
//void    ft_execute_builtin(t_cmd *cmd, t_data *data);
void    ft_execute_program(t_cmd *cmd, t_list *env, t_node *node);

#endif