/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_mgmt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:26:33 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/23 18:49:19 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	ft_intlen(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_error_mgmt(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac == 0 || ac > 6 || ac < 5)
	{
		write(2, "wrong arg count. exiting...\n", 28);
		return (1);
	}
	while (av[i] != NULL)
	{
		if (ft_atoi(av[i]) < 1 || ft_atoi(av[1]) > 200
			|| (ft_atoi(av[i]) < 60 && i > 1 && i != 5)
			|| ft_strlen(av[i]) != ft_intlen(ft_atoi(av[i])))
		{
			write(2, "invalid arg. exiting...\n", 24);
			return (1);
		}
		i++;
	}
	return (0);
}
