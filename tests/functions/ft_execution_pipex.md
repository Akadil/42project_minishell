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

```c
#include "ft_execution_findPath.h"


/*
		Find the path for given command
*/
char	*ft_find_path_exit(t_data *my_data, char *full_cmd)
{
	char	*possible_path;
	char	*cmd_wo_flag; // Command without flag
	int		i;

	cmd_wo_flag = ft_extract_command_exit(my_data, full_cmd);
	i = 0;
	while (my_data->paths[i] && cmd_wo_flag[0] != '\0') // Second one to handle empty commands
	{
		possible_path = ft_strjoin(my_data->paths[i++], cmd_wo_flag);
		if (!possible_path)
			ft_free_perror_exit(my_data, cmd_wo_flag);
		if (access(possible_path, X_OK) == 0)
			return (possible_path);
		free(possible_path);
		if (errno != 2) // errno = 2 is "No such file or directory"
			ft_free_perror2_exit(my_data, cmd_wo_flag, full_cmd);
	}
	if (full_cmd[0] == '\\')
		ft_merror("bash: %s: No such file or directory\n", full_cmd);
	else
		ft_merror("%s: command not found\n", full_cmd);
	return (free(cmd_wo_flag), ft_clean_exit(my_data), NULL);
}

/*
		Remove all the flags from command
*/
static char	*ft_extract_command_exit(t_data *my_data, char *_arg)
{
	char	*command;
	int		size;
	int		i;

	size = 0;
	while (_arg && _arg[size] != '\0' && _arg[size] != ' ')
		size++;
	command = (char *)malloc(sizeof(char) * (size + 1));
	if (!command)
		ft_perror_clean_exit(my_data, "Malloc failed in child process");
	i = 0;
	while (i < size)
	{
		command[i] = _arg[i];
		i++;
	}
	command[i] = '\0';
	return (command);
}

/*
		To handle the errors
*/
static void	ft_free_perror_exit(t_data *my_data, char *_command)
{
	free(_command);
	ft_perror_clean_exit(my_data, "Malloc failed in child process");
}

static void	ft_free_perror2_exit(t_data *my_data, char *_command,
		char *full_command)
{
	ft_perror(full_command);
	free(_command);
	ft_clean_exit(my_data);
}
```