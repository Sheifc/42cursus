/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:17:39 by sheferna          #+#    #+#             */
/*   Updated: 2024/04/14 20:50:12 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	handle_heredoc(int argc, char **argv, char **envp, int *fd)
{
	int		i;
	pid_t	pid_last;
	int		heredocfd[2];

	i = 2;
	here_doc(argv[2], heredocfd);
	while (i++ < argc - 2)
		middle_child_process(argv, envp, heredocfd, i);
	pid_last = fork();
	if (pid_last == -1)
		ft_error("Last fork failed");
	else if (pid_last == 0)
		last_process_heredoc(argv, envp, heredocfd, argc);
	else if (close(fd[0]) == 0)
		waitpid(pid_last, NULL, 0);
}

static void	isvalid_cmd(int argc, char **argv)
{
	int		i;

	i = 1;
	while (i < argc) 
	{
		if (argv[i][0] == '\0' || argv[i] == NULL || argv[i][0] == ' ')
			ft_error("Command not found");
		i++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];

	isvalid_cmd(argc, argv);
	if (argc >= 5)
	{
		if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		{
			if (argc >= 6)
				handle_heredoc(argc, argv, envp, fd);
			else
				ft_error("The number of args is not correct");
		}
		else if (pipe(fd) == -1)
			ft_error("Create pipe failed");
		else
			ft_fork(argv, envp, fd, argc);
	}
	else
		ft_error("The number of args is not correct");
	return (0);
}
