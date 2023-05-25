/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envVar.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:59:26 by akalimol          #+#    #+#             */
/*   Updated: 2023/04/11 15:06:16 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENVVAR_H
#define FT_ENVVAR_H

typedef struct s_item
{
	char *key;
	char *value;
	int key_size;
	int value_size;
} t_item;

typedef struct s_envvar
{
	t_item	*item;
	int		size;
	int		key_size;
	int		value_size;
} t_envvar;

typedef struct s_line
{
	char	*value;
	int		size;
}	t_line;


#endif