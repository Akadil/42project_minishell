/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:52:27 by akadilkalim       #+#    #+#             */
/*   Updated: 2023/05/15 16:23:45 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include "linked_list.h"

#define PIPE 1
#define OR 2
#define AND 3

#define LEFT_P 4
#define RIGHT_P 5

#define REDIRECT_IN 6
#define REDIRECT_OUT 7
#define HEREDOC 8
#define REDIRECT_OUT2 9

#define FILENAME 10
#define PARAMETER 11

typedef struct s_data
{
    t_list  *env;
}   t_data;

typedef struct s_node
{
    t_list  *elems;

    

    t_list  *params; // If cmd, then all params, else one param only
    t_list  *redirections; // "content" = filename, "type" = redirection type
    
    int     type;
    int     in_fd;
    int     out_fd;
    int     exit_code;
    struct s_node   *parent;
    struct s_node   *left;
    struct s_node   *right;
    
}   t_node;

typedef struct s_operator
{

}   t_operator;

typedef struct s_cmd
{
    char    **parameters;

    
}   t_cmd;


#endif