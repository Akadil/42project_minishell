/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envvar_expand_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akadilkalimoldayev <akadilkalimoldayev@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:18:59 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/06 16:34:35 by akadilkalim      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_envvar.h"
#include "ft_data.h"
#include "my_libft.h"
#include <stdlib.h>

void	ft_preproces(t_envvar *env, t_data *data, t_line *line_exp, char *line)
{
	(void)data;
	line_exp->size = ft_strlen(line) + env->value_size - env->key_size + 1;
	line_exp->value = (char *)ft_calloc(sizeof(char), line_exp->size);
	if (!line_exp->value)
		exit(-1); // Extend the problem
}

void	ft_envvar_free(t_envvar *trash, char *trash_line)
{
	int i;

	i = 0;
	while (i < trash->size)
	{
		free(trash->item[i].key);
		i++;
	}
	//free(trash->item);
	free(trash_line);
}