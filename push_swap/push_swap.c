/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 22:11:07 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/05/05 14:27:02 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_stack *stack)
{
	t_stack	*curr;

	curr = stack;
	while (curr->next)
	{
		if (curr->content > curr->next->content)
			return (0);
		curr = curr->next;
	}
	return (1);
}

static void	push_swap(t_stack **a, t_stack *b, int size)
{
	if (size = 2 && !check_sort(*a))
		printf("It`s here\n");
}

int	main(void)
{
	char	*av[10] = {"7", "2"};
	// char	*av[10] = {"698", "0", "154", "-2147483648", "-987", "1236589", "10"};
	int		ac = 2;
	int		size;
	t_stack	*a;
	t_stack	*b;
	

	if (!check_input(av))
		program_exit(NULL, NULL);
	a = create_stack(ac, av);
	b = NULL;
	size = get_size(a);
	define_index(a, size);
	printf("Size: %d\n", size);
	printf("Is sorted?: %d\n", check_sort(a));
	while (a)
	{
		printf("%d - ", a->index);
		printf("%d\n", a->content);
		a = a->next;
	}
}
