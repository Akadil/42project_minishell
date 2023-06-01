/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:48:06 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/01 18:07:26 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_token(char c, int checker)
{
	static char	mode;

	if (checker == 1)
	{
		if (mode == 0)
			return (1);
		return (mode = 0);
	}
	else if (mode == 'd' || (c == '\"' && mode == 0))
	{
		if (mode == 0)
			mode = 'd';
		else if (c == '\"')
			mode = 0;
	}
	else if (mode == 's' || (c == '\'' && mode == 0))
	{
		if (mode == 0)
			mode = 's';
		else if (c == '\'')
			mode = 0;
	}
	else if (ft_isspace(c) == 1)
		return (0);
	return (1);
}
