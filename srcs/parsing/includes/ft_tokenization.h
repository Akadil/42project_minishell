/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenization.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:49:36 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/24 04:44:50 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TOKENIZATION_H
# define FT_TOKENIZATION_H

# include "struct_list.h"
# include "ft_error.h"

t_list  *ft_add_token(char *str, int i_beg, int i_end, t_list *env);
int     ft_is_token(char c, int checker);
t_list  *ft_token_merror(char *str, t_list *token);
t_list  *ft_token_error(t_list *token);
void    ft_remove_quotes(t_list *head);

#endif