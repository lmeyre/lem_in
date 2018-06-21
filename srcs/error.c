/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 18:38:06 by ndelest           #+#    #+#             */
/*   Updated: 2018/04/12 12:07:53 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_parse_error2(int error)
{
	if (error == 6)
	{
		ft_printf(": There is no room linked");
		ft_printf("	to the end room in the input.\n");
	}
	else if (error == 7)
		ft_printf(": There are two rooms with the same coordinates.\n");
	else if (error == 8)
		ft_printf(": There is no path linking start & end.\n");
	else
		ft_printf("\n");
	return (0);
}

int			ft_parse_error(int error, t_env *env)
{
	ft_printf("ERROR");
	env->step = 1;
	if (env->bonus[1] == 0)
		error = -1;
	if (error == 1)
		ft_printf(": Invalid ants number.\n");
	else if (error == 2)
		ft_printf(": There is no room in the input.\n");
	else if (error == 3)
		ft_printf(": There is no start room in the input.\n");
	else if (error == 4)
		ft_printf(": There is no end room in the input.\n");
	else if (error == 5)
	{
		ft_printf(": There is no room linked to the");
		ft_printf(" start room in the input.\n");
	}
	else
		ft_parse_error2(error);
	exit(EXIT_SUCCESS);
	return (0);
}
