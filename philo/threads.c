/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 20:45:31 by sheferna          #+#    #+#             */
/*   Updated: 2024/07/31 19:26:27 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	create_philo_threads(t_philo *philos, t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_number)
	{
		if (pthread_create(&philos[i].thread, NULL, &routine,
				(void *)&philos[i]) != 0)
		{
			data->dead = 1;
			print_error("pthread_create failed for philosopher\n", data);
			return (1);
		}
	}
	return (0);
}

static int	join_philo_threads(t_philo *philos, t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_number)
	{
		if (pthread_join(philos[i].thread, NULL) != 0)
		{
			print_error("pthread_join failed for philosopher\n", data);
			return (1);
		}
	}
	return (0);
}

static int	create_monitor_thread(t_data *data)
{
	pthread_t	monitor_thread;

	if (pthread_create(&monitor_thread, NULL, \
		&monitor_routine, (void *)data) != 0)
	{
		print_error("pthread_create failed for monitor\n", data);
		data->dead = 1;
		return (1);
	}
	else
	{
		if (pthread_detach(monitor_thread) != 0)
		{
			print_error("pthread_detach failed for monitor\n", data);
			return (1);
		}
	}
	return (0);
}

int	create_threads(t_philo *philos, t_data *data)
{
	data->start_time = get_time();
	if (create_philo_threads(philos, data))
		return (1);
	if (create_monitor_thread(data))
		return (1);
	if (join_philo_threads(philos, data))
		return (1);
	return (0);
}
