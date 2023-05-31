/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_unset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:51:00 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/31 22:41:11 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "struct_list.h"
#include <stdio.h>

/*
    Description:    Buildin for unset command

    Idea:           Go through env variables. For each variabele, go through 
                    each value of token. If similarity found, delete env var
    
*/
void	ft_execute_unset(t_list **env, t_list *head)
{
	t_list	*token;
	char	*str;
	int		len;
	char	*cmd;

	if (!head)
		return ;
	cmd = (char *)head->content;
	len = ft_strlen(cmd);
	token = *env;
	while (token)
	{
		str = (char *)token->content;
		if (ft_strncmp(str, cmd, len) == 0 && str[len] == '=')
			break ;
		token = token->next;
	}
	if (!token)
		return ;
	ft_lstremove(env, token, NULL);
}
