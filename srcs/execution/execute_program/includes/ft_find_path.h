/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_path.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akadilkalimoldayev <akadilkalimoldayev@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:37:44 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/28 14:11:04 by akadilkalim      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FIND_PATH_H
# define FT_FIND_PATH_H

#include "struct_list.h"
#include "struct_data.h"
#include "libft.h"
#include "ft_error.h"
#include <stdio.h>

char    *ft_find_all_paths(t_list *env);

#endif