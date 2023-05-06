/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 23:37:57 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/05/06 00:37:34 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	define_index(t_stack *a, int size)
{
	t_stack	*curr;
	t_stack	*max_stack;
	int		max_content;

	while (size--)
	{
		curr = a;
		max_content = INT_MIN;
		max_stack = NULL;
		while (curr)
		{
			if (curr->content == INT_MIN && curr->index == 0)
				curr->index = 1;
			else if (curr->content > max_content && curr->index == 0)
			{
				max_content = curr->content;
				max_stack = curr;
				curr = a;
			}
			else
				curr = curr->next;
		}
		if (max_stack)
			max_stack->index = size + 1;
	}
}

int	get_size(t_stack *lst)
{
	int		count;
	t_stack	*curr;

	count = 0;
	curr = lst;
	while (curr)
	{
		count++;
		curr = curr->next;
	}
	return (count);
}

static t_stack	*new_node(int n)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->content = n;
	node->index = 0;
	node->next = NULL;
	return (node);
}

static void	add_at_end(t_stack **lst, t_stack *new)
{
	t_stack	*curr;

	if (!new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		curr = *lst;
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
