/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:56:02 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/29 15:57:41 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	ft_print_status(t_data *data, int index, char *str)
{
	if (!data->dead)
		pthread_mutex_lock(data->print_mutex);
	if (!data->dead)
		printf("%lu %d %s\n", ft_get_time() - data->start, index, str);
	usleep(10);
	pthread_mutex_unlock(data->print_mutex);
}
