/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:53:04 by sheferna          #+#    #+#             */
/*   Updated: 2024/04/30 21:42:41 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_node
{
	int				data;
	int				index;
	int				position;
	int				target;
	int				cost_a;
	int				cost_b;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	t_node			*head;
}					t_stack;

// Parsing arguments
void	parse_arguments(char **argv, t_stack *stack_a);
void	add_to_stack(t_stack *stack, int num);

// Memory management and errors handling:
void	show_error(void);
void	ft_clean_error(t_stack *stack);
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
void	swap_ss(t_node **head_a, t_node **head_b);

void	push(t_node **head_a, t_node **head_b);

void	rotate(t_node **head);
void	rotate_rr(t_node **head_a, t_node **head_b);

void	reverse(t_node **head);
void	reverse_rrr(t_node **head_a, t_node **head_b);

// Print movements:
void	move_sa(t_node	**head_a);
void	move_sb(t_node	**head_b);
void	move_ss(t_node	**head_a, t_node **head_b);

void	move_pb(t_node **head_a, t_node **head_b);
void	move_pa(t_node **head_b, t_node **head_a);

void	move_ra(t_node **head_a);
void	move_rb(t_node **head_b);
void	move_rr(t_node **head_a, t_node **head_b);

void	move_rra(t_node **head_a);
void	move_rrb(t_node **head_b);
void	move_rrr(t_node **head_a, t_node **head_b);

// Calculating variables:
void	assign_index(t_node **head);
int		lowest_index(t_node **head);
void	assign_position(t_node **head);
void	assign_target(t_node **head_a, t_node **head_b);
void	assign_cost(t_node **head_a, t_node **head_b);
int		ft_stacksize(t_node *head);

// Sorting numbers:
void	sort_three(t_node **head);
void	sorting_algorithm(t_node **head_a, t_node **head_b);
void	sort(t_node **head_a, t_node **head_b);
void	push_all_b_leave_three(t_node **head_a, t_node **head_b);
t_node	*find_cheapest_node(t_node **head_b);
void	move_cheapest(t_node **head_a, t_node **head_b);
void	move_the_rest(t_node **head_a, t_node **head_b);

// Print for debugging:
void	ft_print_array(int *tab);
void	print_node(t_node *head_b);
void	print_pila(t_node **head);
void	print_index(t_node **head);
void	print_stack(t_stack *stack);
void	print_target(t_node **head);
void	print_all(t_node **head_a, t_node **head_b);
void	print_cheapest(t_node *node);

#endif