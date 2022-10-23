/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 21:58:40 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/23 21:40:16 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static int	ft_eat_sleep(t_data *data, int index)
{
	ft_print_status(data, index, "has taken a fork");
	data->eat_mark[index - 1] = ft_get_time();
	data->total_num_of_eats++;
	data->num_of_eats[index - 1] += 1;
	if (data->num_of_eats[index - 1] == data->eat_ceiling)
	{
		pthread_mutex_lock(data->print_mutex);
		data->total_eat_level++;
	}
	if (data->total_eat_level != data->phil_num)
		pthread_mutex_unlock(data->print_mutex);
	else
		printf("%lu %d is eating\n", ft_get_time() - data->start, index);
	if (data->total_num_of_eats != data->eat_ceiling * data->phil_num)
		ft_print_status(data, index, "is eating");
	while ((ft_get_time() - data->eat_mark[index - 1]) < data->tte)
		usleep(USLEEP);
	return (1);
}

static pthread_mutex_t	*ft_decide_left_fork(t_data *data, int index)
{
	if (index == 1)
		return (&data->mutexes[data->phil_num - 1]);
	else
		return (&data->mutexes[index - 2]);
}

static pthread_mutex_t	*ft_decide_right_fork(t_data *data, int index)
{
	if (data->phil_num == 1)
		return (&data->mutexes[0]);
	else if (index == 1)
		return (&data->mutexes[0]);
	else
		return (&data->mutexes[index - 1]);
}

static void	ft_data_locks(t_data *data,
			int index, int flag, pthread_mutex_t *fork)
{
	if (flag == 1)
	{
		if (index != data->phil_num)
			data->locks[index] = pthread_mutex_lock(fork);
		else
			data->locks[0] = pthread_mutex_lock(fork);
	}
	else
	{
		if (index != data->phil_num)
			data->locks[index] = 1;
		else
			data->locks[0] = 1;
	}
}

void	ft_eat(t_data *data, int index)
{
	unsigned char	eaten;
	pthread_mutex_t	*forks[2];

	eaten = 0;
	forks[0] = ft_decide_left_fork(data, index);
	forks[1] = ft_decide_right_fork(data, index);
	while ((!eaten))
	{
		ft_hold_up(data, index, 0);
		if (data->dead)
			break ;
		data->locks[index - 1] = pthread_mutex_lock(forks[0]);
		ft_print_status(data, index, "has taken a fork");
		ft_hold_up(data, index, 1);
		ft_data_locks(data, index, 1, forks[1]);
		eaten = ft_eat_sleep(data, index);
		pthread_mutex_unlock(forks[0]);
		data->locks[index - 1] = 1;
		pthread_mutex_unlock(forks[1]);
		ft_data_locks(data, index, 0, forks[1]);
	}
}
