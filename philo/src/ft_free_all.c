/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 20:34:28 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/29 16:12:16 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	ft_free_all(t_data *data, unsigned char flag)
{
	data->dead = 1;
	usleep(500);
	ft_thread_join(data);
	if (data->threads)
		free(data->threads);
	if (data->mutexes)
		free(data->mutexes);
	if (data->eat_mark)
		free(data->eat_mark);
	if (data->sleep_mark)
		free(data->sleep_mark);
	if (data->num_of_eats)
		free(data->num_of_eats);
	if (data->locks)
		free(data->locks);
	if (data->death_lock)
		free(data->death_lock);
	if (data->print_mutex)
		free(data->print_mutex);
	if (data)
		free(data);
	if (flag == 1)
		return (1);
	else
		return (0);
}
