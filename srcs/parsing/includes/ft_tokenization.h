/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenization.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:49:36 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/17 13:36:32 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TOKENIZATION_H
# define FT_TOKENIZATION_H

# include "struct_list.h"
# include "ft_error.h"

int     ft_add_token(t_list **head, char *str, int i_beg, int i_end);
int     ft_is_token(char c, int checker);
t_list  *ft_token_perror(char *str, t_list *token);
t_list  *ft_token_error(t_list *token);

#endif