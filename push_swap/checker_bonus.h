/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 05:01:15 by heejikim          #+#    #+#             */
/*   Updated: 2022/11/25 05:10:00 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
# include "push_swap.h"

// checker_bonus.c
int		checker(t_stack *stack);
void	flush(t_stack *stack, char **str, int *err, size_t *len);
void	clear_buf(char *str, int *err);
char	*ft_realloc(char *old, size_t new_len);
void	check_result(t_stack *stack);

#endif
