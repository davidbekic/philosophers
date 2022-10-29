/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread_join.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 21:55:48 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/29 16:04:14 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	ft_thread_join(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(data->print_mutex);
	while (i < data->phil_num)
	{
		if (pthread_detach(data->threads[i]))
			printf("not detached\n");
		i++;
	}
	i = 0;
	while (i < data->phil_num)
	{
		pthread_mutex_destroy(&data->mutexes[i]);
		i++;
	}
	return (0);
}
