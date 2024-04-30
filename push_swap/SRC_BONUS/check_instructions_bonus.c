/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instructions_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 20:29:50 by sheferna          #+#    #+#             */
/*   Updated: 2024/04/30 21:44:04 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	init_instructions(t_instruction *instructions)
{
	instructions[0] = (t_instruction){"sa\n", swap_a_aux};
	instructions[1] = (t_instruction){"sb\n", swap_b_aux};
	instructions[2] = (t_instruction){"ss\n", swap_ss};
	instructions[3] = (t_instruction){"ra\n", rotate_a_aux};
	instructions[4] = (t_instruction){"rb\n", rotate_b_aux};
	instructions[5] = (t_instruction){"rr\n", rotate_rr};
	instructions[6] = (t_instruction){"pa\n", push_a_aux};
	instructions[7] = (t_instruction){"pb\n", push_b_aux};
	instructions[8] = (t_instruction){"rra\n", reverse_a_aux};
	instructions[9] = (t_instruction){"rrb\n", reverse_b_aux};
	instructions[10] = (t_instruction){"rrr\n", reverse_rrr};
	instructions[11] = (t_instruction){NULL, NULL};
}

void	verification(t_node **head_a, t_node **head_b)
{
	if (is_sorted(*head_a) && (ft_stacksize(*head_b)) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

void	aux_free(t_node **head_a, t_node **head_b) 
{
    t_stack stack_a = { .head = *head_a };
    t_stack stack_b = { .head = *head_b };
	ft_clean_both_error(&stack_a, &stack_b);
}

void	check_instructions(char *line, t_node **head_a, t_node **head_b)
{
	t_instruction	instructions[12];
	int				i;
	int				flag;

	i = 0;
	flag = 0;
	init_instructions(instructions);
	while (instructions[i].name != NULL)
	{
		if (ft_strncmp(line, instructions[i].name, \
			ft_strlen(instructions[i].name)) == 0)
		{
			instructions[i].function(head_a, head_b);
			flag = 1;
			break ;
		}
		i++;
	}
	free(line);
	if (!flag)
		aux_free(head_a, head_b);
}
