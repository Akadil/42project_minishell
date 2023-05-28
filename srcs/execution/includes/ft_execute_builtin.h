/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_builtin.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 23:10:19 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/29 00:55:56 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXECUTE_BUILTIN
# define FT_EXECUTE_BUILTIN

# include "struct_list.h"
#include "struct_data.h"
#include "libft.h"

void    ft_execute_pwd();
void    ft_execute_unset(t_list **env, char *cmd);
int    ft_execute_exit(t_list **env, t_node *node, t_list *token);
void    ft_execute_env(t_list *env);
void    ft_execute_echo(t_list *token);
int    ft_execute_export(t_list *params, t_list **env);
int    ft_execute_cd(t_list *params, t_list *env);

#endif