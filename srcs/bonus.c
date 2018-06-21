/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 11:22:49 by ndelest           #+#    #+#             */
/*   Updated: 2018/04/12 12:07:52 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_parse_bonus(char *str, t_env *env)
{
	int		i;

	i = 0;
	if (str[i] != '-')
		return ;
	i++;
	while (str[i] != 0)
	{
		if (str[i] == 'v')
			env->bonus[0] = 1;
		if (str[i] == 'e')
			env->bonus[1] = 1;
		if (str[i] == 'd')
			env->bonus[2] = 1;
		if (str[i] == 'c')
			env->bonus[3] = 1;
		if (str[i] == 'k')
			env->bonus[4] = 1;
		if (str[i] == 'p')
			env->bonus[5] = 1;
		i++;
	}
}
