/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 19:21:47 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/23 21:07:19 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	*ft_routine(void *inp_data)
{
	int		index;
	t_data	*data;

	data = (t_data *)inp_data;
	data->threads_ready++;
	pthread_mutex_lock(&data->mutexes[0]);
	data->counter++;
	index = data->counter;
	pthread_mutex_unlock(&data->mutexes[0]);
	if ((index % 2) == 0)
		usleep(5000);
	if (index != 1)
		usleep(100);
	while (data->max_eat_count < data->phil_num)
	{
		ft_eat(data, index);
		usleep(1000);
		ft_sleepy(data, index);
		usleep(40);
		ft_print_status(data, index, "is thinking");
		usleep(40);
	}
	return (NULL);
}
