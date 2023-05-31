/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_program.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 14:05:29 by akadilkalim       #+#    #+#             */
/*   Updated: 2023/05/31 17:52:00 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXECUTE_PROGRAM_H
# define FT_EXECUTE_PROGRAM_H

# include "ft_error.h"
# include "libft.h"
# include "struct_data.h"
# include "struct_list.h"

int		ft_find_path(char *cmd, t_list *env, char **place);
char	**ft_construct_command(t_list *params);

#endif