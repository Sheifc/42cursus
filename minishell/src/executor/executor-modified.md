#include "minishell.h"

void	redirection(t_cmd *current, int tmpout, int last_cmd)
{
	int fdpipe[2];

	dup2(current->fdin, 0);
	close(current->fdin);
	if (last_cmd)
	{
		if (current->fdout == -1)
			current->fdout = dup(tmpout);
	}
	else
	{
		pipe(fdpipe);
		current->next->fdin = fdpipe[0];
		if (current->fdout == -1)
			current->fdout = fdpipe[1];
		else
			close(fdpipe[1]);
	}
	dup2(current->fdout, 1);
	close(current->fdout);
}

void	child_one_cmd(t_shell *data, t_cmd *current, int i, int fdpipe)
{
	data->pid[i] = fork();
	if (data->pid[i] == 0)
	{
		get_path(data, current);
		if (!data->path)
		{
			perror("Error: command not found");
			exit(errno);
		}
		execve(data->path, current->arg, data->envp);
		perror("Error: execve failed");
		exit(errno);
	}
	else if (data->pid[i] < 0)
		perror("Error: fork failed");
	else
		if (i < data->cmd_count - 1)
			close(fdpipe);
}

void	child(t_shell *data, t_cmd *current, int i, int fdpipe)
{		
	data->pid[i] = fork();
	if (data->pid[i] == 0)
	{
		if (!execute_builtin(data))
		{
			get_path(data, current);
			if (!data->path)
			{
				perror("Error: command not found");
				exit(errno);
			}
			execve(data->path, current->arg, data->envp);
			perror("Error: execve failed");
			exit(errno);
		}
		else
			exit(data->status);
	}
	else if (data->pid[i] < 0)
		perror("Error: fork failed");
	else
		if (i < data->cmd_count - 1)
			close(fdpipe);
}

void restart_fds(int tmpin, int tmpout)
{	
	dup2(tmpin, 0);
	dup2(tmpout, 1);
	close(tmpin);
	close(tmpout);
}

void	execute_one_cmd(t_shell *data, t_cmd *current, int i, int tmpout)
{
	int	fdpipe[2];

	if (!execute_builtin(data))
	{
		redirection(current, tmpout, data->cmd_count - 1 == i);
		child_one_cmd(data, current, i, fdpipe[1]);
	}
}

void	execute_more_cmds(t_shell *data, t_cmd *current, int i, int tmpout)
{
	int	fdpipe[2];

	while (++i < data->cmd_count)
	{
		redirection(current, tmpout, data->cmd_count - 1 == i);
		child(data, current, i, fdpipe[1]);
		data->cmd_count--;
		current = current->next;
	}
}

void executor(t_shell *data)
{
	int tmpin;
	int tmpout;
	int i;
	t_cmd *current;

	i = -1;
	count_commands(data);
	init_pid(data);
	current = data->cmd;
	if (!current)
		return ;
	tmpin = dup(0);
	tmpout = dup(1);
	if (current->fdin == -1)
		current->fdin = dup(tmpin);
	if (data->cmd_count == 1)
		execute_one_cmd(data, current, i, tmpout);
	else
		execute_more_cmds(data, current, i, tmpout);
	waitpid(data->pid[data->cmd_count-1], &data->status, 0);
	data->status = WEXITSTATUS(data->status);
	end_processess(data->pid, data->cmd_count - 1);
	restart_fds(tmpin, tmpout);
}
