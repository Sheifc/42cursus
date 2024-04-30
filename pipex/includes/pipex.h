/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 11:22:29 by sheferna          #+#    #+#             */
/*   Updated: 2024/04/12 10:54:17 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/wait.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"

// ------------ MAIN function -----------------------------
int		main(int argc, char **argv, char **envp);
// ------------ UTILS -------------------------------------
void	ft_error(char *msg);
int		wait_and_report(pid_t pid);
int		count_char_in_str(char *str, int c);
// ------------ FORK --------------------------------------
void	ft_fork(char **argv, char **envp, int *fd);
// ------------ PROCESSES ---------------------------------
void	child_process1(char **argv, char **envp, int *fd);
void	child_process2(char **argv, char **envp, int *fd);
// ------------ Get COMMAND PATH --------------------------
char	*get_cmd_path(char *argv, char **envp);
// ------------ Parse COMMANDS ----------------------------
char	**cmd_split(char **argv);
// ------------ EXECUTE -----------------------------------
void	ft_execute(char *path, char **argv, char **envp);

#endif