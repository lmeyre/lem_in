/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_ant_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 00:34:34 by lmeyre            #+#    #+#             */
/*   Updated: 2018/04/13 00:36:04 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ant_no_path(t_env *env, char ***path, int ant)
{
	static int	jpath = 0;

	*path = env->ant_path->content;
	env->tab_ant[ant]->path_nbr = jpath;
	if (env->ant_path->next)
	{
		jpath++;
		env->ant_path = env->ant_path->next;
	}
	else
	{
		while (env->ant_path->prev)
			env->ant_path = env->ant_path->prev;
		jpath = 0;
	}
}

void		link_ant_path(char ***path, t_env *env, int ant, t_list *tmppath)
{
	int tmp;

	tmp = env->tab_ant[ant]->path_nbr;
	reset_clone(env);
	tmppath = env->clone;
	while (tmp)
	{
		env->clone = env->clone->next;
		tmp--;
	}
	if (env->clone == NULL)
	{
		env->clone = tmppath;
		tmp = env->tab_ant[ant]->path_nbr;
		while (tmp)
		{
			env->clone = env->clone->next;
			tmp--;
		}
		*path = env->clone->content;
		reset_clone(env);
	}
	else
		*path = env->clone->content;
	reset_path(env);
}
