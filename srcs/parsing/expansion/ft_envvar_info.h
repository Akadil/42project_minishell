/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envvar_info.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:04:11 by akalimol          #+#    #+#             */
/*   Updated: 2023/04/11 16:11:27 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENVVAR_INFO_H
# define FT_ENVVAR_INFO_H

# include "ft_envvar.h"
# include "my_libft.h"

int		ft_isalnum_alt(char c);
int		ft_isalnum_alt2(char c);
int		ft_word_size(char *_line, int _pos);
int		ft_envvar_count(char *_line);
void	ft_init_envvar(t_envvar *data);
char    *ft_add_word(char *line, int pos);

#endif