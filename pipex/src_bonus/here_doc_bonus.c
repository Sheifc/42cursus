/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 14:30:44 by sheferna          #+#    #+#             */
/*   Updated: 2024/04/14 17:29:09 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	comparison(char *line, char *delim)
{
	while (line != NULL)
	{
		if (ft_strncmp(line, delim, ft_strlen(delim)) == 0)
		{
			free(line);
			break ;
		}
		free(line);
		line = get_next_line(0);
		write(1, line, ft_strlen(line));
	}
}

static void	parent_here_doc(int *fd, pid_t pidc)
{
	close(fd[1]);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		ft_error("Could not duplicate in here_doc");
	waitpid(pidc, NULL, 0);
}

void	here_doc(char *delim, int *heredocfd)
{
	pid_t	pidc;
	char	*line;

	if (pipe(heredocfd) == -1)
		ft_error("Could not create a pipe for here_doc");
	pidc = fork();
	if (pidc == -1)
		ft_error("Could not fork in here_doc");
	else if (pidc == 0)
	{
		close(heredocfd[0]);
		dup2(heredocfd[1], 1);
		line = get_next_line(0);
		write(1, line, ft_strlen(line));
		comparison(line, delim);
		exit(EXIT_SUCCESS);
	}
	else
		parent_here_doc(heredocfd, pidc);
}
