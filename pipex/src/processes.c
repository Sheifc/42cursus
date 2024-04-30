/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 10:56:04 by sheferna          #+#    #+#             */
/*   Updated: 2024/04/14 20:38:20 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process1(char **argv, char **envp, int *fd)
{
	int		infile_fd;
	char	*path;

	close(fd[0]);
	infile_fd = open(argv[1], O_RDONLY);
	if (infile_fd == -1)
		ft_error("Could not open the infile");
	if ((dup2(infile_fd, STDIN_FILENO)) == -1)
		ft_error("Could not redirect infile_fd");
	close(infile_fd);
	if ((dup2(fd[1], STDOUT_FILENO)) == -1)
		ft_error("Could not redirect fd 1");
	close(fd[1]);
	path = get_cmd_path(argv[2], envp);
	if (!path)
		ft_error("Command not found");
	ft_execute(path, &argv[2], envp);
	exit(EXIT_SUCCESS);
}

void	child_process2(char **argv, char **envp, int *fd)
{
	int		outfile_fd;
	char	*path;

	close(fd[1]);
	outfile_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile_fd == -1)
		ft_error("Could not open outfile_fd");
	if ((dup2(fd[0], STDIN_FILENO)) == -1)
		ft_error("Could not redirect fd 0");
	close(fd[0]);
	if ((dup2(outfile_fd, STDOUT_FILENO)) == -1)
		ft_error("Could not redirect outfile_fd");
	close(outfile_fd);
	path = get_cmd_path(argv[3], envp);
	if (!path)
		ft_error("Command not found");
	ft_execute(path, &argv[3], envp);
	exit(EXIT_SUCCESS);
}
