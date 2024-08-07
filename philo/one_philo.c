/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 09:38:13 by sheferna          #+#    #+#             */
/*   Updated: 2024/07/31 21:49:46 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	one_philo(t_philo *philo)
{
	philo->data->start_time = get_time();
	if (pthread_create(&philo[0].thread, NULL, &routine, \
			(void *)&philo[0]) != 0)
	{
		printf("Error: pthread_create failed for philosopher\n");
		philo->data->dead = 1;
		return (1);
	}
	if (pthread_join(philo[0].thread, NULL) != 0)
	{
		printf("Error: pthread_join failed for philosopher\n");
		return (1);
	}
	return (0);
}
