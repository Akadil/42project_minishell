```c
void	ft_exec_command(t_data *my_data, char *command)
{
	char	*command_path;
	char	**splitted_command;
	int		pid;

	pid = fork();
	if (pid < -1)
		ft_perror_clean_exit(my_data, "Fork failed");
	if (pid == 0)
	{
		if (dup2(my_data->prev_fd, STDIN_FILENO) == -1)
			ft_perror_clean_exit(my_data, "Dup2 failed for child process");
		if (dup2(my_data->pipe_fd[1], STDOUT_FILENO) == -1)
			ft_perror_clean_exit(my_data, "Dup2 failed for child process");
		ft_clean_fds(my_data);
		command_path = ft_find_path_exit(my_data, command);
		splitted_command = ft_split(command, ' ');
		if (!splitted_command)
			ft_perror_clean_exit(my_data, "Malloc failed");
		if (execve(command_path, splitted_command, NULL) == -1)
			ft_perror_clean_exit(my_data, "Execve failed");
	}
	else
		close(my_data->prev_fd); // this fd is input pipe for above exec command 
}
```