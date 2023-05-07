/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 22:11:02 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/05/07 01:17:06 by wcorrea-         ###   ########.fr       */
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
	int				nb;
	int				id;
	int				ps;
	int				tg;
	int				mb;
	int				ma;
	struct s_stack	*nx;
}					t_stack;

int			is_correct_input(char **arg);
int			get_stack_size(t_stack *st);
t_stack		*create_stack(int ac, char **av);
void		define_index(t_stack *sa, int size);
int			is_sorted(t_stack *st);

void		swap_2(t_stack **sa, t_stack **sb, char *choice);
void		swap_3(t_stack **st);
void		rotate_3(t_stack **sa, t_stack **sb, char *choice);
void		above_3(t_stack **sa, t_stack **sb);

void		sort_with_less_moves(t_stack **sa, t_stack **sb);
int			get_lower_position(t_stack **st);
void		get_target_position(t_stack **sa, t_stack **sb);
void		define_need_moves(t_stack **sa, t_stack **sb);

int			ft_strcmp(char *s1, char *s2);
int			absolute(int n);
long int	ft_atoi(const char *s);
void		ft_putstr(char *s);
void		free_stack(t_stack **st);
void		print_error_and_exit(t_stack **sa, t_stack **sb);

#endif