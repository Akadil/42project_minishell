/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preprocess_redirection.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:14:51 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/25 14:40:53 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_list.h"
#include "struct_data.h"
#include "libft.h"
#include <stdlib.h>

t_list  *ft_preprocess_redirection(t_list *token,  t_cmd *cmd, int i_cmd)
{
    t_list  *temp;

    free(token->content);
    token->content = token->next->content;
    ft_lstremove(&token, token->next, NULL);
    temp = token->next;
    token = ft_lstretrieve(&token, token);
    ft_lstadd_back(&(cmd[i_cmd].redir), token);
    return (temp);
}