/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_putpath.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 18:15:35 by ndelest           #+#    #+#             */
/*   Updated: 2018/04/22 16:39:58 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_map_makepath2(char **map, int *x, int *y, int color)
{
	while (y[0] != y[1])
	{
		if (y[0] > y[1])
			y[0] = y[0] - 1;
		else
			y[0] = y[0] + 1;
		if (map[y[0]][x[0]] == '.')
			map[y[0]][x[0]] = color - 32;
	}
	while (x[0] != x[1])
	{
		if (x[0] > x[1])
			x[0] = x[0] - 1;
		else
			x[0] = x[0] + 1;
		if (map[y[0]][x[0]] == '.')
			map[y[0]][x[0]] = color;
	}
}

static void	ft_map_makepath1(char **map, int *x, int *y, int color)
{
	while (x[0] != x[1])
	{
		if (x[0] > x[1])
			x[0] = x[0] - 1;
		else
			x[0] = x[0] + 1;
		if (map[y[0]][x[0]] == '.')
			map[y[0]][x[0]] = color;
	}
	while (y[0] != y[1])
	{
		if (y[0] > y[1])
			y[0] = y[0] - 1;
		else
			y[0] = y[0] + 1;
		if (map[y[0]][x[0]] == '.')
			map[y[0]][x[0]] = color - 32;
	}
}

static void	ft_map_choosepath(char **map, int *x, int *y, int color)
{
	if (y[0] > y[1])
		ft_map_makepath2(map, x, y, color);
	else
		ft_map_makepath1(map, x, y, color);
}

static int	ft_find_coord(char *current, t_room **tab_room, int coord)
{
	int		i;

	i = 0;
	while (ft_strcmp(current, tab_room[i]->name) != 0)
		i++;
	if (coord == 0)
		return (tab_room[i]->coord_x);
	else
		return (tab_room[i]->coord_y);
}

void		ft_launch_path(t_env *env, char **map, t_list *tmp, int j)
{
	int		x[2];
	int		y[2];
	int		i;

	while (tmp)
	{
		i = 0;
		x[0] = ft_find_coord(((char **)tmp->content)[i], env->tab_room, 0);
		y[0] = ft_find_coord(((char **)tmp->content)[i], env->tab_room, 1);
		i++;
		while (((char **)tmp->content)[i] != NULL)
		{
			x[1] = ft_find_coord(((char **)tmp->content)[i], env->tab_room, 0);
			y[1] = ft_find_coord(((char **)tmp->content)[i], env->tab_room, 1);
			ft_map_choosepath(map, x, y, 97 + j);
			x[0] = x[1];
			y[0] = y[1];
			i++;
		}
		j++;
		if (j > 7)
			j = 0;
		tmp = tmp->next;
	}
}
