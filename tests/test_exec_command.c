/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_exec_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 19:04:18 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/28 20:15:48 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_data.h"
#include "struct_list.h"
#include <stdio.h>
#include "libft.h"
#include <readline/history.h>
#include <readline/readline.h>

/*
    To test:        make test_exec_command
*/

int    ft_exec_command(t_node *node, t_list **env);

int main(void)
{
    t_node  node;
    t_list  *env_var;
    char    *str;
    char    **params;
    int     i;
    int     j;
    
    node.cmds = (t_cmd *)ft_calloc(sizeof(t_cmd), 2);
    node.count_cmd = 2;
    env_var = ft_lstnew("USER=akalimol", 0);
    ft_lstadd_back(&env_var, ft_lstnew("a=z", 0));
    ft_lstadd_back(&env_var, ft_lstnew("PATH=/mnt/nfs/homes/akalimol/sgoinfre/miniconda3/bin:/mnt/nfs/homes/akalimol/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin", 0));
    
    j = 0;
    while (j < 2)
    {
        node.cmds[j].redir = NULL;
        str = readline("Enter params: ");
        params = ft_split(str, ' ');
        i = 0;
        while (params[i])
        {
            ft_lstadd_back(&node.cmds[j].params, ft_lstnew(params[i], 0));
            i++;
        }
        str = readline("Enter redirections: ");
        params = ft_split(str, ' ');
        i = 0;
        while (params[i])
        {
            if (ft_strcmp(params[i], "<") == 0 && i++ > -1)
                ft_lstadd_back(&node.cmds[j].redir, ft_lstnew(params[i], 6));
            else if (ft_strcmp(params[i], ">") == 0 && i++ > -1)
                ft_lstadd_back(&node.cmds[j].redir, ft_lstnew(params[i], 7));
            else if (ft_strcmp(params[i], "<<") == 0 && i++ > -1)
                ft_lstadd_back(&node.cmds[j].redir, ft_lstnew(params[i], 9));
            i++;
        }
        node.cmds[j].in_fd = 0;
        node.cmds[j].out_fd = 1;
        node.cmds[j].out_pipe_fd = -1;
        j++;
    }
    ft_exec_command(&node, &env_var);
    return (0);
}