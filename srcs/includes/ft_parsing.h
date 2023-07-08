/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:48:54 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/08 18:54:15 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSING_H
# define FT_PARSING_H

# include "ft_clean.h"
# include "ft_error.h"
# include "struct_data.h"
# include "struct_list.h"
# include <stdio.h>
# include <stdlib.h>

char	*ft_add_spaces(char *str);
t_list	*ft_tokenization(char *str, t_list *env, t_data *data);
void	ft_assign_types(t_list *node);
int		ft_check_tokens(t_list *node);
// int		ft_extend_wildcard(t_list **head);
int		ft_open_heredocs(t_list *head, t_list *env);
t_node	*ft_make_tree(t_list *token, t_node *parent);

#endif