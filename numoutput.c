/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numoutput.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <gpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 09:42:49 by gpetit            #+#    #+#             */
/*   Updated: 2020/12/28 11:15:43 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char	*ft_precision2(int len, char *tmp)
{
	char	*stock;
	char	*output;
	int		i;

	i = 0;
	stock = malloc(sizeof(char) * (len + 1));
	if (!stock)
		return (NULL);
	while (i < len)
		stock[i++] = '0';
	stock[i] = '\0';
	output = ft_strjoin(stock, tmp);
	free(stock);
	return (output);
}

char	*ft_precision(long nb, int precision, char *tmp, int neg)
{
	char	*stock;
	char	*output;
	int		len;

	len = precision - (int)ft_strlen(tmp);
	if (precision == 0 && nb == 0)
		output = ft_strdup("");
	else if (len <= 0)
		output = ft_strdup(tmp);
	else
		output = ft_precision2(len, tmp);
	if (neg)
	{
		stock = output;
		output = ft_strjoin("-", stock);
		free(stock);
	}
	free(tmp);
	return (output);
}

char	*ft_width2(int len, t_flags *flags, int neg, char *tmp)
{
	char	*stock;
	int		i;

	i = 0;
	stock = malloc(sizeof(char) * (len + 1));
	if (!stock)
		return (NULL);
	while (i < len)
	{
		if (flags->zero)
		{
			stock[i++] = '0';
			if (neg)
			{
				stock[0] = '-';
				tmp[0] = '0';
			}
		}
		else
			stock[i++] = ' ';
	}
	stock[i] = '\0';
	return (stock);
}

char	*ft_width(int len, char *tmp, t_flags *flags, int neg)
{
	char	*stock;
	char	*output;

	if (len <= 0)
		output = ft_strdup(tmp);
	else
	{
		stock = ft_width2(len, flags, neg, tmp);
		if (flags->tabulator)
			output = ft_strjoin(tmp, stock);
		else
			output = ft_strjoin(stock, tmp);
		free(stock);
	}
	free(tmp);
	return (output);
}

int	ft_numoutput(long nb, t_flags *flags)
{
	int		nbrlen;
	char	*tmp;
	char	*output;
	int		negative;

	negative = 0;
	if (nb < 0)
	{
		nb = -nb;
		negative = 1;
	}
	if (flags->operator == 'x' || flags->operator == 'X')
		tmp = ft_print_hexa(nb, flags->operator);
	else
		tmp = ft_itoa(nb);
	if (flags->taillemax != -1)
		flags->zero = 0;
	output = ft_precision(nb, flags->taillemax, tmp, negative);
	nbrlen = (int)ft_strlen(output);
	tmp = ft_width(flags->taillemin - nbrlen, output, flags, negative);
	nbrlen = ft_putstr(tmp);
	free(tmp);
	return (nbrlen);
}
