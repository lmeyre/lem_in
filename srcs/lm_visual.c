/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_visual.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 14:01:28 by ndelest           #+#    #+#             */
/*   Updated: 2018/04/19 18:51:52 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_map_room(t_env *env, char **map)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	while (i < env->size)
	{
		y = env->tab_room[i]->coord_y;
		x = env->tab_room[i]->coord_x;
		map[y][x] = i + 48;
		i++;
	}
}

static void	ft_map_path(t_env *env, char **map)
{
	t_list	*tmp;

	tmp = env->tab_path;
	ft_launch_path(env, map, tmp, 0);
}

static char	**ft_domap(t_env *env)
{
	char	**map;
	int		i;

	if (!(map = malloc(sizeof(*map) * (env->max_y + 3))))
		exit(EXIT_FAILURE);
	i = 0;
	while (i < env->max_y + 2)
	{
		if (!(map[i] = malloc(sizeof(**map) * (env->max_x + 3))))
			exit(EXIT_FAILURE);
		ft_memset(map[i], '.', env->max_x + 2);
		map[i][env->max_x + 2] = 0;
		i++;
	}
	map[i] = NULL;
	ft_map_room(env, map);
	ft_map_path(env, map);
	ft_map_link(env, map);
	return (map);
}

int			ft_init_visual(t_env *env)
{
	char	**map;

	map = ft_domap(env);
	ft_launch_map(map, env);
	ft_deltab(map);
	write(1, "\n", 1);
	return (1);
}
