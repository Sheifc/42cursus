/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:54:32 by sheferna          #+#    #+#             */
/*   Updated: 2024/07/31 20:55:58 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	alloc_philo(t_philo **philos, t_data *data)
{
	*philos = (t_philo *)malloc(sizeof(t_philo) * data->philo_number);
	if (!*philos)
	{
		print_error("Error: malloc failed for one philo\n", data);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philos;

	if (argc < 5 || argc > 6)
	{
		printf("Error: Wrong number of arguments " \
			"you must enter 4 or 5 arguments\n");
		return (1);
	}
	philos = NULL;
	if (init_data(&data) != 0)
		return (1);
	if (parse_args(&data, argv) != 0)
		return (1);
	if (alloc_philo(&philos, &data) != 0)
		return (1);
	if (init_philos(philos, &data) != 0)
		return (1);
	if (data.philo_number == 1)
		one_philo(&philos[0]);
	else
		create_threads(philos, &data);
	ft_clean(&data);
	return (0);
}
