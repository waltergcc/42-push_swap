/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 22:10:58 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/05/06 22:29:24 by wcorrea-         ###   ########.fr       */
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

static int	is_repeated(char **arg)
{
	int	i;
	int	j;

	i = 1;
	while (arg[i])
	{
		j = i + 1;
		while (arg[j])
		{
			if (ft_strcmp(arg[i], arg[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	is_valid_number(char *s)
{
	if (*s == '+' || *s == '-')
		s++;
	while (*s >= '0' && *s <= '9')
		s++;
	if (*s && !(*s >= '0' && *s <= '9'))
		return (0);
	if (!*s && (*(s - 1) == '+' || *(s - 1) == '-'))
		return (0);
	return (1);
}

static char	*remove_extra_zeros(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i] == '0')
		i++;
	if (!s[i])
	{
		s[0] = '0';
		s[1] = '\0';
		return (s);
	}
	else
	{
		if (s[0] == '-')
			s[j++] = '-';
		while (s[i])
			s[j++] = s[i++];
		s[j] = '\0';
		return (s);
	}
}

int	is_correct_input(char **arg)
{
	int	i;

	i = 1;
	while (arg[i])
	{
		if (!is_valid_number(arg[i]))
			return (0);
		if (arg[i][0] == '0' || arg[i][1] == '0')
			arg[i] = remove_extra_zeros(arg[i]);
		i++;
	}
	if (is_repeated(arg) || !arg[1][0])
		return (0);
	return (1);
}
