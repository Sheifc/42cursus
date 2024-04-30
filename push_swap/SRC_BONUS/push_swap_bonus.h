/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:58:18 by sheferna          #+#    #+#             */
/*   Updated: 2024/03/26 13:13:03 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_node
{
	int				data;
	int				index;
	int 			position;
	int				target;
	int 			cost_a;
	int				cost_b;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	t_node			*head;
}					t_stack;

typedef struct s_instruction
{
	char			*name;
	void			(*function)(t_node **, t_node **);
}					t_instruction;

// Parsing arguments
void	parse_arguments(char **argv, t_stack *stack_a);
void	add_to_stack(t_stack *stack, int num);

// Memory management and errors handling:
void	show_error(void);
void	ft_clean_error(t_stack *stack);
void	ft_clean_both_error(t_stack *stack_a, t_stack *stack_b);
void	free_stack(t_stack *stack);
void	ft_free_matrix(char **matrix);

// Parsing verifications:
int		is_in_stack(t_stack *stack, int num);
int		is_number_valid(char *str);
void	int_limit(long n);
int		is_sorted(t_node *head);
int		is_empty_or_space_only(const char *str);

// Movements:
void	swap(t_node **head_a);
void	swap_a_aux(t_node **head_a, t_node **head_b);
void	swap_b_aux(t_node **head_a, t_node **head_b);
void	swap_ss(t_node **head_a, t_node **head_b);

void	push(t_node **head_a, t_node **head_b);
void	push_a_aux(t_node **head_a, t_node **head_b);
void	push_b_aux(t_node **head_a, t_node **head_b);

void	rotate(t_node **head);
void	rotate_a_aux(t_node **head_a, t_node **head_b);
void	rotate_b_aux(t_node **head_a, t_node **head_b);
void	rotate_rr(t_node **head_a, t_node **head_b);

void	reverse(t_node **head);
void	reverse_a_aux(t_node **head_a, t_node **head_b);
void	reverse_b_aux(t_node **head_a, t_node **head_b);
void	reverse_rrr(t_node **head_a, t_node **head_b);

int		ft_stacksize(t_node *head);
void	aux_free(t_node **head_a, t_node **head_b);

void	init_instructions(t_instruction *instructions);
void	check_instructions(char *line, t_node **head_a, t_node **head_b);
void	verification(t_node **head_a, t_node **head_b);

#endif