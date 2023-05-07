/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 23:37:57 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/05/07 00:09:20 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	define_index(t_stack *sa, int size)
{
	t_stack	*a;
	t_stack	*max_ad;
	int		max_nb;

	while (size--)
	{
		a = sa;
		max_nb = INT_MIN;
		max_ad = NULL;
		while (a)
		{
			if (a->nb == INT_MIN && a->id == 0)
				a->id = 1;
			else if (a->nb > max_nb && a->id == 0)
			{
				max_nb = a->nb;
				max_ad = a;
				a = sa;
			}
			else
				a = a->nx;
		}
		if (max_ad)
			max_ad->id = size + 1;
	}
}

int	get_stack_size(t_stack *st)
{
	int		size;
	t_stack	*s;

	size = 0;
	s = st;
	while (s)
	{
		size++;
		s = s->nx;
	}
	return (size);
}

static t_stack	*new_node(int n)
{
	t_stack	*s;

	s = (t_stack *)malloc(sizeof(t_stack));
	if (!s)
		return (NULL);
	s->nb = n;
	s->id = 0;
	s->ps = -1;
	s->tg = -1;
	s->ma = -1;
	s->mb = -1;
	s->nx = NULL;
	return (s);
}

static void	add_at_end(t_stack **st, t_stack *new)
{
	t_stack	*s;

	if (!new)
		return ;
	if (!*st)
		*st = new;
	else
	{
		s = *st;
		while (s->nx)
			s = s->nx;
		s->nx = new;
	}
}

t_stack	*create_stack(int ac, char **av)
{
	t_stack		*sa;
	long int	n;
	int			i;

	sa = NULL;
	n = 0;
	i = 1;
	while (i < ac)
	{
		n = ft_atoi(av[i]);
		if (n < INT_MIN || n > INT_MAX)
			print_error_and_exit(&sa, NULL);
		if (i == 1)
			sa = new_node((int)n);
		else
			add_at_end(&sa, new_node((int)n));
		i++;
	}
	return (sa);
}
