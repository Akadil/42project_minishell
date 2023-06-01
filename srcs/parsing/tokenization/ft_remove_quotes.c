/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_quotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 04:12:20 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/01 17:22:18 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "struct_list.h"

void	ft_remove_quotes_string(char *str)
{
	char	mode;
	int		i;
	int		j;

	i = 0;
	j = 0;
	mode = '\0';
	while (str[i])
	{
		if (mode == '\0' && str[i] == '\'')
			mode = 's';
		else if (mode == 's' && str[i] == '\'')
			mode = '\0';
		else if (mode == '\0' && str[i] == '\"')
			mode = 'd';
		else if (mode == 'd' && str[i] == '\"')
			mode = '\0';
		else
			str[j++] = str[i];
		i++;
	}
	while (j != i)
		str[j++] = '\0';
}

void	ft_remove_quotes(t_list *head)
{
	t_list	*token;
	char	*str;

	token = head;
	while (token)
	{
		str = (char *)token->content;
		ft_remove_quotes_string(str);
		token = token->next;
	}
}
