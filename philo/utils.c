/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:03:03 by sheferna          #+#    #+#             */
/*   Updated: 2024/07/31 15:00:32 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	time;
	long			result;

	gettimeofday(&time, NULL);
	result = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (result);
}

void	ft_usleep(int time)
{
	long	start;

	start = get_time();
	while (get_time() - start < time)
		usleep(time / 10);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(char *)s1 - *(char *)s2);
}

void	print_message(t_philo *philo, char *str)
{
	long	time;

	time = get_time() - philo->data->start_time;
	if (get_dead(philo->data) == 0)
	{
		if (pthread_mutex_lock(philo->print) != 0)
			print_error("pthread_mutex_lock failed\n", philo->data);
		printf("%ld %d %s\n", time, philo->id, str);
		if (ft_strcmp(str, "died"))
		{
			if (pthread_mutex_unlock(philo->print))
				print_error("pthread_mutex_unlock failed\n", philo->data);
		}
		else
		{
			if (pthread_mutex_unlock(philo->print))
				print_error("pthread_mutex_unlock failed\n", philo->data);
		}
	}
}
