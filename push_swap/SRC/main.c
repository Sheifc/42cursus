/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:02:15 by sheferna          #+#    #+#             */
/*   Updated: 2024/04/30 21:36:06 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void	leaks(void)
{
	system("leaks -q push_swap");
} */

static void	args_check(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 2)
		return ;
	while (i < argc) 
	{
		if (is_empty_or_space_only(argv[i]))
			show_error();
		if ((!(argv[i][0]) || argv[i][0] == ' ' || argv[i][0] == '-' \
			|| argv[i][0] == '+') \
			&& (argv[i][1] == '\0' || !argv[i][1]))
			show_error();
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		i;
	int		size;
	//atexit(leaks);
	stack_a.head = NULL;
	stack_b.head = NULL;
	i = 1;
	args_check(argc, argv);
	while (i < argc)
		parse_arguments(&argv[i++], &stack_a);
	if (!is_sorted(stack_a.head))
	{
		size = ft_stacksize(stack_a.head);
		assign_index(&stack_a.head);
		if (size == 2)
			move_sa(&stack_a.head);
		else if (size == 3)
			sort_three(&stack_a.head);
		else if (size > 3)
			sorting_algorithm(&stack_a.head, &stack_b.head);
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
