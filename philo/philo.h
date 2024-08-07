/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:48:49 by sheferna          #+#    #+#             */
/*   Updated: 2024/07/31 15:07:17 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	int				meals_count;
	int				eating;
	long			death_time;
	long			last_meal;
	pthread_mutex_t	*print;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	meals_count_mutex;
	pthread_mutex_t	last_meal_mutex;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	t_philo			*philo;
	int				philo_number;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			start_time;
	int				n_times_must_eat;
	int				check_times_eat;
	int				dead;
	int				error;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	dead_mutex;
}					t_data;

/**********************INIT***************************/

int					parse_args(t_data *data, char **argv);
int					init_data(t_data *data);
int					init_philos(t_philo *philos, t_data *data);

/**********************UTILS**************************/

int					is_number(char c);
int					check_num(long num);
long				ft_atol(const char *str);
long				get_time(void);
void				ft_usleep(int time);
void				print_message(t_philo *philo, char *str);
int					print_error(char *msg, t_data *data);
void				ft_clean(t_data *data);

/**********************THREADS************************/

void				*routine(void *philo_ptr);
void				*monitor_routine(void *data_ptr);
int					one_philo(t_philo *philo);
int					create_threads(t_philo *philos, t_data *data);

int					check_times_eat(t_philo *philo);

int					get_dead(t_data *data);
void				set_dead(t_data *data, int dead);
int					get_all_full(t_data *data);
long				get_last_meal(t_philo *philo);
void				set_last_meal(t_philo *philo);
int					get_meals_count(t_philo *philo);

#endif
