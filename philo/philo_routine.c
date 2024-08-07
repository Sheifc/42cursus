/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:58:36 by sheferna          #+#    #+#             */
/*   Updated: 2024/08/07 11:05:56 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		if (pthread_mutex_lock(philo->left_fork) != 0)
		{
			print_error("Error: pthread_mutex_lock failed\n", philo->data);
			return ;
		}
		print_message(philo, "has taken a fork");
		if (pthread_mutex_lock(philo->right_fork) != 0
			|| philo->data->error == 1)
			print_error("Error: pthread_mutex_lock failed\n", philo->data);
		print_message(philo, "has taken a fork");
	}
	else
	{
		if (pthread_mutex_lock(philo->right_fork) != 0
			|| philo->data->error == 1)
			print_error("Error: pthread_mutex_lock failed\n", philo->data);
		print_message(philo, "has taken a fork");
		if (pthread_mutex_lock(philo->left_fork) != 0
			|| philo->data->error == 1)
			print_error("Error: pthread_mutex_lock failed\n", philo->data);
		print_message(philo, "has taken a fork");
	}
}

static void	drop_forks(t_philo *philo)
{
	if (pthread_mutex_unlock(philo->left_fork) != 0 || philo->data->error == 1)
		print_error("pthread_mutex_unlock failed\n", philo->data);
	if (pthread_mutex_unlock(philo->right_fork) != 0 || philo->data->error == 1)
		print_error("pthread_mutex_unlock failed\n", philo->data);
}

static int	eat(t_philo *philo)
{
	take_forks(philo);
	print_message(philo, "is eating");
	set_last_meal(philo);
	if (pthread_mutex_lock(&philo->meals_count_mutex) != 0
		|| philo->data->error == 1)
		print_error("Error: pthread_mutex_lock failed\n", philo->data);
	philo->meals_count++;
	if (pthread_mutex_unlock(&philo->meals_count_mutex) != 0
		|| philo->data->error == 1)
		print_error("Error: pthread_mutex_unlock failed\n", philo->data);
	ft_usleep(philo->data->time_to_eat);
	drop_forks(philo);
	if (philo->data->error == 1)
		return (1);
	return (0);
}

int	check_times_eat(t_philo *philo)
{
	if (philo->data->n_times_must_eat == -1)
		return (1);
	if (get_meals_count(philo) < philo->data->n_times_must_eat)
		return (1);
	return (0);
}

void	*routine(void *philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *)philo_ptr;
	if (philo->data->philo_number == 1)
	{
		print_message(philo, "has taken a fork");
		ft_usleep(philo->data->time_to_die);
		print_message(philo, "died");
		return (NULL);
	}
	else if (philo->id % 2 == 0)
		ft_usleep(50);
	while ((get_dead(philo->data) == 0) && (check_times_eat(philo) == 1)
		&& (philo->data->error == 0))
	{
		if (eat(philo) == 1)
			return (NULL);
		if (!get_dead(philo->data) && philo->data->error == 0)
		{
			print_message(philo, "is sleeping");
			ft_usleep(philo->data->time_to_sleep);
			print_message(philo, "is thinking");
		}
	}
	return (NULL);
}
