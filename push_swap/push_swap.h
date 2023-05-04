/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 22:11:02 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/05/05 00:08:30 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

int		check_input(char **arg);
t_stack	*create_stack(int ac, char **av);

int		absolute_nbr(int n);
int		ft_atoi(const char *s);
void	ft_putstr(char *s);
void	free_stack(t_stack **stack);
void	program_exit(t_stack **a, t_stack **b);

#endif