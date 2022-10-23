/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread_init.c					:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 19:13:31 by dbekic            #+#    #+#             */
/*   Updated: 2022/08/05 18:19:52 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	ft_thread_init(t_data *data)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(data->print_mutex, NULL) != 0)
		return (ft_free_all(data, 1));
	while (i < data->phil_num)
	{
		if (pthread_mutex_init(&data->mutexes[i], NULL) != 0)
			return (ft_free_all(data, 1));
		i++;
	}
	i = 0;
	while (i < data->phil_num)
	{
		data->eat_mark[i] = data->start;
		if (pthread_create(data->threads + i,
				NULL, ft_routine, (void *) data) != 0)
			return (ft_free_all(data, 1));
		i++;
	}
	return (0);
}
