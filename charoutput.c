/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charoutput.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <gpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 15:43:48 by gpetit            #+#    #+#             */
/*   Updated: 2020/12/28 10:53:27 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_percentoutput2(char c, t_flags *flags, char *output)
{
	int	i;

	i = 0;
	while (++i <= flags->taillemin - 2)
	{
		if (flags->zero == 1 && flags->tabulator == 0)
			output[i] = '0';
		else
			output[i] = ' ';
	}
	if (flags->tabulator)
	{
		output[0] = c;
		output[flags->taillemin - 1] = ' ';
	}
	else
	{
		if (flags->zero == 1)
			output[0] = '0';
		else
			output[0] = ' ';
		output[flags->taillemin - 1] = c;
	}
	output[flags->taillemin] = '\0';
}

int	ft_percentoutput(char c, t_flags *flags)
{
	int				count;
	char			*output;
	int				i;

	count = 1;
	if (flags->taillemin > 1)
	{
		output = malloc(sizeof(char) * ((flags->taillemin) + 1));
		if (!output)
			return (-1);
		ft_percentoutput2(c, flags, output);
		i = 0;
		while (i < flags->taillemin)
			ft_putchar(output[i++]);
		free(output);
		count = flags->taillemin;
	}
	else
		ft_putchar(c);
	return (count);
}

void	ft_charoutput2(char c, t_flags *flags, char *output)
{
	int	i;

	i = 0;
	while (++i <= flags->taillemin - 2)
		output[i] = ' ';
	if (flags->tabulator)
	{
		output[0] = c;
		output[flags->taillemin - 1] = ' ';
	}
	else
	{
		output[0] = ' ';
		output[flags->taillemin - 1] = c;
	}
	output[flags->taillemin] = '\0';
}

int	ft_charoutput(char c, t_flags *flags)
{
	int				count;
	char			*output;
	int				i;

	count = 1;
	if (flags->zero != 0 || flags->taillemax != -1)
		return (-1);
	if (flags->taillemin > 1)
	{
		output = malloc(sizeof(char) * ((flags->taillemin) + 1));
		if (!output)
			return (-1);
		ft_charoutput2(c, flags, output);
		i = 0;
		while (i < flags->taillemin)
			ft_putchar(output[i++]);
		free(output);
		count = flags->taillemin;
	}
	else
		ft_putchar(c);
	return (count);
}
