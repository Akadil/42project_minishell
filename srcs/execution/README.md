```
typedef struct s_process
{
    t_type  *parts;

    t_env   *env;
    int     type; // Not sure
    int     in_fd;
    int     out_fd;
    int     err_fd;
    char    *path; 


}   t_process;
```

```
void    ft_prepare_pipe(t_data *data, int i_com)
{
    int i_in;
    int i_out;
    int fd[2];

    ft_handle_heredoc(data, i_com);

    // Indirection
    if (data->pipes.pipe_fd[1] != -1)
        data->pipes.in_fd = data->pipes.pipe_fd[1];
    i_in = 0;
    while (i_in < data->commands[i_com].infile_size)
    {
        if (i_in != 0)
            close(data->pipes.in_fd);                       // close unneeded onces
        if (data->commands[i_com].infile_mode[i_in] == 1)			// <
        {
            data->pipes.in_fd = open(data->commands[i_com].infile[i_in], O_RDONLY);
	        if (data->pipes.in_fd == -1)
		        ft_perror_clean_exit(data, data->commands[i_com].infile[i_in]);
        }
        else                                                // <<
        {
            data->pipes.in_fd = ft_atoi(data->commands[i_com].infile[i_in]);
			if (data->pipes.in_fd == -1)
				ft_perror_clean_exit(data, "Heredoc problems???\n");
        }
        i_in++;
    }

    // Outdirection
    if (data->num_commands > i_com + 1)
    {
        if (pipe(fd) == -1)
            exit(-1);                               // Handle this
        data->pipes.pipe_fd[0] = fd[0];
        data->pipes.pipe_fd[1] = fd[1];
    }
    else if (data->num_commands == i_com + 1)
    {
        data->pipes.pipe_fd[0] = 1;
        data->pipes.pipe_fd[1] = -1;
    }
    i_out = 0;
    while (i_out < data->commands[i_com].outfile_size)
    {
		if (i_out != 0)
            close(data->pipes.pipe_fd[0]);
        if (data->commands[i_com].outfile_mode[i_out] == 1)        // >
        {
            data->pipes.pipe_fd[0] = open(data->commands[i_com].outfile[i_out], O_WRONLY | O_CREAT | O_APPEND, 0666);
	        if (data->pipes.pipe_fd[0] == -1)
		        ft_perror_clean_exit(data, data->commands[i_com].outfile[i_out]); // This one should be different one
        }
        else                                                // <<
        {
            data->pipes.pipe_fd[0] = open(data->commands[i_com].outfile[i_out], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	        if (data->pipes.pipe_fd[0] == -1)
		        ft_perror_clean_exit(data, data->commands[i_com].outfile[i_out]); // This one too
        }
        i_out++;
    }
}
```