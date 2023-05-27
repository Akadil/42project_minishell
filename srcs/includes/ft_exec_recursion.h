/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_recursion.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:29:09 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/27 18:45:09 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXEC_RECURSION_H
# define FT_EXEC_RECURSION_H

#include "struct_data.h"
#include "libft.h"
#include "ft_clean.h"
#include <stdio.h>

int    ft_exec_recursion(t_data *data, t_node *node, t_node *parent);
int ft_check_operator(int exit_code, char *str);
int    ft_preprocess(t_node *node);

#endif