/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:46:54 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/29 16:14:06 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static int	save_lines(t_data *data, int i)
{
	pthread_mutex_lock(data->print_mutex);
	*data->death_lock = 1;
	printf("%lu %d died\n", ft_get_time() - data->start, i + 1);
	return (ft_free_all(data, 1));
}

static int	continue_simulation_sec(t_data *data, int *max_eat_flag, int i)
{
	while (1)
	{
		if ((ft_get_time() - data->eat_mark[i]) > data->ttd)
		{
			free(max_eat_flag);
			return (save_lines(data, i));
		}
		if (data->num_of_eats[i] == data->eat_ceiling && !max_eat_flag[i])
		{
			data->max_eat_count += 1;
			max_eat_flag[i]++;
		}
		if (data->total_eat_level == data->phil_num)
		{
			data->dead = 1;
			free(max_eat_flag);
			return (ft_free_all(data, 0));
		}
		if (++i == data->phil_num)
			i = 0;
	}
	free(max_eat_flag);
	return (1);
}

static int	continue_simulation(t_data *data)
{
	int	*max_eat_flag;
	int	i;

	i = 0;
	max_eat_flag = (int *) ft_calloc(data->phil_num, sizeof(int));
	if (!max_eat_flag)
		return (ft_free_all(data, 1));
	return (continue_simulation_sec(data, max_eat_flag, i));
}

static int	ft_init_vars(t_data **data, char **av)
{
	(*data)->threads_ready = 0;
	(*data)->dead = 0;
	(*data)->phil_num = ft_atoi(av[1]);
	(*data)->start = ft_get_time();
	if (ft_memory_init((*data)) == 1)
		return (1);
	(*data)->start = ft_get_time();
	(*data)->ttd = ft_atoi(av[2]);
	(*data)->tte = ft_atoi(av[3]);
	(*data)->tts = ft_atoi(av[4]);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ft_error_mgmt(ac, av))
		return (1);
	data = (t_data *) ft_calloc(1, sizeof(t_data));
	if (!data || ft_init_vars(&data, av))
		return (1);
	if (av[5] != NULL)
		data->eat_ceiling = ft_atoi(av[5]);
	else
		data->eat_ceiling = INT_MAX;
	data->total_num_of_eats = 0;
	data->total_eat_level = 0;
	if (ft_thread_init(data) == 1)
		return (1);
	return (continue_simulation(data));
}
