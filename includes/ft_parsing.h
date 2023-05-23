/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:48:54 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/23 18:34:25 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_PARSING_H
# define LINE_PARSING_H

# include "struct_data.h"
# include "struct_list.h"
# include "ft_error.h"
# include "ft_clean.h"
# include <stdio.h>
# include <stdlib.h>

char	*ft_add_spaces(char *str);
t_list	*ft_tokenization(char *str, t_list *env);
void	ft_assign_types(t_list *node);
int		ft_check_tokens(t_list *node);
t_node	*ft_make_tree(t_list *token, t_node *parent);

#endif