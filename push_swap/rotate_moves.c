/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 22:54:56 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/05/06 09:41:19 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse(t_stack **lst)
{
	t_stack	*curr;
	t_stack	*before_last;
	t_stack	*last;

	last = *lst;
	before_last = *lst;
	curr = *lst;
	while (last->next)
		last = last->next;
	while (before_last->next->next)
		before_last = before_last->next;
	*lst = last;
	(*lst)->next = curr;
	before_last->next = NULL;
}

static void	rotate(t_stack **lst)
{
	t_stack	*curr;
	t_stack	*last;

	curr = *lst;
	*lst = (*lst)->next;
	last = *lst;
	while (last->next)
		last = last->next;
	curr->next = NULL;
	last->next = curr;
}

void	rotate_3(t_stack **a, t_stack **b, char *choice)
{
	if (ft_strcmp(choice, "ra") == 0)
		rotate(a);
	else if (ft_strcmp(choice, "rb") == 0)
		rotate(b);
	else if (ft_strcmp(choice, "rr") == 0)
	{
		rotate(a);
		rotate(b);
	}
	else if (ft_strcmp(choice, "rra") == 0)
		reverse(a);
	else if (ft_strcmp(choice, "rrb") == 0)
		reverse(b);
	else if (ft_strcmp(choice, "rrr") == 0)
	{
		reverse(a);
		reverse(b);
	}
	ft_putstr(choice);
	ft_putstr("\n");
}
