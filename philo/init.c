/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:52:57 by sheferna          #+#    #+#             */
/*   Updated: 2024/08/07 11:04:54 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parse_args(t_data *data, char **argv)
{
	data->philo_number = (int)ft_atol(argv[1]);
	data->time_to_die = ft_atol(argv[2]);
	data->time_to_eat = ft_atol(argv[3]);
	data->time_to_sleep = ft_atol(argv[4]);
	if (argv[5])
	{
		data->n_times_must_eat = (int)ft_atol(argv[5]);
		data->check_times_eat = 1;
	}
	else
		data->n_times_must_eat = -1;
	if (data->philo_number == -2 || data->time_to_die == -2 \
		|| data->time_to_eat == -2 || data->time_to_sleep == -2 \
		|| data->n_times_must_eat == -2)
		return (1);
	return (0);
}

int	init_data(t_data *data)
{
	data->philo = NULL;
	data->philo_number = 0;
	data->time_to_die = 0;
	data->time_to_eat = 0;
	data->time_to_sleep = 0;
	data->start_time = 0;
	data->n_times_must_eat = 0;
	data->check_times_eat = 0;
	data->dead = 0;
	data->error = 0;
	data->forks = NULL;
	if (pthread_mutex_init(&data->print, NULL))
		print_error("Error: pthread_mutex_init failed\n", data);
	if (pthread_mutex_init(&data->dead_mutex, NULL))
		print_error("Error: pthread_mutex_init failed\n", data);
	return (data->error);
}

static int	init_philo(t_philo *philo, pthread_mutex_t *forks, \
int i, t_data *data)
{
	philo->id = i + 1;
	philo->meals_count = 0;
	philo->eating = 0;
	philo->death_time = 0;
	philo->last_meal = 0;
	philo->left_fork = &forks[i];
	philo->right_fork = &forks[(i + 1) % data->philo_number];
	philo->data = data;
	philo->print = &data->print;
	if (pthread_mutex_init(&philo->meals_count_mutex, NULL))
		print_error("Error: pthread_mutex_init failed\n", data);
	if (pthread_mutex_init(&philo->last_meal_mutex, NULL))
		print_error("Error: pthread_mutex_init failed\n", data);
	return (data->error);
}

int	init_philos(t_philo *philos, t_data *data)
{
	int				i;

	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
		* data->philo_number);
	if (!data->forks)
	{
		print_error("Error: malloc failed for forks\n", data);
		return (1);
	}
	i = -1;
	while (++i < data->philo_number)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			print_error("Error: pthread_mutex_init failed\n", data);
			return (1);
		}
	}
	i = -1;
	while (++i < data->philo_number)
		init_philo(&philos[i], data->forks, i, data);
	data->philo = philos;
	return (data->error);
}
