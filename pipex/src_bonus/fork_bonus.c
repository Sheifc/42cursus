/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:42:20 by sheferna          #+#    #+#             */
/*   Updated: 2024/04/14 17:38:06 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_fork(char **argv, char **envp, int *fd, int argc)
{
	pid_t	pid_first;
	pid_t	pid_last;
	int		i;

	i = 2;
	pid_first = fork();
	if (pid_first == -1)
		ft_error("Fork failed");
	else if (pid_first == 0)
		first_child_process(argv, envp, fd);
	else
	{
		close(fd[1]);
		waitpid(pid_first, NULL, 0);
		while (++i < argc - 2)
			middle_child_process(argv, envp, fd, i);
		pid_last = fork();
		if (pid_last == -1)
			ft_error("Last fork failed");
		else if (pid_last == 0)
			last_child_process(argv, envp, fd, argc);
		else if (close(fd[0]) == 0)
			waitpid(pid_last, NULL, 0);
	}
}
