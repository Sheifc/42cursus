/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:42:03 by sheferna          #+#    #+#             */
/*   Updated: 2024/04/12 10:47:29 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	first_child_process(char **argv, char **envp, int *fd)
{
	int		fdin;
	char	**paths;
	char	*path;

	close(fd[0]);
	fdin = open(argv[1], O_RDONLY);
	if (fdin == -1)
		ft_error("Could not open the infile");
	if (dup2(fdin, STDIN_FILENO) == -1)
		ft_error("Redirection fdin failed");
	close(fdin);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		ft_error("Redirection fd 1 in first child failed");
	close(fd[1]);
	paths = find_path(envp);
	path = get_cmd_path(paths, &argv[2]);
	ft_free_matrix(paths);
	execute_cmd(path, &argv[2], envp);
	exit(EXIT_SUCCESS);
}

static void	path_exec(char **argv, char **envp, int i)
{
	char	**paths;
	char	*path;

	paths = find_path(envp);
	path = get_cmd_path(paths, &argv[i]);
	ft_free_matrix(paths);
	execute_cmd(path, &argv[i], envp);
}

void	middle_child_process(char **argv, char **envp, int *fd, int i)
{
	pid_t	pid;
	int		middlefd[2];

	if (pipe(middlefd) == -1)
		ft_error("pipe failed");
	pid = fork();
	if (pid == 0)
	{
		close(fd[1]);
		close(middlefd[0]);
		if (dup2(fd[0], STDIN_FILENO) == -1)
			ft_error("Redirection fd 0 in middle process failed");
		close(fd[0]);
		if (dup2(middlefd[1], STDOUT_FILENO) == -1)
			ft_error("Redirection middlefd 1 failed");
		close(middlefd[1]);
		path_exec(argv, envp, i);
		exit(EXIT_SUCCESS);
	}
	close(middlefd[1]);
	waitpid(pid, NULL, 0);
	fd[0] = middlefd[0];
	fd[1] = middlefd[1];
}

void	last_child_process(char **argv, char **envp, int *fd, int argc)
{
	char	**paths;
	char	*path;
	int		fdout;

	close(fd[1]);
	fdout = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fdout == -1)
		ft_error("Could not open the outfile");
	if (dup2(fd[0], STDIN_FILENO) == -1)
		ft_error("dup2 fd 0 failed");
	close(fd[0]);
	if (dup2(fdout, STDOUT_FILENO) == -1)
		ft_error("dup2 outfile fd failed");
	close(fdout);
	paths = find_path(envp);
	path = get_cmd_path(paths, &argv[argc - 2]);
	ft_free_matrix(paths);
	execute_cmd(path, &argv[argc - 2], envp);
	exit(EXIT_SUCCESS);
}

void	last_process_heredoc(char **argv, char **envp, int *fd, int argc)
{
	char	**paths;
	char	*path;
	int		fdout;

	close(fd[1]);
	fdout = open(argv[argc - 1], O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fdout == -1)
		ft_error("Could not open the outfile");
	if (dup2(fd[0], STDIN_FILENO) == -1)
		ft_error("dup2 fd 0 failed");
	close(fd[0]);
	if (dup2(fdout, STDOUT_FILENO) == -1)
		ft_error("dup2 outfile fd failed");
	close(fdout);
	paths = find_path(envp);
	path = get_cmd_path(paths, &argv[argc - 2]);
	ft_free_matrix(paths);
	execute_cmd(path, &argv[argc - 2], envp);
	exit(EXIT_SUCCESS);
}
