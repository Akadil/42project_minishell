/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenization.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:49:06 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/01 17:22:02 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_tokenization.h"

/**
 * @brief               separate each key word into token
 * 
 * @example             cat || ls  -> ['cat', '|', 'ls']
 * 
 * @ref:ft_is_token()       
 * @ref:ft_add_token()
 * @ref:ft_token_error()
 * @ref:ft_token_merror()
 * 
 * @param str           input string to tokenize
 * @return t_list*      tokens
 */
t_list	*ft_tokenization(char *str, t_list *env, t_data *data)
{
	t_list	*head;
	int		i_beg;
	int		i_end;
	t_list	*token;

	(void)env;
	i_beg = 0;
	i_end = 0;
	head = NULL;
	while (str[i_beg])
	{
		i_end = i_beg;
		while (str[i_end] && ft_is_token(str[i_end], 0))
			i_end++;
		token = ft_add_token(str, i_beg, i_end, data);
		if (!token)
			return (ft_token_error(head));
		ft_lstadd_back(&head, token);
		i_beg = i_end + 1;
	}
	if (ft_is_token(0, 1) == 0)
		return (ft_token_merror("BASH: unclosed quotes\n", head));
	ft_remove_quotes(head);
	return (head);
}
