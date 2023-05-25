/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:33:56 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/25 11:28:09 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_envvar_expand.h"

// char	*ft_expand_envvar(t_data *data, char *line)
// {
// 	t_envvar	env_var;
// 	t_line		line_ret;
// 	int			i;		// To track line[i]
// 	int			j;		// To track new_line[j]
// 	int			k;		// To track env_var.item[k];

// 	ft_envvar_info(&env_var, line);
// 	ft_preproces(&env_var, data, &line_ret, line);
// 	i = 0;
// 	j = 0;
// 	k = 0;
// 	while (i + j < line_ret.size - 1)
// 	{
// 		if (line[i] == '$' && ft_isalnum_alt2(line[i + 1]))
// 		{
// 			if (env_var.item[k].value)
// 				ft_strlcat(line_ret.value, env_var.item[k].value, line_ret.size);
// 			j += env_var.item[k].value_size - env_var.item[k].key_size - 1;
// 			i += env_var.item[k++].key_size;
// 		}
// 		else
// 			line_ret.value[i + j] = line[i];
// 		i++;
// 	}
// 	line_ret.value[i + j] = '\0';
// 	ft_envvar_free(&env_var, line);
// 	free(env_var.item);
// 	return (line_ret.value);
// }

