/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:36:02 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/28 18:06:00 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H

# include "ft_clean.h"
# include "struct_data.h"
# include "libft.h"
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

void	ft_error(void);
void	ft_perror(char *str);
void	ft_merror(char *str, char *param);
void	ft_error_clean_exit(t_node *node, t_list *env, int exit_code);
void	ft_perror_clean_exit(t_data *my_data, char *str);
void	ft_merror_clean_exit(t_data *my_data, char *str, char *param);
void	ft_clean_exit(t_data *my_data);
void	ft_error_exit(void);

#endif