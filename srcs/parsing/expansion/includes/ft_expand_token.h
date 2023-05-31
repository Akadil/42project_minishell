/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_token.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:56:19 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/31 17:52:01 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXPAND_TOKEN_H
# define FT_EXPAND_TOKEN_H

# include <stdio.h>
# include <stdlib.h>
# include "struct_list.h"
# include "struct_data.h"
# include "libft.h"

char	*ft_expand_string(char *str, t_list *env, t_data *data);
t_list	*ft_free_expand_token(char **words, t_list **head);
int     ft_find_n_word(char const *s, char c);
char	**ft_split_alt(char const *s, char c);

#endif
