/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexaconvertor_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <gpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 10:47:50 by gpetit            #+#    #+#             */
/*   Updated: 2020/12/28 11:05:19 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_hexaconvertor(char *stock, unsigned long nb, unsigned long i)
{
	static char	rosetta[] = "0123456789abcdef";

	if (nb > 0)
		ft_hexaconvertor(stock, nb / 16, i - 1);
	if (i <= ft_strlen(stock))
		stock[i] = rosetta[nb % 16];
}

void	ft_hexamajconvertor(char *stock, unsigned long nb, unsigned long i)
{
	static char	rosetta[] = "0123456789ABCDEF";

	if (nb > 0)
		ft_hexamajconvertor(stock, nb / 16, i - 1);
	if (i <= ft_strlen(stock))
		stock[i] = rosetta[nb % 16];
}

char	*ft_print_memory(void *ptr)
{
	unsigned long	n;
	char			*stock;
	unsigned long	x;
	unsigned long	count;

	n = (unsigned long)ptr;
	x = n;
	count = 0;
	if (x == 0)
		count = 1;
	while (x > 0)
	{
		x = x / 16;
		count++;
	}
	stock = malloc(sizeof(char) * (count + 1));
	if (!stock)
		return (NULL);
	stock[count] = '\0';
	ft_hexaconvertor(stock, n, count - 1);
	return (stock);
}

char	*ft_print_hexa(unsigned long nb, char c)
{
	char			*stock;
	unsigned long	x;
	unsigned long	count;

	x = nb;
	count = 0;
	if (x == 0)
		count = 1;
	while (x > 0)
	{
		x = x / 16;
		count++;
	}
	stock = malloc(sizeof(char) * (count + 1));
	if (!stock)
		return (NULL);
	stock[count] = '\0';
	if (c == 'x')
		ft_hexaconvertor(stock, nb, count - 1);
	if (c == 'X')
		ft_hexamajconvertor(stock, nb, count - 1);
	return (stock);
}
