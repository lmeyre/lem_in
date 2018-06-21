/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 19:30:32 by lmeyre            #+#    #+#             */
/*   Updated: 2018/04/13 00:43:22 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		display_bonus_path(t_env *env, int i, int j)
{
	t_list	*clone;
	int		count;
	int		size;

	size = 0;
	reset_clone(env);
	clone = env->clone;
	while (clone)
	{
		++size;
		clone = clone->next;
	}
	while (j < size)
	{
		count = 0;
		while (i < env->ants)
		{
			if (env->tab_ant[i]->path_nbr == j)
				++count;
			++i;
		}
		ft_printf("%d fourmis ont prit le chemin %d\n", count, j + 1);
		i = 0;
		j++;
	}
}

void		show_path(t_env *env)
{
	int i;

	i = 1;
	ft_printf("Liste des chemins :\n");
	while (env->tab_path->next)
	{
		ft_printf("Chemin numero %d = ", i);
		ft_rchar_tab(env->tab_path->content);
		++i;
		env->tab_path = env->tab_path->next;
	}
	ft_printf("Chemin numero %d = ", i);
	ft_rchar_tab(env->tab_path->content);
	while (env->tab_path->prev)
		env->tab_path = env->tab_path->prev;
	ft_printf("Fin de la liste des chemins\n");
}

void		free_path_element(t_list **lst)
{
	t_list	*tmp_next;
	int		i;

	if (lst == NULL)
		return ;
	i = 0;
	while ((*lst)->next != NULL)
	{
		tmp_next = (*lst)->next;
		ft_free_strtab((char***)&((*lst)->content));
		free((*lst));
		(*lst) = tmp_next;
	}
	ft_free_strtab(((char ***)&((((*lst))->content))));
	free((*lst));
	(*lst) = NULL;
}

t_list		*clone_lst(t_list *lst, t_env *env, int i)
{
	t_list	*tmp;

	tmp = env->tab_path;
	while (tmp)
	{
		while (((char**)tmp->content)[i])
			++i;
		if (!lst)
			lst = ft_lst_new(sizeof(char*) * (i + 1));
		else
			ft_lst_add_end(&lst, ft_lst_new(sizeof(char*) * (i + 1)));
		while (lst->next)
			lst = lst->next;
		i = 0;
		while (((char**)tmp->content)[i])
		{
			((char**)lst->content)[i] = ft_strdup(((char**)tmp->content)[i]);
			++i;
		}
		i = 0;
		tmp = tmp->next;
	}
	while (lst->prev)
		lst = lst->prev;
	return (lst);
}
