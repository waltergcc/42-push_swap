/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 22:11:07 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/05/07 00:09:20 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *st)
{
	t_stack	*s;

	s = st;
	while (s->nx)
	{
		if (s->nb > s->nx->nb)
			return (0);
		s = s->nx;
	}
	return (1);
}

static void	push_swap(t_stack **sa, t_stack **sb, int size)
{
	if (size == 2 && !is_sorted(*sa))
		swap_2(sa, NULL, "sa");
	else if (size == 3)
		swap_3(sa);
	else if (size > 3 && !is_sorted(*sa))
		above_3(sa, sb);
}

int	main(int ac, char **av)
{
	int		size;
	t_stack	*sa;
	t_stack	*sb;

	if (ac < 2)
		return (0);
	if (!is_correct_input(av))
		print_error_and_exit(NULL, NULL);
	sa = create_stack(ac, av);
	sb = NULL;
	size = get_stack_size(sa);
	define_index(sa, size);
	push_swap(&sa, &sb, size);
	free_stack(&sa);
	free_stack(&sb);
}
