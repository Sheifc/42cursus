/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:42:32 by sheferna          #+#    #+#             */
/*   Updated: 2024/04/12 10:52:38 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

void	execute_cmd(char *path, char **argv, char **envp)
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
