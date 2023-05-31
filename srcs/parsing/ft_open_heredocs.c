/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_heredocs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 03:32:32 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/01 00:57:21 by akalimol         ###   ########.fr       */
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

int    ft_get_heredoc(char *delimiter, t_list *env, int *fd);
char  *ft_expand_string(char *str, t_list *env);
void ft_remove_quotes_string(char *str);

int ft_open_heredocs(t_list *head, t_list *env)
{
    t_list  *token;
    void    *temp;
    int     *fd;
    int     status;

    token = head;
    while (token)
    {
        if (token->type == 8)
        {
            temp = token->next->content;
            fd = (int *)malloc(sizeof(int));
            if (!fd)
                return (-1);
            status = ft_get_heredoc((char *)temp, env, fd);
            if (status != 0)
                return (free (fd), status);
            token->next->content = fd;
            free (temp);
        }
        token = token->next;
    }
    return (0);
}

void    ft_signal_handler3(int signal)
{
	if (signal == SIGINT)
	{
		write(1, "\n", 1);
        rl_replace_line("", 0);
        rl_redisplay();
        close (STDIN_FILENO);
        my_signal = 1;
	}
}

// int    ft_get_heredoc(char *delimiter, t_list *env)
// {
// 	char        *line;
//     int		    fd[2];
//     const int   cpy_fd = dup(STDIN_FILENO);;
    
//     my_signal = 0;
//     signal(SIGINT, ft_signal_handler3);
//     signal(SIGQUIT, SIG_IGN);
//     if (pipe(fd) == -1)
//     {
//         ft_error();
//         return (-1);
//     }
// 	line = readline(">");
// 	while (line && ft_strcmp(line, delimiter) != 0)
// 	{
//         if (my_signal || !line || ft_strcmp(line, delimiter) == 0)
//             break;
//         line = ft_expand_string(line, env);
//         ft_remove_quotes_string(line);
// 		ft_putstr_fd(line, fd[1]);
// 		free(line);
// 		line = readline(">");
// 	}
//     free(line);
//     dup2(cpy_fd, STDIN_FILENO);
//     close(cpy_fd);
//     close(fd[1]);
//     if (my_signal == 1)
//         return (close(fd[0]), 130);
//     return (fd[0]);
// }

int    ft_get_heredoc(char *delimiter, t_list *env, int *my_fd)
{
	char    *line;
    int		fd[2];
    int     fd_cpy;
    int     status;

    status = 0;
    fd_cpy = dup(STDIN_FILENO);
    signal(SIGQUIT, SIG_IGN);
    signal(SIGINT, &ft_signal_handler3);
    if (pipe(fd) == -1)
        return (ft_error(), errno);
    line = readline(">");
	while (line && ft_strcmp(line, delimiter) != 0)
	{
        line = ft_strjoin(ft_expand_string(line, env), "\n");
        if (!line)
        {
            status = 255;
            break;
        }
        ft_remove_quotes_string(line);
		ft_putstr_fd(line, fd[1]);
		free(line);
		line = readline(">");
	}
    if (status != 255)
        free(line);
    close (fd[1]);
    dup2(fd_cpy, STDIN_FILENO);
    close(fd_cpy);
    if (my_signal == 1)
        return (my_signal = 0, close(fd[0]), 130);
    if (status != 0)
        return (close(fd[0]), status);
    *my_fd = fd[0];
    return (0);
}

// int    ft_get_heredoc(char *delimiter, t_list *env, int *my_fd)
// {
// 	char    *line;
//     int		fd[2];
//     int     cpy_fd;

//     my_signal = 0;
//     cpy_fd = dup(STDIN_FILENO);
//     signal(SIGQUIT, SIG_IGN);
//     signal(SIGINT, &ft_signal_handler3);
//     if (pipe(fd) == -1)
//         return (ft_error(), errno);
//     line = readline(">");
// 	while (line && ft_strcmp(line, delimiter) != 0 && my_signal == 0)
// 	{
//         line = ft_expand_string(line, env);
//         ft_remove_quotes_string(line);
// 		ft_putstr_fd(line, fd[1]);
// 		free(line);
// 		line = readline(">");
// 	}
//     free(line);
//     close (fd[1]);
//     dup2(STDIN_FILENO, cpy_fd);
//     close(cpy_fd);
//     if (my_signal == 1)
//         return (my_signal = 0, close(fd[0]), 130);
//     *my_fd = fd[0];
//     return (0);
// }
