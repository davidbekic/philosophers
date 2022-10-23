/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hold_up.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 12:42:45 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/23 20:35:39 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	ft_hold_up(t_data *data, int index, int flag)
{
	usleep(1700);
	if (flag == 0)
	{
		while ((data->phil_num == index) && (data->locks[0] == 0
				|| data->locks[index - 1]) == 0)
			usleep(200);
		while ((data->locks[index - 1] == 0 || data->locks[index] == 0)
			&& data->phil_num != index)
			usleep(200);
	}
	if (flag == 1)
	{
		while (data->phil_num == index && data->locks[0] == 0)
			usleep(200);
		while (data->locks[index] == 0 && data->phil_num != index)
			usleep(200);
	}
}
