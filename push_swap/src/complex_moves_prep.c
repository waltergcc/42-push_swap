/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_moves_prep.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 01:08:50 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/05/07 16:53:26 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_moves(t_stack **sa, t_stack **sb)
{
	t_stack	*a;
	t_stack	*b;
	int		size_a;
	int		size_b;

	a = *sa;
	b = *sb;
	size_a = get_stack_size(a);
	size_b = get_stack_size(b);
	while (b)
	{
		b->mv_b = b->position;
		if (b->position > size_b / 2)
			b->mv_b = (size_b - b->position) * -1;
		b->mv_a = b->where_fit;
		if (b->where_fit > size_a / 2)
			b->mv_a = (size_a - b->where_fit) * -1;
		b = b->next;
	}
}

int	get_a_position(t_stack **sa, int b_index, int max, int a_pos)
{
	t_stack	*a;

	a = *sa;
	while (a)
	{
		if (a->main_index > b_index && a->main_index < max)
		{
			max = a->main_index;
			a_pos = a->position;
		}
		a = a->next;
	}
	if (max != INT_MAX)
		return (a_pos);
	a = *sa;
	while (a)
	{
		if (a->main_index < max)
		{
			max = a->main_index;
			a_pos = a->position;
		}
		a = a->next;
	}
	return (a_pos);
}

void	get_stack_positions(t_stack **st)
{
	t_stack	*s;
	int		i;

	s = *st;
	i = 0;
	while (s)
	{
		s->position = i;
		s = s->next;
		i++;
	}
}

void	where_fit_in_a(t_stack **sa, t_stack **sb)
{
	t_stack	*b;
	int		a_pos;

	b = *sb;
	get_stack_positions(sa);
	get_stack_positions(sb);
	a_pos = 0;
	while (b)
	{
		a_pos = get_a_position(sa, b->main_index, INT_MAX, a_pos);
		b->where_fit = a_pos;
		b = b->next;
	}
}
