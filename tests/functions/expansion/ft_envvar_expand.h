/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envvar_expand.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:04:40 by akalimol          #+#    #+#             */
/*   Updated: 2023/04/11 21:06:25 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENVVAR_EXPAND_H
# define FT_ENVVAR_EXPAND_H

# include "ft_data.h"
# include "ft_envvar.h"
# include "my_libft.h"
# include "ft_envvar_info.h"

void    ft_envvar_info(t_envvar *data, char *line);
void	ft_preproces(t_envvar *env, t_data *data, t_line *line_exp, char *line);
void	ft_envvar_free(t_envvar *trash, char *trash_line);

#endif