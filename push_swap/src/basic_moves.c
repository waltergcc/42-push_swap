/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 21:36:29 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/05/06 23:32:17 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_index(t_stack *st)
{
	int		max_id;
	t_stack	*s;

	max_id = st->id;
	s = st;
	while (s)
	{
		if (s->id > max_id)
			max_id = s->id;
		s = s->nx;
	}
	return (max_id);
}

static void	swap(t_stack *st)
{
	int	t;

	if (!st || !st->nx)
		return ;
	t = st->nb;
	st->nb = st->nx->nb;
	st->nx->nb = t;
	t = st->id;
	st->id = st->nx->id;
	st->nx->id = t;
}

static void	push(t_stack **src, t_stack **dst)
{
	t_stack	*t;

	if (!src)
		return ;
	t = (*src)->nx;
	(*src)->nx = *dst;
	*dst = *src;
	*src = t;
}

void	swap_2(t_stack **sa, t_stack **sb, char *choice)
{
	if (ft_strcmp(choice, "sa") == 0)
		swap(*sa);
	else if (ft_strcmp(choice, "sb") == 0)
		swap(*sb);
	else if (ft_strcmp(choice, "ss") == 0)
	{
		swap(*sa);
		swap(*sb);
	}
	if (ft_strcmp(choice, "pa") == 0)
		push(sb, sa);
	else if (ft_strcmp(choice, "pb") == 0)
		push(sa, sb);
	ft_putstr(choice);
	ft_putstr("\n");
}

void	swap_3(t_stack **lst)
{
	int	max_id;

	if (is_sorted(*lst))
		return ;
	max_id = get_max_index(*lst);
	if ((*lst)->id == max_id)
		rotate_3(lst, NULL, "ra");
	else if ((*lst)->nx->id == max_id)
		rotate_3(lst, NULL, "rra");
	if ((*lst)->id > (*lst)->nx->id)
		swap_2(lst, NULL, "sa");
}
