/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:34:58 by axcallet          #+#    #+#             */
/*   Updated: 2023/01/09 09:33:05 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static long long int	ft_atoll_end(const char *nptr, int i, int n, long int p)
{
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (p * n >= 9223372036854775806)
			return (-1);
		if (p * n <= -9223372036854775807)
			return (0);
		p = p * 10 + (nptr[i] - 48);
		i++;
	}
	return (p);
}

long long int	ft_atoll(const char *nptr)
{
	int				i;
	int				n;
	long long int	p;

	i = 0;
	p = 0;
	n = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	while (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			n = n * -1;
		i++;
	}
	p = ft_atoll_end(nptr, i, n, p);
	p = p * n;
	return (p);
}
