/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:15:26 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/29 01:29:13 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_expand_token.h"

/**
 * @brief 			Expands (env var expansion) the string and create tokens. 
 * 					
 * 					All key words were already tokenized, but if token contain 
 * 					env var and env var contains a space, then our token have 
 * 					to be divided
 * 					
 * @example			Suppose $a="s -la". Then l$a -> ls -la with ls is a command
 * @example			Suppose $a=" ". Then ls$a-la$a"Makefile" -> ls -la Makefile 
 * 
 * @param str		-	string to expand 
 * @param env		-	env variables
 * 
 * @return t_list*	=	NULL - some malloc problems
 * 					=	list - with all variables
 */
t_list  *ft_expand_token(char *str, t_list *env)
{
	t_list	*head;
	t_list	*token;
	char	*exp_string;
	char	**words;
	int		i;

	exp_string = ft_expand_string(str, env);
	if (!exp_string)
		return (NULL);
	if (ft_find_n_word(exp_string, ' ') <= 1)
		return (ft_lstnew(exp_string, 0));
	if (!(words = ft_split_alt(exp_string, ' ')))
		return (NULL);
	i = 0;
	head = NULL;
	while (words[i])
	{
		token = ft_lstnew(words[i], 0);
		if (!token)
			return (ft_free_expand_token(words, &head));
		ft_lstadd_back(&head, token);
		i++;
	}
	free(words);
	return (head);
}