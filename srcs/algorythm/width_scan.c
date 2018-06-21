/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_scan.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 01:06:25 by lmeyre            #+#    #+#             */
/*   Updated: 2018/04/13 02:25:49 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		verify_child(t_env *env, int room)
{
	if (!env->queue)
	{
		if (!(env->queue = ft_lst_new(sizeof(int*))))
			exit(EXIT_FAILURE);
	}
	else
	{
		if (!(ft_lst_add_end(&(env->queue), ft_lst_new(sizeof(int*)))))
			exit(EXIT_FAILURE);
		while (env->queue->next)
			env->queue = env->queue->next;
	}
	*((int*)env->queue->content) = *((int*)env->tab_room[room]->link->content);
	env->tab_room[*((int*)env->tab_room[room]->link->content)]->finder = room;
}

static void		assign_value(t_env *env, int room)
{
	if (!env->scanned)
	{
		if (!(env->scanned = ft_lst_new(sizeof(int*))))
			exit(EXIT_FAILURE);
	}
	else
	{
		if (!(ft_lst_add_end(&(env->scanned), ft_lst_new(sizeof(int*)))))
			exit(EXIT_FAILURE);
		while (env->scanned->next)
			env->scanned = env->scanned->next;
	}
	*((int*)env->scanned->content) = room;
}

static int		add_child_queue(t_env *env, int room)
{
	t_list *tmplst;

	tmplst = env->tab_room[room]->link;
	if (env->tab_room[room]->link == NULL)
		return (1);
	while (env->tab_room[room]->link)
	{
		if (check_scanned(env, *(int*)env->tab_room[room]->link->content) ==
				1 && !(room == env->start
					&& *(int*)env->tab_room[room]->link->content == env->end))
		{
			reset_blackroom(env);
			verify_child(env, room);
		}
		reset_blackroom(env);
		env->tab_room[room]->link = env->tab_room[room]->link->next;
	}
	reset_link(env, room);
	assign_value(env, room);
	env->tab_room[room]->link = tmplst;
	return (1);
}

int				queue_work(t_env *env, t_list *tmp, t_list *head)
{
	static int	exception = 0;

	if (exception == 0 && exception_link(env, env->start) == 42)
	{
		++exception;
		env->tab_room[env->end]->finder = env->start;
		return (42);
	}
	else
		++exception;
	add_child_queue(env, env->start);
	if (reset_queue(env) == 666 || !env->queue)
		return (0);
	head = env->queue;
	while (env->queue)
	{
		if (*(int*)env->queue->content == env->end)
			return (42);
		tmp = env->queue;
		add_child_queue(env, *(int*)env->queue->content);
		env->queue = tmp;
		env->queue = env->queue->next;
	}
	env->queue = head;
	return (0);
}
