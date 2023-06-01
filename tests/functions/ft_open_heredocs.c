/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_heredocs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 03:32:32 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/01 19:11:39 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_list.h"
#include "ft_error.h"
#include "libft.h"
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <errno.h>
#include <sys/signal.h>

int    ft_get_heredoc(char *delimiter, t_list *env);
char  *ft_expand_string(char *str, t_list *env);
void ft_remove_quotes_string(char *str);

int ft_open_heredocs(t_list *head, t_list *env)
{
    t_list  *token;
    void    *temp;
    int     *fd;
    int     saver;

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
            if (*fd != 0)
            {
                saver = *fd;
                free (fd);
                return (saver);
            }
            token->next->content = fd;
            free (temp);
        }
        token = token->next;
    }
    return (0);
}

void    ft_signal_handler3(int sig)
{
    if (sig == SIGINT)
    {
        g_signal = 1;
        write(1, "\n", 1);
        rl_replace_line("", 0);
        rl_redisplay();
        close(STDIN_FILENO);
    }
}

int    ft_get_heredoc(char *delimiter, t_list *env)
{
	char    *line;
    int		fd[2];
    int     fd_in;

    fd_in = dup(STDIN_FILENO);
    signal(SIGQUIT, &ft_signal_handler3);
    signal(SIGINT, &ft_signal_handler3);
    if (pipe(fd) == -1)
        return (ft_error(), errno);
    line = readline(">");
	while (line && ft_strcmp(line, delimiter) != 0 && my_signal == 0)
	{
        line = ft_expand_string(line, env);
        ft_remove_quotes_string(line);
		ft_putstr_fd(line, fd[1]);
		free(line);
		line = readline(">");
	}
    if (my_signal == 1)
    {
        my_signal = 0;
        close(fd[1]);
        close(fd[0]);
        dup2(fd_in, STDIN_FILENO);
        close(fd_in);
        free (line);
        return (130);
    }
    free(line);
    close (fd[1]);
    close(fd_in);
    return (fd[0]);
}
