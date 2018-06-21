/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ant.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 00:14:00 by lmeyre            #+#    #+#             */
/*   Updated: 2018/04/19 15:55:45 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		send_ant(t_env *env, int i, int ant, char **path)
{
	t_list		*tmppath;

	tmppath = NULL;
	ant = sort_true_ants(env);
	if (ant == -1)
		return ;
	if (env->tab_ant[ant]->path_nbr == -1)
		ant_no_path(env, &path, ant);
	else if (!ft_strcmp(env->tab_ant[ant]->room, env->tab_room[env->end]->name))
		return ;
	else
		link_ant_path(&path, env, ant, tmppath);
	while (ft_strcmp(path[i], env->tab_ant[ant]->room) != 0)
		++i;
	++i;
	env->tab_ant[ant]->room = ft_strdup_free(path[i], &env->tab_ant[ant]->room);
	choose_color(env->tab_ant[ant]->path_nbr, env);
	ft_printf("L%d-%s ", env->tab_ant[ant]->id, path[i]);
	(env->bonus[4] == 1) ? ft_printf(EOC) : 0;
	if (ft_strcmp(env->tab_ant[ant]->room, env->tab_room[env->end]->name) == 0)
	{
		env->tab_ant[ant]->awake = 1;
		++(env->ants_end);
	}
	env->tab_ant[ant]->manage = 0;
}

int			sort_true_ants(t_env *env)
{
	int ant;

	ant = 0;
	while (ant < env->ants)
	{
		if (env->tab_ant[ant]->manage == 1)
			return (ant);
		++ant;
	}
	return (-1);
}

void		reset_true_ants(t_env *env)
{
	int ant;

	ant = 0;
	while (ant < env->ants)
	{
		if (env->tab_ant[ant]->manage == 0)
			if (ft_strcmp(env->tab_ant[ant]->room,
				env->tab_room[env->end]->name) != 0)
				env->tab_ant[ant]->manage = 1;
		++ant;
	}
}

void		choose_color(int nbr, t_env *env)
{
	if (env->bonus[4] == 0)
		return ;
	while (nbr > 6)
	{
		if (nbr - 6 > 0)
			nbr -= 6;
	}
	if (nbr == 0)
		ft_printf(CYAN);
	else if (nbr == 1)
		ft_printf(MAGENTA);
	else if (nbr == 2)
		ft_printf(RED);
	else if (nbr == 3)
		ft_printf(YELLOW);
	else if (nbr == 4)
		ft_printf(GREEN);
	else if (nbr == 5)
		ft_printf(BLUE);
	else if (nbr == 6)
	{
		ft_printf(BLACK);
		ft_printf(BGWHITE);
	}
}
