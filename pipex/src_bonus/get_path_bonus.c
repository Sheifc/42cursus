/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:42:45 by sheferna          #+#    #+#             */
/*   Updated: 2024/04/14 20:40:00 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	**find_path(char **envp)
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

char	*get_cmd_path(char **path, char **argv)
{
	int		i;
	char	*cmd_path;
	char	**split_cmd;

	i = 0;
	split_cmd = cmd_split(argv);
	while (path[i])
	{
		cmd_path = ft_strjoin(ft_strjoin(path[i], "/"), split_cmd[0]);
		if (access(cmd_path, X_OK) == 0)
			break ;
		free(cmd_path);
		cmd_path = NULL;
		i++;
	}
	if (path[i] == NULL)
		ft_error("Command not found");
	return (cmd_path);
}
