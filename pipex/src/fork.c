/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 10:55:17 by sheferna          #+#    #+#             */
/*   Updated: 2024/04/14 17:39:20 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_fork(char **argv, char **envp, int *fd)
{
	pid_t	pidc1;
	pid_t	pidc2;

	pidc1 = fork();
	if (pidc1 == -1)
		ft_error("Could not fork first time");
	else if (pidc1 == 0)
		child_process1(argv, envp, fd);
	else
	{
		close(fd[1]);
		waitpid(pidc1, NULL, 0);
		pidc2 = fork();
		if (pidc2 == -1)
			ft_error("Could not fork second time");
		else if (pidc2 == 0)
			child_process2(argv, envp, fd);
		else
		{
			close(fd[0]);
			waitpid(pidc2, NULL, 0);
		}
	}
}
