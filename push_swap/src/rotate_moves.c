/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 22:54:56 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/05/06 23:34:09 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse(t_stack **st)
{
	t_stack	*s;
	t_stack	*before;
	t_stack	*last;

	last = *st;
	before = *st;
	s = *st;
	while (last->nx)
		last = last->nx;
	while (before->nx->nx)
		before = before->nx;
	*st = last;
	(*st)->nx = s;
	before->nx = NULL;
}

static void	rotate(t_stack **st)
{
	t_stack	*s;
	t_stack	*last;

	s = *st;
	*st = (*st)->nx;
	last = *st;
	while (last->nx)
		last = last->nx;
	s->nx = NULL;
	last->nx = s;
}

void	rotate_3(t_stack **sa, t_stack **sb, char *choice)
{
	if (ft_strcmp(choice, "ra") == 0)
		rotate(sa);
	else if (ft_strcmp(choice, "rb") == 0)
		rotate(sb);
	else if (ft_strcmp(choice, "rr") == 0)
	{
		rotate(sa);
		rotate(sb);
	}
	else if (ft_strcmp(choice, "rra") == 0)
		reverse(sa);
	else if (ft_strcmp(choice, "rrb") == 0)
		reverse(sb);
	else if (ft_strcmp(choice, "rrr") == 0)
	{
		reverse(sa);
		reverse(sb);
	}
	ft_putstr(choice);
	ft_putstr("\n");
}
