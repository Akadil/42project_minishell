/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preprocess_parameter.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:25:34 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/25 14:39:14 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_list.h"
#include "struct_data.h"
#include "libft.h"

t_list  *ft_preprocess_parameter(t_list *token, t_cmd *cmd, int i_cmd)
{
    t_list  *temp;

    temp = token->next;
    token = ft_lstretrieve(&token, token);
    ft_lstadd_back(&(cmd[i_cmd].params), token);
    return (temp);
}