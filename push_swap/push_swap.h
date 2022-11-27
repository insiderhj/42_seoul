/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 22:10:57 by heejikim          #+#    #+#             */
/*   Updated: 2022/11/25 17:45:56 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>

typedef struct s_elem {
	int				val;
	struct s_elem	*up;
	struct s_elem	*down;
}	t_elem;

typedef struct s_stack {
	t_elem	*ta;
	t_elem	*tb;
	size_t	size_total;
	size_t	size_a;
	size_t	size_b;
}	t_stack;

typedef struct s_info {
	size_t	op_count;
	size_t	ra_n;
	size_t	rb_n;
	size_t	rra_n;
	size_t	rrb_n;
}	t_info;

// ft_utils.c
int			ft_strcmp(const char *s1, const char *s2);
size_t		ft_strlen(const char *str);
int			ft_atoi(const char *str);
int			ft_check_num(const t_stack *stack, const char *str);
void		print_op(char *op);

// push_swap.c
void		push_swap(t_stack *stack);
void		push_a(t_stack *stack, t_info info);
void		print_stack(t_stack *stack);
void		final_rotate(t_stack *stack);
void		repeat_op(t_stack *stack, char *op, size_t count);

// calculator.c
t_info		calc_min_ops(t_stack *stack);
size_t		count_ra(t_stack *stack, int val);
t_info		update_min(t_stack *stack, t_info res, size_t ra_n, size_t rb_n);
t_info		create_info(size_t ra_n, size_t rb_n, size_t rra_n, size_t rrb_n);
size_t		max(size_t a, size_t b);

// stack.c
t_elem		*create_elem(int val);
int			insert_elem(t_stack *stack, char *str);
int			ft_find(t_elem *top, int val);

// stack_ops.c
void		push(t_elem **top, t_elem *new);
t_elem		*pop(t_elem **top);
void		swap(t_elem **top);
void		rotate(t_elem **top);
void		rrotate(t_elem **top);

// stack_ops_2.c
int			do_op(t_stack *stack, char *op, int print);
int			do_op_push(t_stack *stack, char *op);
int			do_op_rotate(t_stack *stack, char *op);

// memory_manager.c
t_stack		*create_stack(void);
void		free_elems(t_elem *start);
int			free_stack(t_stack *stack, int print_error);

#endif
