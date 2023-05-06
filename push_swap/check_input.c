/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 22:10:58 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/05/05 23:37:32 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	if (*s1 == '+')
	{
		if (*s2 != '+')
			s1++;
	}
	else
	{
		if (*s2 == '+')
			s2++;
	}
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

static int	check_repeat(char **arg)
{
	int	i;
	int	j;

	i = 0;
	while (arg[i])
	{
		j = i + 1;
		while (arg[j])
		{
			if (!ft_strcmp(arg[i], arg[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_digits(char *s)
{
	if (*s == '+' || *s == '-')
		s++;
	while (*s >= '0' && *s <= '9')
		s++;
	if (*s && !(*s >= '0' && *s <= '9'))
		return (0);
	return (1);
}

static int	check_zero(char *s)
{
	if (*s == '+' || *s == '-')
		s++;
	while (*s == '0')
		s++;
	if (*s)
		return (0);
	return (1);
}

int	check_input(char **arg)
{
	int	i;
	int	zero;

	i = 0;
	zero = 0;
	while (arg[i])
	{
		if (!check_digits(arg[i]))
			return (0);
		zero += check_zero(arg[i]);
		i++;
	}
	if (zero > 1 || !check_repeat(arg))
		return (0);
	return (1);
}
