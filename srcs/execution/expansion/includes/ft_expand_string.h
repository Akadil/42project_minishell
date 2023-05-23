/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_string.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 19:01:58 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/23 12:46:55 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXPAND_STRING_H
# define FT_EXPAND_STRING_H

# include "struct_list.h"
# include "libft.h"
# include <stdlib.h>

char	*ft_strchr_alt(const char *s, int c);
int     ft_size_expanded(char *str, char *value, char *end);
char    *ft_strjoin_big(char *str, char *value, char *end);
int     ft_find_key(char *str);
char    *ft_find_value(char *key, int i_pos, t_list *env);


#endif