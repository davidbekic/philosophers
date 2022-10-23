/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:18:24 by dbekic            #+#    #+#             */
/*   Updated: 2022/07/23 19:08:53 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void	*ft_calloc(size_t count, size_t size)
{
	void		*carr;
	char		*ncarr;
	size_t		i;

	i = 0;
	carr = malloc(count * size);
	if (carr == NULL)
		return (NULL);
	ncarr = (char *) carr;
	while (i < (count * size))
	{
		ncarr[i] = 0;
		i++;
	}
	carr = (void *) ncarr;
	return (ncarr);
}
