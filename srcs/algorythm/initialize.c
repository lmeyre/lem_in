/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 01:06:05 by lmeyre            #+#    #+#             */
/*   Updated: 2018/04/13 01:28:41 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

t_env		init_value(void)
{
	t_env	env;

	env.tab_room = NULL;
	env.blackroom = NULL;
	env.start = -1;
	env.end = -1;
	env.queue = NULL;
	env.scanned = NULL;
	env.ants_start = -1;
	env.ants_end = 0;
	env.size = 0;
	env.tab_path = NULL;
	env.path_nbr = 0;
	env.tube = 0;
	env.tab_ant = NULL;
	env.max_x = 0;
	env.max_y = 0;
	env.tmp = 0;
	ft_memset(env.bonus, 0, sizeof(int) * 6);
	env.activ_ant = 0;
	env.ants_end = 0;
	env.clone = NULL;
	return (env);
}

void		reset_value(t_env *env)
{
	ft_lst_del_all(&env->queue);
	env->queue = NULL;
	ft_lst_del_all(&env->scanned);
	env->scanned = NULL;
	env->step = 0;
}

void		init_ants(t_env *env)
{
	int i;

	i = 0;
	if (!(env->tab_ant = (t_ant**)malloc(sizeof(t_ant*) * (env->ants))))
		exit(EXIT_FAILURE);
	while (i < env->ants)
	{
		env->tab_ant[i] = (t_ant*)malloc(sizeof(t_ant));
		env->tab_ant[i]->id = i + 1;
		env->tab_ant[i]->room = ft_strdup(env->tab_room[env->start]->name);
		env->tab_ant[i]->path_nbr = -1;
		env->tab_ant[i]->manage = 1;
		env->tab_ant[i]->awake = -1;
		++i;
	}
}

void		free_list(t_list **lst)
{
	t_list *tmp;

	if (!*lst)
		return ;
	while ((*lst)->next)
		*lst = (*lst)->next;
	while ((*lst)->prev)
	{
		if ((*lst)->content)
			free((*lst)->content);
		tmp = *lst;
		*lst = (*lst)->prev;
		free(tmp);
	}
	if ((*lst)->content)
		free((*lst)->content);
	free(*lst);
	*lst = NULL;
}

void		reset_clone(t_env *env)
{
	if (env->clone)
		while (env->clone->prev)
			env->clone = env->clone->prev;
}
