/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 16:15:35 by ndelest           #+#    #+#             */
/*   Updated: 2018/04/19 12:04:21 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_room_add_last(t_room **begin, t_room *new)
{
	t_room *tmp;

	tmp = *begin;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

static void	ft_checkmax_coord(t_env *env, t_room *room)
{
	if (room->coord_x > env->max_x)
		env->max_x = room->coord_x;
	if (room->coord_y > env->max_y)
		env->max_y = room->coord_y;
}

static void	ft_checkfor_startend(t_env *env)
{
	if (env->start < env->end)
		env->start = env->size - 1;
	else
		env->end = env->size - 1;
}

static int	ft_make_room(char *line, t_env *env, t_room **room_chained)
{
	int		i;
	char	**tab;
	t_room	*room;

	if (!(tab = ft_strsplit(line, ' ')))
		exit(EXIT_FAILURE);
	i = 0;
	while (tab[i] != NULL)
		i++;
	if (i != 3)
		return (ft_deltab(tab));
	if (!(room = init_room(tab)))
		return (ft_deltab(tab));
	if (env->size == INT_MAX)
		return (0);
	env->size++;
	ft_checkmax_coord(env, room);
	if (*room_chained == NULL)
		*room_chained = room;
	else
		ft_room_add_last(room_chained, room);
	if (env->start < -1 || env->end < -1)
		ft_checkfor_startend(env);
	ft_deltab(tab);
	return (1);
}

int			ft_parse_room(char *line, t_env *env, t_room **room_chained)
{
	int		i;

	i = 0;
	while (line[i] != 0)
	{
		if (line[i] == '-')
		{
			if (*room_chained == NULL)
				return (0);
			if (env->tab_room == NULL)
				env = ft_create_envtab(env, *room_chained);
			env->tube = 1;
			return (ft_check_link(line, env, 0, 0));
		}
		i++;
	}
	if (env->tube == 0)
		return (ft_make_room(line, env, room_chained));
	else
		return (0);
}
