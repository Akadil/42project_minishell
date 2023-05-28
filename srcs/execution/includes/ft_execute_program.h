/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_program.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 14:05:29 by akadilkalim       #+#    #+#             */
/*   Updated: 2023/05/28 18:50:02 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXECUTE_PROGRAM_H
# define FT_EXECUTE_PROGRAM_H

# include "struct_list.h"
# include "struct_data.h"
# include "libft.h"
# include "ft_error.h"

char    *ft_find_path(char *cmd, t_list *env);
char    **ft_construct_command(t_list *params);

#endif