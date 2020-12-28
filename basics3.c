/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <gpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 10:40:03 by gpetit            #+#    #+#             */
/*   Updated: 2020/12/28 10:41:34 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*s2;
	unsigned int	i;
	size_t			j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	s2 = malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			s2[j] = s[i];
			j++;
		}
		i++;
	}
	s2[j] = '\0';
	return (s2);
}

static void	ft_fill(char *dst, char *s, int *i)
{
	int	j;

	j = 0;
	while (s[j])
	{
		dst[*i] = s[j];
		j++;
		(*i)++;
	}
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dst;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	dst = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dst)
		return (NULL);
	i = 0;
	ft_fill(dst, s1, &i);
	ft_fill(dst, s2, &i);
	dst[i] = '\0';
	return (dst);
}
