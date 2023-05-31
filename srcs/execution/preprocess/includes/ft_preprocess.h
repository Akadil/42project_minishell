/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preprocess.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:31:52 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/31 17:52:00 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PREPROCESS_H
# define FT_PREPROCESS_H

# include "ft_error.h"
# include "struct_data.h"
# include <stdio.h>
# include <stdlib.h>

int		ft_preprocess_node(t_node *node);
int		ft_count_cmds(t_list *token);
void	ft_init_cmds(t_cmd *cmds, int num_cmds);
void	ft_preprocess_cmd(t_cmd *cmds, t_list *token);

#endif