/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envvar_info_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:01:09 by akalimol          #+#    #+#             */
/*   Updated: 2023/04/12 11:00:42 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_envvar.h"
#include "my_libft.h"
#include <stdlib.h>

int	ft_isalnum_alt(char c)
{
	if (ft_isalnum(c) == 1 || c == '_')
		return (1);
	return (0);
}

int	ft_isalnum_alt2(char c)
{
	if (ft_isalpha(c) == 1 || c == '_')
		return (1);
	return (0);
}

int	ft_word_size(char *_line, int _pos)
{
	int	size;

	size = 0;
	while (_line[_pos + size] && ft_isalnum_alt(_line[_pos + size]))
		size++;
	return (size);
}

int	ft_envvar_count(char *_line)
{
	int	num;
	int	i;

	i = 0;
	num = 0;
	while (_line[i])
	{
		if (_line[i] == '$' && ft_isalnum_alt2(_line[i + 1]))
			num++;
		i++;
	}
	return (num);
}

void	ft_init_envvar(t_envvar *data)
{
	int	i;

	i = 0;
	while (i < data->size)
	{
		data->item[i].key = NULL;
		data->item[i].value = NULL;
		data->item[i].key_size = 0;
		data->item[i].value_size = 0;
		i++;
	}
	data->key_size = 0;
	data->value_size = 0;
}
