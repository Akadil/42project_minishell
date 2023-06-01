/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_data.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:52:27 by akadilkalim       #+#    #+#             */
/*   Updated: 2023/06/01 19:45:34 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_DATA_H
# define STRUCT_DATA_H

# include "struct_list.h"

extern int			g_signal;

# define PIPE 1
# define OR 2
# define AND 3
# define LEFT_P 4
# define RIGHT_P 5
# define REDIRECT_IN 6
# define REDIRECT_OUT 7
# define HEREDOC 8
# define REDIRECT_OUT2 9
# define FILENAME 10
# define PARAMETER 11

typedef struct s_cmd
{
	t_list			*params;
	t_list			*redir;
	int				in_fd;
	int				out_fd;
	int				out_pipe_fd;
}					t_cmd;

typedef struct s_node
{
	t_list			*elems;
	t_cmd			*cmds;
	int				count_cmd;
	int				type;
	int				exit_code;
	int				level;
	struct s_node	*parent;
	struct s_node	*left;
	struct s_node	*right;
	int				is_micro;

}					t_node;

typedef struct s_data
{
	t_list			*env;
	t_node			*node;
	int				exit_code;
}					t_data;

void				ft_signal(int signal);

#endif