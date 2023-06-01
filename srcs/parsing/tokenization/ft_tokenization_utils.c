/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenization_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:58:56 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/01 17:18:41 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"
#include "libft.h"
#include "struct_list.h"
#include <stdlib.h>

t_list	*ft_token_error(t_list *token)
{
	ft_error();
	ft_lstclear(&token, &free);
	return (NULL);
}

t_list	*ft_token_merror(char *str, t_list *token)
{
	ft_merror(str, NULL);
	ft_lstclear(&token, &free);
	return (NULL);
}
