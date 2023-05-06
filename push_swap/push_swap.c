/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 22:11:07 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/05/06 09:32:40 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_stack *lst)
{
	t_stack	*curr;

	curr = lst;
	while (curr)
	{
		printf("%d - ", curr->index);
		printf("%d\n", curr->content);
		curr = curr->next;
	}
}

int	check_sort(t_stack *lst)
{
	t_stack	*curr;

	curr = lst;
	while (curr->next)
	{
		if (curr->content > curr->next->content)
			return (0);
		curr = curr->next;
	}
	return (1);
}

static void	push_swap(t_stack **a, t_stack **b, int size)
{
	(void) b;
	if (size == 2 && !check_sort(*a))
		swap_2(a, NULL, "sa");
	else if (size == 3)
		swap_3(a);
	else if (size > 3 && !check_sort(*a))
		return;
}

int	main(void)
{
	char	*av[10] = {"18", "19", "17"};
	// char	*av[10] = {"698", "0", "154", "-2147483648", "-987", "1236589", "10"};
	int		ac = 3;
	int		size;
	t_stack	*a;
	t_stack	*b;
	

	if (!check_input(av))
		program_exit(NULL, NULL);
	a = create_stack(ac, av);
	b = NULL;
	size = get_size(a);
	define_index(a, size);
	print_list(a);
	push_swap(&a, &b, size);
	print_list(a);

}
