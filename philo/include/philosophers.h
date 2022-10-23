/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:46:54 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/23 21:23:10 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# define USLEEP 200
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_data
{
	int				counter;
	int				tte;
	int				tts;
	int				ttd;
	int				eat_ceiling;
	int				*num_of_eats;
	int				total_num_of_eats;
	int				phil_num;
	int				*locks;
	int				*death_lock;
	int				max_eat_count;
	int				error;
	int				dead;
	int				threads_ready;
	int				total_eat_level;
	long			start;
	long			*eat_mark;
	long			*sleep_mark;
	pthread_t		*threads;
	pthread_mutex_t	*mutexes;
	pthread_mutex_t	*print_mutex;
	pthread_mutex_t	*left_right_fork;
}		t_data;

int			ft_memory_init(t_data *data);
int			ft_atoi(const char *str);
int			ft_strncmp(char *s1, char *s2, unsigned int n);
int			ft_thread_init(t_data *data);
int			ft_thread_join(t_data *data);
int			ft_free_all(t_data *data, unsigned char flag);
int			ft_error_mgmt(int ac, char **av);
int			ft_thread_join(t_data *data);
int			ft_sleepy(t_data *data, int index);
long		ft_get_time(void);
void		*ft_routine(void *inp_data);
void		*ft_calloc(size_t count, size_t size);
void		ft_eat(t_data *data, int index);
void		ft_hold_up(t_data *data, int index, int flag);
void		ft_print_status(t_data *data, int index, char *str);

#endif
