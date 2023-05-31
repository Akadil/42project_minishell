/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_recursion.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:29:09 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/31 19:01:16 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXEC_RECURSION_H
# define FT_EXEC_RECURSION_H

# include "ft_clean.h"
# include "libft.h"
# include "struct_data.h"
# include <stdio.h>

int	ft_exec_recursion(t_node *node, t_data *data, t_node *parent);
int	ft_check_operator(int exit_code, char *str);
int	ft_preprocess(t_node *node);
int	ft_exec_command(t_node *node, t_data *data);

#endif