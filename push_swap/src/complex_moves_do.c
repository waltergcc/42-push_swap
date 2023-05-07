/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_complex_moves.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 01:12:37 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/05/07 01:12:56 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_both(t_stack **sa, t_stack **sb, int *ma, int *mb)
{
	while (*ma < 0 && *ma < 0)
	{
		(*ma)++;
		(*mb)++;
		rotate_3(sa, sb, "rrr");
	}
}

static void	rotate_both(t_stack **sa, t_stack **sb, int *ma, int *mb)
{
	while (*ma > 0 && *mb > 0)
	{
		(*ma)--;
		(*mb)--;
		rotate_3(sa, sb, "rr");
	}
}

static void	rotate_a(t_stack **sa, int *ma)
{
	while (*ma)
	{
		if (*ma > 0)
		{
			rotate_3(sa, NULL, "ra");
			(*ma)--;
		}
		else if (*ma < 0)
		{
			rotate_3(sa, NULL, "rra");
			(*ma)++;
		}
	}
}

static void	rotate_b(t_stack **sb, int *mb)
{
	while (*mb)
	{
		if (*mb > 0)
		{
			rotate_3(NULL, sb, "rb");
			(*mb)--;
		}
		else if (*mb < 0)
		{
			rotate_3(NULL, sb, "rrb");
			(*mb)++;
		}
	}
}

void	sort_with_less_moves(t_stack **sa, t_stack **sb)
{
	t_stack	*b;
	int		less_moves;
	int		ma;
	int		mb;

	b = *sb;
	less_moves = INT_MAX;
	while (b)
	{
		if (absolute(b->ma) + absolute(b->mb) < absolute(less_moves))
		{
			less_moves = absolute(b->ma) + absolute(b->mb);
			ma = b->ma;
			mb = b->mb;
		}
		b = b->nx;
	}
	if (ma < 0 && mb < 0)
		reverse_both(sa, sb, &ma, &mb);
	else if (ma > 0 && mb > 0)
		rotate_both(sa, sb, &ma, &mb);
	rotate_a(sa, &ma);
	rotate_b(sb, &mb);
	swap_2(sa, sb, "pa");
}
