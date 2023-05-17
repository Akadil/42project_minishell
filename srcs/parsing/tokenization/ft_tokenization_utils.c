/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenization_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:58:56 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/17 13:36:20 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_list.h"
#include <stdlib.h>
#include "ft_error.h"
#include "libft.h"

t_list  *ft_token_error(t_list *token)
{
    ft_error();
    ft_lstclear(&token, &free);
    return (NULL);
}

t_list  *ft_token_perror(char *str, t_list *token)
{
    ft_perror(str);
    ft_lstclear(&token, &free);
    return (NULL);
}
