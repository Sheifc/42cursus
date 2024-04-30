/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 10:58:02 by sheferna          #+#    #+#             */
/*   Updated: 2024/04/14 20:10:55 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**cmd_split(char **argv)
{
	int		count;
	char	**cmd_splitted;

	count = count_char_in_str(*argv, '\'');
	if (count == 2)
	{
		cmd_splitted = ft_split(*argv, '\'');
		cmd_splitted[0] = ft_strtrim(cmd_splitted[0], " ");
		return (cmd_splitted);
	}
	else
	{
		cmd_splitted = ft_split(*argv, ' ');
		return (cmd_splitted);
	}
}

void	ft_execute(char *path, char **argv, char **envp)
{
	char	**cmd;

	cmd = cmd_split(argv);
	if (!cmd)
	{
		free(path);
		ft_error("Error splitting command");
	}
	if (execve(path, cmd, envp) == -1)
	{
		ft_free_matrix(cmd);
		free(path);
		ft_error("Execute failed");
	}
}
