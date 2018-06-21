/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_scan.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 01:16:13 by lmeyre            #+#    #+#             */
/*   Updated: 2018/04/13 01:16:47 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		check_queue(t_env *env, int room)
{
	t_list *tmp;

	tmp = env->queue;
	while (tmp->prev)
		tmp = tmp->prev;
	while (tmp)
	{
		if (room == *(int*)tmp->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static int		check_scan(t_env *env, int room)
{
	while (env->scanned->next)
	{
		if (*(int*)env->scanned->content == room)
			return (0);
		env->scanned = env->scanned->next;
	}
	if (*(int*)env->scanned->content == room)
		return (0);
	reset_scan(env);
	return (1);
}

int				check_scanned(t_env *env, int room)
{
	reset_scan(env);
	if (env->queue && check_queue(env, room) == 0)
		return (0);
	if (!env->scanned && !env->blackroom)
		return (1);
	if (env->scanned && check_scan(env, room) == 0)
		return (0);
	if (!env->blackroom)
		return (1);
	else
	{
		reset_blackroom(env);
		while (env->blackroom->next)
		{
			if (*((int*)env->blackroom->content) == room)
				return (0);
			env->blackroom = env->blackroom->next;
		}
		if (*((int*)env->blackroom->content) == room)
			return (0);
		return (1);
	}
}
