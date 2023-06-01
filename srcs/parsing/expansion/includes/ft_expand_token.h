/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_token.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:56:19 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/01 17:26:37 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXPAND_TOKEN_H
# define FT_EXPAND_TOKEN_H

# include "libft.h"
# include "struct_data.h"
# include "struct_list.h"
# include <stdio.h>
# include <stdlib.h>

char	*ft_expand_string(char *str, t_list *env, t_data *data);
t_list	*ft_free_expand_token(char **words, t_list **head);
int		ft_find_n_word(char const *s, char c);
char	**ft_split_alt(char const *s, char c);

#endif
