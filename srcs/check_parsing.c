/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:05:01 by ndelest           #+#    #+#             */
/*   Updated: 2018/04/12 16:29:11 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_check_coordinates(t_env *env)
{
	int		i;
	int		j;

	i = 0;
	while (i < env->size)
	{
		j = i + 1;
		while (j < env->size)
		{
			if ((env->tab_room[i]->coord_x == env->tab_room[j]->coord_x)
				&& (env->tab_room[i]->coord_y == env->tab_room[j]->coord_y))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int			ft_check_parsing(t_env *env)
{
	if (env->ants <= 0)
		ft_parse_error(1, env);
	else if (env->size == 0)
		ft_parse_error(2, env);
	else if (env->start < 0)
		ft_parse_error(3, env);
	else if (env->end < 0)
		ft_parse_error(4, env);
	else if (env->tab_room == NULL)
		ft_parse_error(5, env);
	else if (env->tab_room[env->start]->link == NULL)
		ft_parse_error(5, env);
	else if (env->tab_room[env->end]->link == NULL)
		ft_parse_error(6, env);
	else if (!ft_check_coordinates(env))
		ft_parse_error(7, env);
	else
		return (1);
	return (1);
}
