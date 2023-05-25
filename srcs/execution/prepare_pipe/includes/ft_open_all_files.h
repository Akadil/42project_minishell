/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_all_files.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:05:58 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/25 17:06:36 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OPEN_ALL_FILES_H
# define FT_OPEN_ALL_FILES_H

# include "struct_list.h"
# include "struct_data.h"
# include <fcntl.h>
# include <unistd.h>

int ft_open(t_list *token, int fd);

#endif