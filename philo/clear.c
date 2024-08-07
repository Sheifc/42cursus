/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 22:00:55 by sheferna          #+#    #+#             */
/*   Updated: 2024/08/07 11:01:27 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clear_data(t_data	*data)
{
	if (data->forks)
		free(data->forks);
	if (data->philo)
		free(data->philo);
}

void	ft_clean(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_number)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philo[i].meals_count_mutex);
		pthread_mutex_destroy(&data->philo[i].last_meal_mutex);
	}
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->dead_mutex);
	clear_data(data);
}
