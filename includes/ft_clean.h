/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:38:42 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/01 19:46:03 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CLEAN_H
# define FT_CLEAN_H

# include "struct_data.h"
# include "struct_list.h"

void	ft_clean_fds(t_cmd *cmd);
void	ft_clean_tree(t_node *node);
void	ft_clean_cmds(t_cmd *cmds_p, int size);
void	ft_clean_tokens(t_list **token, void (*del)(void *));
void	ft_clean_darray(char **trash);
void	ft_clean_env(t_list *env);

#endif
