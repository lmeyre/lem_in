/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkint_positive.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 11:20:33 by ndelest           #+#    #+#             */
/*   Updated: 2018/04/05 12:00:23 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_checkint_positive(char *str, int *k, int i)
{
	long long int	l;
	char			*nb;

	l = 0;
	if (i > 10)
		return (0);
	if (i > 9)
	{
		nb = &str[i - 1];
		*k = ft_atoi(nb);
		nb = str;
		nb[i - 1] = 0;
		l = ft_atoi(nb);
	}
	else
		*k = ft_atoi(str);
	l = (l * 10) + *k;
	if (l > INT_MAX)
		return (0);
	else
		*k = l;
	return (1);
}
