/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:43:01 by sheferna          #+#    #+#             */
/*   Updated: 2024/04/12 10:58:24 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

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
void	ft_fork(char **argv, char **envp, int *fd, int i);
// ------------ PROCESSES ---------------------------------
void	first_child_process(char **argv, char **envp, int *fd);
void	middle_child_process(char **argv, char **envp, int *fd, int i);
void	last_child_process(char **argv, char **envp, int *fd, int argc);
// ------------ Get COMMAND PATH --------------------------
char	**find_path(char **envp);
char	*get_cmd_path(char **path, char **argv);
// ------------ Parse COMMANDS ----------------------------
char	**cmd_split(char **argv);
// ------------ EXECUTE -----------------------------------
void	execute_cmd(char *cmd, char **argv, char **envp);
// ------------ HERE_DOC ----------------------------------
void	here_doc(char *argv, int *heredocfd);
void	last_process_heredoc(char **argv, char **envp, \
		int *heredocfd, int argc);

#endif
