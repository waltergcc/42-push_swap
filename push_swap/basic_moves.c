/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 21:36:29 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/05/06 09:38:58 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_index(t_stack *lst)
{
	int		index;
	t_stack	*curr;

	index = lst->index;
	curr = lst;
	while (curr)
	{
		if (curr->index > index)
			index = curr->index;
		curr = curr->next;
	}
	return (index);
}

static void	swap(t_stack *lst)
{
	int	temp;

	if (!lst || !lst->next)
		return ;
	temp = lst->content;
	lst->content = lst->next->content;
	lst->next->content = temp;
	temp = lst->index;
	lst->index = lst->next->index;
	lst->next->index = temp;
}

static void	push(t_stack **from, t_stack **to)
{
	t_stack	*curr;

	if (!from)
		return ;
	curr = (*from)->next;
	(*from)->next = *to;
	*to = *from;
	*from = curr;
}

void	swap_2(t_stack **a, t_stack **b, char *choice)
{
	if (ft_strcmp(choice, "sa") == 0)
		swap(*a);
	else if (ft_strcmp(choice, "sb") == 0)
		swap(*b);
	else if (ft_strcmp(choice, "ss") == 0)
	{
		swap(*a);
		swap(*b);
	}
	if (ft_strcmp(choice, "pa") == 0)
		push(b, a);
	else if (ft_strcmp(choice, "pb") == 0)
		push(a, b);
	ft_putstr(choice);
	ft_putstr("\n");
}

void	swap_3(t_stack **lst)
{
	int	max;

	if (check_sort(*lst))
		return ;
	max = get_max_index(*lst);
	if ((*lst)->index == max)
		rotate_3(lst, NULL, "ra");
	else if ((*lst)->next->index == max)
		rotate_3(lst, NULL, "rra");
	if ((*lst)->index > (*lst)->next->index)
		swap_2(lst, NULL, "sa");
}
