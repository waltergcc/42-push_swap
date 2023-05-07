/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_moves_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 01:08:50 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/05/07 01:09:51 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	define_need_moves(t_stack **sa, t_stack **sb)
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
		b->mb = b->ps;
		if (b->ps > size_b / 2)
			b->mb = (size_b - b->ps) * -1;
		b->ma = b->tg;
		if (b->tg > size_a / 2)
			b->ma = (size_a - b->tg) * -1;
		b = b->nx;
	}
}

int	define_targets(t_stack **sa, int b_id, int target, int position)
{
	t_stack	*a;

	a = *sa;
	while (a)
	{
		if (a->id > b_id && a->id < target)
		{
			target = a->id;
			position = a->ps;
		}
		a = a->nx;
	}
	if (target != INT_MAX)
		return (position);
	a = *sa;
	while (a)
	{
		if (a->id < target)
		{
			target = a->id;
			position = a->ps;
		}
		a = a->nx;
	}
	return (position);
}

void	define_positions(t_stack **st)
{
	t_stack	*s;
	int		i;

	s = *st;
	i = 0;
	while (s)
	{
		s->ps = i;
		s = s->nx;
		i++;
	}
}

void	get_target_position(t_stack **sa, t_stack **sb)
{
	t_stack	*b;
	int		target;

	b = *sb;
	define_positions(sa);
	define_positions(sb);
	target = 0;
	while (b)
	{
		target = define_targets(sa, b->id, INT_MAX, target);
		b->tg = target;
		b = b->nx;
	}
}

int	get_lower_position(t_stack **st)
{
	t_stack	*s;
	int		min_id;
	int		low;

	s = *st;
	min_id = INT_MAX;
	define_positions(st);
	low = s->ps;
	while (s)
	{
		if (s->id < min_id)
		{
			min_id = s->id;
			low = s->ps;
		}
		s = s->nx;
	}
	return (low);
}
