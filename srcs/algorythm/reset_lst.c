/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 01:06:16 by lmeyre            #+#    #+#             */
/*   Updated: 2018/04/13 02:26:22 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			reset_queue(t_env *env)
{
	if (env->queue)
		while (env->queue->prev)
			env->queue = env->queue->prev;
	return (1);
}

void		reset_scan(t_env *env)
{
	if (env->scanned)
		while (env->scanned->prev)
			env->scanned = env->scanned->prev;
}

void		reset_blackroom(t_env *env)
{
	if (env->blackroom)
		while (env->blackroom->prev)
			env->blackroom = env->blackroom->prev;
}

void		reset_link(t_env *env, int room)
{
	if (env->tab_room[room]->link)
		while (env->tab_room[room]->link->prev)
			env->tab_room[room]->link = env->tab_room[room]->link->prev;
}

void		reset_path(t_env *env)
{
	if (env->tab_path)
		while (env->tab_path->prev)
			env->tab_path = env->tab_path->prev;
}
