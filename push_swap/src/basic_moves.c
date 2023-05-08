/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 21:36:29 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/05/08 10:46:10 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_index(t_stack *st)
{
	int		max_id;
	t_stack	*s;

	max_id = st->main_index;
	s = st;
	while (s)
	{
		if (s->main_index > max_id)
			max_id = s->main_index;
		s = s->next;
	}
	return (max_id);
}

static void	swap(t_stack *top)
{
	int	tmp;

	if (!top || !top->next)
		return ;
	tmp = top->n;
	top->n = top->next->n;
	top->next->n = tmp;
	tmp = top->main_index;
	top->main_index = top->next->main_index;	
	top->next->main_index = tmp;
}

static void	push(t_stack **top1, t_stack **top2)
{
	t_stack	*tmp;

	if (!top1)
		return ;
	tmp = (*top1)->next;
	(*top1)->next = *top2;
	*top2 = *top1;
	*top1 = tmp;
}

void	swap_move(t_stack **sa, t_stack **sb, char *choice)
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

void	small_sort(t_stack **st)
{
	int	max_id;

	if (is_sorted(*st))
		return ;
	max_id = get_max_index(*st);
	if ((*st)->main_index == max_id)
		rotate_move(st, NULL, "ra");
	else if ((*st)->next->main_index == max_id)
		rotate_move(st, NULL, "rra");
	if ((*st)->main_index > (*st)->next->main_index)
		swap_move(st, NULL, "sa");
}
