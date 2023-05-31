/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preprocess_cmd.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:41:33 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/31 17:52:00 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PREPROCESS_CMD_H
# define FT_PREPROCESS_CMD_H

# include "libft.h"
# include "struct_data.h"
# include "struct_list.h"
# include <stdio.h>
# include <stdlib.h>

t_list	*ft_preprocess_parameter(t_list *token, t_cmd *cmd, int i_cmd);
t_list	*ft_preprocess_redirection(t_list *token, t_cmd *cmd, int i_cmd);

#endif