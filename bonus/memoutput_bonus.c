/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memoutput_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <gpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 17:47:26 by gpetit            #+#    #+#             */
/*   Updated: 2020/12/28 11:14:21 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*ft_spaces(char *tmp, t_flags *flags)
{
	int		i;
	int		max;
	char	*spaces;
	char	*output;

	i = 0;
	max = flags->taillemin - (int)ft_strlen(tmp);
	spaces = malloc(sizeof(char) * (max + 1));
	if (!spaces)
		return (NULL);
	spaces[max] = '\0';
	while (i < max)
		spaces[i++] = ' ';
	if (flags->tabulator)
		output = ft_strjoin(tmp, spaces);
	else
		output = ft_strjoin(spaces, tmp);
	free(spaces);
	return (output);
}

int	ft_memoutput(void *ptr, t_flags *flags)
{
	char	*tmp;
	char	*spaces;
	char	*output;
	int		count;
	int		i;

	i = 0;
	spaces = NULL;
	if (flags->taillemax == 0)
		tmp = ft_strdup("0x");
	else
		tmp = ft_strjoin("0x", (char*)ft_print_memory(ptr));
	free((char*)ft_print_memory(ptr));
	if (flags->taillemin > (int)ft_strlen(tmp))
		output = ft_spaces(tmp, flags);
	else
		output = ft_strdup(tmp);
	count = ft_putstr(output);
	free(tmp);
	free(output);
	return (count);
}
