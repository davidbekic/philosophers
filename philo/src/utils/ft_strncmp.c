/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 07:17:18 by dbekic            #+#    #+#             */
/*   Updated: 2022/07/23 19:08:04 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	unsigned char	*ns1;
	unsigned char	*ns2;

	ns1 = (unsigned char *) s1;
	ns2 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	i = 0;
	while (ns1[i] == ns2[i] && ns1[i] && ns2[i] && i < n)
		i++;
	if (i == n)
		i--;
	return (ns1[i] - ns2[i]);
}
