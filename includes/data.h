/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:52:27 by akadilkalim       #+#    #+#             */
/*   Updated: 2023/05/11 18:30:46 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include "linked_list.h"

typedef struct s_data
{
    t_list  *env;
}   t_data;

typedef struct s_node
{
    t_list  *elems;
    int     exit_code;

    int     in_fd;
    int     out_fd;

    struct s_node   *parent;
    struct s_node   *left;
    struct s_node   *right;

}   t_node;

#endif