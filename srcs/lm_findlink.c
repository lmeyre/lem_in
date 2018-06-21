/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_findlink.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 18:16:59 by ndelest           #+#    #+#             */
/*   Updated: 2018/04/22 16:15:00 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_map_makelink2(char **map, int *x, int *y)
{
	int		a;
	int		b;

	a = x[0];
	b = y[0];
	while (b != y[1])
	{
		if (b > y[1])
			b--;
		else
			b++;
		if (map[b][a] == '.')
			map[b][a] = '|';
	}
	while (a != x[1])
	{
		if (a > x[1])
			a--;
		else
			a++;
		if (map[b][a] == '.')
			map[b][a] = '-';
	}
}

static void	ft_map_makelink1(char **map, int *x, int *y)
{
	int		a;
	int		b;

	a = x[0];
	b = y[0];
	while (a != x[1])
	{
		if (a > x[1])
			a--;
		else
			a++;
		if (map[b][a] == '.')
			map[b][a] = '-';
	}
	while (b != y[1])
	{
		if (b > y[1])
			b--;
		else
			b++;
		if (map[b][a] == '.')
			map[b][a] = '|';
	}
}

static void	ft_map_chooselink(char **map, int *x, int *y)
{
	if (y[0] > y[1])
		ft_map_makelink2(map, x, y);
	else
		ft_map_makelink1(map, x, y);
}

void		ft_map_link(t_env *env, char **map)
{
	int		i;
	int		x[2];
	int		y[2];
	t_room	*room;
	t_list	*link;

	i = 0;
	while (i < env->size)
	{
		x[0] = env->tab_room[i]->coord_x;
		y[0] = env->tab_room[i]->coord_y;
		link = env->tab_room[i]->link;
		while (link != NULL)
		{
			room = env->tab_room[*((int *)link->content)];
			x[1] = room->coord_x;
			y[1] = room->coord_y;
			ft_map_chooselink(map, x, y);
			link = link->next;
		}
		i++;
	}
}
