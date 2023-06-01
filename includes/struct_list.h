/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:29:34 by akadilkalim       #+#    #+#             */
/*   Updated: 2023/06/01 19:46:45 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_LIST_H
# define STRUCT_LIST_H

typedef struct s_list
{
	void			*content;
	int				type;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

#endif