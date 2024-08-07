/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 09:36:34 by sheferna          #+#    #+#             */
/*   Updated: 2024/07/31 19:24:08 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor_routine(void *data_ptr)
{
	t_data	*data;
	int		i;

	data = (t_data *)data_ptr;
	while (!get_dead(data) && data->error == 0)
	{
		i = -1;
		while (++i < data->philo_number && !get_dead(data))
		{
			if (data->time_to_die < ((get_time() - data->start_time) \
				- get_last_meal(&data->philo[i])))
			{
				set_dead(data, 1);
				return (NULL);
			}
			if (get_meals_count(&data->philo[i]) == data->n_times_must_eat)
				return (NULL);
		}
		ft_usleep(10);
	}
	return (NULL);
}
