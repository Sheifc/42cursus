/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 10:58:47 by sheferna          #+#    #+#             */
/*   Updated: 2024/04/06 14:46:43 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**get_path(char **envp)
{
	char	*full_path;
	char	**path_splitted;

	full_path = NULL;
	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
		{
			full_path = (*envp + 5);
			break ;
		}
		envp++;
	}
	if (!full_path)
		ft_error("Error getting the variable path in envp");
	path_splitted = ft_split(full_path, ':');
	return (path_splitted);
}

char	*get_cmd_path(char *argv, char **envp)
{
	char	**cmd;
	char	**paths;
	char	*cmd_path;
	int		i;

	i = 0;
	cmd_path = NULL;
	paths = get_path(envp);
	cmd = ft_split(argv, ' ');
	while (paths[i])
	{
		cmd_path = ft_strjoin(ft_strjoin(paths[i], "/"), cmd[0]);
		if (!access(cmd_path, X_OK))
			break ;
		free(cmd_path);
		cmd_path = NULL;
		i++;
	}
	ft_free_matrix(paths);
	return (cmd_path);
}
