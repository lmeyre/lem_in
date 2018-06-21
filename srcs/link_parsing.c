/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 15:17:32 by ndelest           #+#    #+#             */
/*   Updated: 2018/04/19 12:04:08 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_make_link(t_env *env, int i, int j)
{
	t_list	*list;

	if (!(list = ft_lst_new(sizeof(int))))
		exit(EXIT_FAILURE);
	*((int *)list->content) = j;
	if (env->tab_room[i]->link == NULL)
		env->tab_room[i]->link = list;
	else
		ft_lst_add_end(&(env->tab_room[i]->link), list);
	if (!(list = ft_lst_new(sizeof(int))))
		exit(EXIT_FAILURE);
	*((int *)list->content) = i;
	if (env->tab_room[j]->link == NULL)
		env->tab_room[j]->link = list;
	else
		ft_lst_add_end(&(env->tab_room[j]->link), list);
	return (1);
}

t_env		*ft_create_envtab(t_env *env, t_room *room_chained)
{
	int		i;

	if (!(env->tab_room = malloc(sizeof(t_room *) * env->size)))
		exit(EXIT_FAILURE);
	i = 0;
	while (i < env->size)
	{
		env->tab_room[i] = room_chained;
		room_chained = room_chained->next;
		i++;
	}
	return (env);
}

int			ft_check_link(char *line, t_env *env, int i, int j)
{
	char	**tab;
	int		error;

	error = 0;
	if (!(tab = ft_strsplit(line, '-')))
		exit(EXIT_FAILURE);
	while (tab[i] != NULL)
		i++;
	if (i != 2)
	{
		error = 1;
		ft_deltab(tab);
		return (0);
	}
	i = 0;
	while (i < env->size && ft_strcmp(env->tab_room[i]->name, tab[0]) != 0)
		i++;
	while (j < env->size && ft_strcmp(env->tab_room[j]->name, tab[1]) != 0)
		j++;
	if (j == env->size || i == env->size)
		error = 1;
	ft_deltab(tab);
	if (error == 1)
		return (0);
	return (ft_make_link(env, i, j));
}
