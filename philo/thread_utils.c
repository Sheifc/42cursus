/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:08:11 by sheferna          #+#    #+#             */
/*   Updated: 2024/07/31 15:15:41 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_dead(t_data *data)
{
	int	dead;

	if (pthread_mutex_lock(&data->dead_mutex) != 0)
		print_error("Error: pthread_mutex_lock failed\n", data);
	dead = data->dead;
	if (pthread_mutex_unlock(&data->dead_mutex) != 0)
		print_error("Error: pthread_mutex_unlock failed\n", data);
	return (dead);
}

void	set_dead(t_data *data, int dead)
{
	print_message(data->philo, "died");
	if (pthread_mutex_lock(&data->dead_mutex) != 0)
		print_error("pthread_mutex_lock failed\n", data);
	data->dead = dead;
	if (pthread_mutex_unlock(&data->dead_mutex) != 0)
		print_error("pthread_mutex_unlock failed\n", data);
}

long	get_last_meal(t_philo *philo)
{
	long	last_meal;

	if (pthread_mutex_lock(&philo->last_meal_mutex) != 0)
		print_error("Error: pthread_mutex_lock failed\n", philo->data);
	last_meal = philo->last_meal;
	if (pthread_mutex_unlock(&philo->last_meal_mutex) != 0)
		print_error("Error: pthread_mutex_unlock failed\n", philo->data);
	return (last_meal);
}

void	set_last_meal(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->last_meal_mutex) != 0)
		print_error("Error: pthread_mutex_lock failed\n", philo->data);
	philo->last_meal = get_time() - philo->data->start_time;
	if (pthread_mutex_unlock(&philo->last_meal_mutex) != 0)
		print_error("Error: pthread_mutex_unlock failed\n", philo->data);
}

int	get_meals_count(t_philo *philo)
{
	int	meals_count;

	if (pthread_mutex_lock(&philo->meals_count_mutex) != 0)
		print_error("Error: pthread_mutex_lock failed\n", philo->data);
	meals_count = philo->meals_count;
	if (pthread_mutex_unlock(&philo->meals_count_mutex) != 0)
		print_error("Error: pthread_mutex_unlock failed\n", philo->data);
	return (meals_count);
}
