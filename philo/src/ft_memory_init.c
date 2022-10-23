/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:58:08 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/23 21:37:33 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static int	ft_init_first_group(t_data *data, int size)
{
	data->mutexes = (pthread_mutex_t *) ft_calloc(size, 64);
	if (!data->mutexes)
		return (ft_free_all(data, 1));
	data->print_mutex = (pthread_mutex_t *) ft_calloc(1, 64);
	if (!data->print_mutex)
		return (ft_free_all(data, 1));
	data->eat_mark = (long *) ft_calloc(size, sizeof(long));
	if (!data->eat_mark)
		return (ft_free_all(data, 1));
	data->sleep_mark = (long *) ft_calloc(size, sizeof(long));
	if (!data->sleep_mark)
		return (ft_free_all(data, 1));
	return (0);
}

static int	ft_init_second_group(t_data *data, int size)
{
	data->threads = (pthread_t *) ft_calloc(size, sizeof(pthread_t));
	if (!data->threads)
		return (ft_free_all(data, 1));
	data->num_of_eats = (int *) ft_calloc(size, sizeof(int));
	if (!data->num_of_eats)
		return (ft_free_all(data, 1));
	data->locks = (int *) ft_calloc(size, sizeof(int));
	if (!data->locks)
		return (ft_free_all(data, 1));
	data->death_lock = (int *) ft_calloc(1, sizeof(int));
	if (!data->death_lock)
		return (ft_free_all(data, 1));
	return (0);
}

int	ft_memory_init(t_data *data)
{
	int	i;

	i = 0;
	data->counter = i;
	if (ft_init_first_group(data, data->phil_num) == 1)
		return (1);
	if (ft_init_second_group(data, data->phil_num) == 1)
		return (1);
	while (i < data->phil_num)
	{
		data->locks[i] = 1;
		i++;
	}
	return (0);
}
