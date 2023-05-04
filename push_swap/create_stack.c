/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 23:37:57 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/05/05 00:11:41 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*new_node(int n)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = n;
	node->next = NULL;
	return (node);
}

static void	add_at_end(t_stack **stack, t_stack *new)
{
	t_stack	*curr;

	if (!new)
		return ;
	if (!*stack)
		*stack = new;
	else
	{
		curr = *stack;
		while (curr->next)
			curr = curr->next;
		curr->next = new;
	}
}

t_stack	*create_stack(int ac, char **av)
{
	t_stack	*a;
	long	n;
	int		i;

	a = NULL;
	n = 0;
	i = 0;
	while (i < ac)
	{
		n = ft_atoi(av[i]);
		if (n < INT_MIN || n > INT_MAX)
			program_exit(&a, NULL);
		if (i == 0)
			a = new_node(n);
		else
			add_at_end(&a, new_node(n));
		i++;
	}
	return (a);
}
