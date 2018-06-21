/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_launch_visual.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 16:54:08 by ndelest           #+#    #+#             */
/*   Updated: 2018/04/19 20:40:00 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_search_room(t_env *env, t_list *tmp, int i, int j)
{
	int		id_room;
	char	*room_name;

	room_name = env->tab_room[i]->name;
	id_room = i;
	i = 0;
	while (((char **)tmp->content)[i] != NULL)
	{
		if (ft_strcmp(room_name, ((char **)tmp->content)[i]) == 0)
		{
			choose_color(j, env);
			ft_printf("%c", id_room + 48);
			ft_printf(EOC);
			return (1);
		}
		i++;
	}
	return (0);
}

static void	ft_print_room(t_env *env, int id_room)
{
	int		j;
	t_list	*tmp;

	j = 0;
	if (id_room == env->start || id_room == env->end)
	{
		ft_printf("%c", id_room + 48);
		return ;
	}
	tmp = env->tab_path;
	while (tmp)
	{
		if (ft_search_room(env, tmp, id_room, j))
			return ;
		j++;
		if (j > 7)
			j = 0;
		tmp = tmp->next;
	}
	ft_printf("%c", id_room + 48);
}

static void	ft_print_path(t_env *env, int path)
{
	if (path >= 97)
	{
		choose_color(path - 97, env);
		ft_printf("-");
		ft_printf(EOC);
	}
	else
	{
		choose_color(path - 65, env);
		ft_printf("|");
		ft_printf(EOC);
	}
}

static void	ft_print_data(t_env *env)
{
	int		i;
	t_list	*tmp;

	i = 0;
	ft_printf("\nLEGENDE :\n");
	i = 0;
	while (i < env->size)
	{
		ft_printf("Room number %c : %s    ", i + 48, env->tab_room[i]->name);
		i++;
		if (i % 2 == 0)
			write(1, "\n", 1);
	}
	ft_printf("\n\n");
	i = 0;
	tmp = env->tab_path;
	while (tmp)
	{
		choose_color(i++, env);
		ft_printf("Chemin %d\n", i);
		ft_printf(EOC);
		tmp = tmp->next;
	}
}

int			ft_launch_map(char **map, t_env *env)
{
	int		i;
	int		j;

	i = 0;
	ft_printf("\n\n");
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != 0)
		{
			if (map[i][j] >= 48 && map[i][j] <= 64)
				ft_print_room(env, (int)map[i][j] - 48);
			else if ((map[i][j] >= 65 && map[i][j] <= 112))
				ft_print_path(env, (int)map[i][j]);
			else if (map[i][j] == '.')
				ft_printf(" ");
			else
				ft_printf("%c", map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	ft_print_data(env);
	return (1);
}
