/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare_pipe.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:01:18 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/31 18:35:03 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PREPARE_PIPE_H
# define FT_PREPARE_PIPE_H

# include "ft_error.h"
# include "struct_data.h"
# include "struct_list.h"
# include <fcntl.h>
# include <unistd.h>

int		ft_open_in(t_list *token, int fd);
int		ft_open_out(t_list *token, int fd);
char	*ft_open_all_files(t_list *token, t_cmd *cmd);

#endif
