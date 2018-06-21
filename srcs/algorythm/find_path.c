/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 00:49:06 by lmeyre            #+#    #+#             */
/*   Updated: 2018/04/19 13:28:13 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			exception_link(t_env *env, int room)
{
	t_list *tmp;

	if (room != env->start)
		return (0);
	tmp = env->tab_room[room]->link;
	while (tmp)
	{
		if (*(int*)tmp->content == env->end)
			return (42);
		tmp = tmp->next;
	}
	return (0);
}

static void	fill_lock_path(int tmp, t_env *env)
{
	if (tmp != env->start && tmp != env->end)
	{
		if (!env->blackroom)
			env->blackroom = ft_lst_new(sizeof(int*));
		else
		{
			ft_lst_add_end(&env->blackroom, ft_lst_new(sizeof(int*)));
			while (env->blackroom->next)
				env->blackroom = env->blackroom->next;
		}
		*(int*)(env->blackroom->content) = tmp;
	}
}

static int	lock_path(t_env *env, int room, int i)
{
	int tmp;

	while (env->tab_room[room]->finder != -1)
	{
		++i;
		if (room == env->start)
			break ;
		room = env->tab_room[room]->finder;
	}
	room = env->end;
	env->tab_path->content = (char**)malloc(sizeof(char*) * (i + 1 + 1));
	((char**)env->tab_path->content)[i + 1] = NULL;
	while (i >= 0)
	{
		((char**)(env->tab_path->content))[i] =
		ft_strdup(env->tab_room[room]->name);
		--i;
		tmp = room;
		room = env->tab_room[room]->finder;
		env->tab_room[tmp]->finder = -1;
		fill_lock_path(tmp, env);
	}
	reset_blackroom(env);
	return (1);
}

static void	destroy_last_path(t_env *env)
{
	while (env->tab_path->next)
		env->tab_path = env->tab_path->next;
	ft_free_strtab((char***)&env->tab_path->content);
	env->tab_path = env->tab_path->prev;
	free(env->tab_path->next);
	env->tab_path->next = NULL;
	while (env->tab_path->prev)
		env->tab_path = env->tab_path->prev;
}

int			find_path(t_env *env)
{
	t_list	*tmp;
	int		nbr;

	nbr = 0;
	env->tab_path = ft_lst_new(0);
	while (queue_work(env, NULL, NULL) == 42)
	{
		++nbr;
		free_list(&(env->queue));
		free_list(&(env->scanned));
		lock_path(env, env->end, 0);
		ft_lst_add_end(&env->tab_path, ft_lst_new(0));
		while (env->tab_path->next)
			env->tab_path = env->tab_path->next;
	}
	if (nbr == 0)
		ft_parse_error(8, env);
	reset_path(env);
	destroy_last_path(env);
	tmp = env->tab_path;
	return (1);
}
