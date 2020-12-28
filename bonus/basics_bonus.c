/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics_bonus.c                                  	:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <gpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 15:30:50 by gpetit            #+#    #+#             */
/*   Updated: 2020/12/10 12:04:57 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

unsigned long	ft_strlen(char *s)
{
	unsigned long	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	int		len;
	int		i;
	char	*s2;

	i = 0;
	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	s2 = malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (NULL);
	while (i < len)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

int	ft_strchrmodif(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	while (*ptr != c)
	{
		if (*ptr == '\0')
			return (0);
		ptr++;
	}
	return (1);
}
