/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_space_utils_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 21:30:32 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/31 21:31:31 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_set_mode_add_space(char *mode, char c1, char c2)
{
	if (*mode == 0 && c1 == '\'')
		*mode = '\'';
	else if (*mode == '\'' && c1 == '\'')
		*mode = '\0';
	else if (*mode == 0 && c1 == '\"')
		*mode = '\"';
	else if (*mode == '\"' && c1 == '\"')
		*mode = '\0';
	else if (c2 == '\0')
		*mode = '\0';
}

char	*ft_is_metacharacter(char c1, char c2)
{
	static char	mode;

	ft_set_mode_add_space(&mode, c1, c2);
	if (mode != '\0')
		return (NULL);
	if (c1 == '|' && c2 == '|')
		return ("||");
	if (c1 == '|')
		return ("|");
	if (c1 == '&' && c2 == '&')
		return ("&&");
	if (c1 == '(')
		return ("(");
	if (c1 == ')')
		return (")");
	if (c1 == '<' && c2 == '<')
		return ("<<");
	if (c1 == '<')
		return ("<");
	if (c1 == '>' && c2 == '>')
		return (">>");
	if (c1 == '>')
		return (">");
	return (NULL);
}

int	ft_size(char *str)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (str[i])
	{
		if (ft_is_metacharacter(str[i], str[i + 1]) != 0)
			size++;
		i++;
	}
	return (i + size * 2);
}
