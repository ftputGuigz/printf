/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <gpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 22:36:35 by gpetit            #+#    #+#             */
/*   Updated: 2020/12/28 11:36:33 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_size(long nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		count++;
	if (nb < 0)
	{
		nb = -nb;
		count++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(long nb)
{
	char	*stock;
	int		i;

	i = ft_size(nb);
	stock = malloc(sizeof(char) * (i + 1));
	if (!stock)
		return (NULL);
	stock[i--] = '\0';
	if (nb == 0)
	{
		stock[0] = '0';
		return (stock);
	}
	if (nb < 0)
	{
		nb = -nb;
		stock[0] = '-';
	}
	while (nb > 0)
	{
		stock[i] = ((nb % 10) + 48);
		nb = nb / 10;
		i--;
	}
	return (stock);
}

int	ft_atoi(const char *str)
{
	long	i;
	int		sign;
	long	nb;

	i = 0;
	nb = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (sign * nb);
}
