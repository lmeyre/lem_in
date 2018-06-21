/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 19:45:48 by lmeyre            #+#    #+#             */
/*   Updated: 2018/04/19 13:28:40 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		more_path(int count, t_list *path, int size, int nbr_path)
{
	t_list	*compare;
	int		new_count;
	int		new_ants;

	compare = path->next;
	while (((char**)(compare)->content)[size] != NULL)
		++(size);
	--size;
	new_ants = 1;
	new_count = size + (new_ants - 1 / nbr_path);
	if (new_count > count)
		return (-1);
	while (new_count < count)
	{
		new_ants++;
		new_count = size + (new_ants - 1 / nbr_path);
	}
	new_count = size + (new_ants - 2);
	return (new_count);
}

static int		nbr_good_path(t_env *env, int nbr_path,
				int count_bis, int count)
{
	int		size;
	t_list	*tmp;

	tmp = env->tab_path;
	size = 0;
	while (((char**)(tmp)->content)[size] != NULL)
		++(size);
	--size;
	count = size + (env->ants_start - 1);
	while (tmp->next != NULL && nbr_path < env->ants_start
		&& ((count_bis = more_path(count, tmp, 0, nbr_path)) != -1))
	{
		++nbr_path;
		tmp = tmp->next;
		count = count_bis;
	}
	if (tmp->next != NULL)
		free_path_element(&tmp->next);
	return (nbr_path);
}

void			awake_ant(t_env *env)
{
	int	i;

	i = 0;
	while (env->activ_ant && i < env->ants)
	{
		if (env->tab_ant[i]->awake == -1)
		{
			env->tab_ant[i]->awake = 0;
			env->activ_ant--;
		}
		i++;
	}
}

void			split_path(t_env *env, int round, int i, int good_path)
{
	env->clone = clone_lst(env->clone, env, 0);
	reset_path(env);
	env->ant_path = env->tab_path;
	while (env->ants_end < env->ants)
	{
		good_path = nbr_good_path(env, 1, 0, 0);
		env->activ_ant = good_path;
		awake_ant(env);
		i = 0;
		while (i < env->ants && env->tab_ant[i]->awake != 0)
			++i;
		while (i < env->ants)
		{
			send_ant(env, 0, 0, NULL);
			++i;
			while (i < env->ants && env->tab_ant[i]->awake != 0)
				++i;
		}
		env->ants_start -= good_path;
		++round;
		ft_putchar('\n');
		reset_true_ants(env);
	}
	if (env->bonus[3] == 1)
		display_bonus_path(env, 0, 0);
}
