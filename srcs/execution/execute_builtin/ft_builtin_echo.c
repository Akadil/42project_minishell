/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_echo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 23:21:31 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/31 17:59:42 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "struct_list.h"

int	ft_strcmp_alt(char *str)
{
	int	i;

	if (!str || str[0] != '-')
		return (1);
	i = 1;
	while (str[i] && str[i] == 'n')
		i++;
	if (str[i] == '\0')
		return (0);
	return (1);
}

void	ft_execute_echo(t_list *token)
{
	int	is_n;

	is_n = 0;
	while (token && ft_strcmp_alt((char *)token->content) == 0)
	{
		is_n = 1;
		token = token->next;
	}
	while (token)
	{
		ft_printf("%s", (char *)token->content);
		if (token->next)
			ft_printf(" ");
		token = token->next;
	}
	if (is_n == 0)
		ft_printf("\n");
}
