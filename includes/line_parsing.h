/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_parsing.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:48:54 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/16 15:43:57 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_PARSING_H
# define LINE_PARSING_H

#include "data.h"
#include "linked_list.h"
#include "ft_error.h"
#include <stdio.h>

t_list    *ft_tokenization(char *str);
char    *ft_add_spaces(char *str);
t_node  *ft_make_tree(t_list *token, t_node *parent);


#endif