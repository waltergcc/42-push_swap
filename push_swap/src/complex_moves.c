/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 10:53:55 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/05/07 01:20:40 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	split_stack(t_stack **sa, t_stack **sb)
{
	int		size;
	int		pushed;
	int		i;

	size = get_stack_size(*sa);
	pushed = 0;
	i = 0;
	while (size > 6 && i < size && pushed < size / 2)
	{
		if ((*sa)->id <= size / 2)
		{
			swap_2(sa, sb, "pb");
			pushed++;
		}
		else
			rotate_3(sa, NULL, "ra");
		i++;
	}
	while (size - pushed > 3)
	{
		swap_2(sa, sb, "pb");
		pushed++;
	}
	swap_3(sa);
}

static void	shift_stack(t_stack **sa)
{
	int	size;
	int	low;

	size = get_stack_size(*sa);
	low = get_lower_position(sa);
	if (low > size / 2)
	{
		while (low++ < size)
			rotate_3(sa, NULL, "rra");
	}
	else
	{
		while (low--)
			rotate_3(sa, NULL, "ra");
	}
}

void	above_3(t_stack **sa, t_stack **sb)
{
	split_stack(sa, sb);
	while (*sb)
	{
		get_target_position(sa, sb);
		define_need_moves(sa, sb);
		sort_with_less_moves(sa, sb);
	}
	if (!is_sorted(*sa))
		shift_stack(sa);
}
