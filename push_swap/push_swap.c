/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 22:11:07 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/05/05 00:13:49 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	char	*av[10] = {"+2", "0", "1", "8", "7", "9", "10"};
	int		ac = 7;
	t_stack	*a;

	if (!check_input(av))
		program_exit(NULL, NULL);
	a = create_stack(ac, av);
	while (a)
	{
		printf("%d\n", a->value);
		a = a->next;
	}
}
