/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleepy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 22:25:50 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/23 17:56:17 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	ft_sleepy(t_data *data, int index)
{
	if ((data->num_of_eats[index - 1] > 0) && (*data->death_lock == 0)
		&& (data->phil_num > 1)
		&& (data->max_eat_count < data->phil_num) && data->dead != 1)
		ft_print_status(data, index, "is sleeping");
	data->sleep_mark[index - 1] = ft_get_time();
	if (data->dead)
		return (1);
	while ((((ft_get_time() - data->sleep_mark[index - 1]) < data->tts)
			&& data->phil_num > 1)
		&& data->max_eat_count < data->phil_num && data->dead != 1)
	{
		if (data->dead)
			break ;
		usleep(USLEEP);
	}
	return (0);
}
