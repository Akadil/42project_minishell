/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_heredocs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 03:32:32 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/25 12:15:30 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_list.h"
#include "ft_error.h"
#include "libft.h"
#include <unistd.h>
#include <readline/readline.h>

int    ft_get_heredoc(char *delimiter, t_list *env);
char  *ft_expand_string(char *str, t_list *env);
void ft_remove_quotes_string(char *str);

int ft_open_heredocs(t_list *head, t_list *env)
{
    t_list  *token;
    void    *temp;
    int     *fd;

    token = head;
    while (token)
    {
        if (token->type == 8)
        {
            temp = token->next->content;
            fd = (int *)malloc(sizeof(int));
            if (!fd)
                return (-1);
            *fd = ft_get_heredoc((char *)temp, env);
            if (*fd == -1)
            {
                free (fd);
                return (-1);
            }
            token->next->content = fd;
            free (temp);
        }
        token = token->next;
    }
    return (0);
}

int    ft_get_heredoc(char *delimiter, t_list *env)
{
	char    *line;
    int		fd[2];

    if (pipe(fd) == -1)
    {
        ft_error();
        return (-1);
    }
	line = readline(">");
	while (line && ft_strcmp(line, delimiter) != 0)
	{
        line = ft_expand_string(line, env);
        ft_remove_quotes_string(line);
		ft_putstr_fd(line, fd[1]);
		free(line);
		line = readline(">");
	}
    free(line);
    close (fd[1]);
    return (fd[0]);
}
