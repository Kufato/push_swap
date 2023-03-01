/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 10:48:30 by axcallet          #+#    #+#             */
/*   Updated: 2023/01/26 14:19:31 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*final_str;

	i = 0;
	j = 0;
	final_str = ft_calloc(sizeof(char), (ft_strlen(s1) + ft_strlen(s2) + 3));
	if (!final_str)
		return (NULL);
	ft_memcpy(final_str, s1, ft_strlen(s1));
	i = 0;
	j = ft_strlen(final_str);
	while (s2[i] != '\0')
	{
		final_str[j] = s2[i];
		i++;
		j++;
	}
	final_str[j] = ' ';
	final_str[j + 1] = '\0';
	free(s1);
	return (final_str);
}
