/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare_pipe.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:01:18 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/25 17:04:27 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PREPARE_PIPE_H
# define FT_PREPARE_PIPE_H

# include <unistd.h>
# include "struct_data.h"
# include "struct_list.h"
# include "ft_error.h"

char    *ft_open_all_files(t_list *token, t_cmd *cmd);

#endif
