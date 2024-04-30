/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 11:30:39 by sheferna          #+#    #+#             */
/*   Updated: 2024/04/14 20:44:15 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		i;

	i = 1;
	while (i < argc) 
	{
		if (argv[i][0] == '\0' || argv[i] == NULL || argv[i][0] == ' ')
			ft_error("Command not found");
		i++;
	}
	if (argc == 5)
	{
		if (pipe(fd) == -1)
			ft_error("Could not create pipe");
		else
			ft_fork(argv, envp, fd);
	}
	else
		ft_error("The number of args is not correct");
	return (0);
}
