/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 18:18:36 by ndelest           #+#    #+#             */
/*   Updated: 2018/06/21 18:45:48 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_debug_printroom(t_env *env)
{
	int		i;
	t_list	*list;

	i = 0;
	while (i < env->size)
	{
		ft_printf("Salle numero : %d\n", i);
		ft_printf("Nom : %s\n", env->tab_room[i]->name);
		ft_printf("Room find by this one : %d\n", env->tab_room[i]->finder);
		ft_printf("Coordinate x : %d\n", env->tab_room[i]->coord_x);
		ft_printf("Coordonnees y : %d\n", env->tab_room[i]->coord_y);
		ft_printf("ID of the ant in the room: %d\n", env->tab_room[i]->ant_id);
		list = env->tab_room[i]->link;
		while (list)
		{
			ft_printf("Link with the room number %d\n",
					*((int *)list->content));
			list = list->next;
		}
		ft_printf("_____________________\n");
		i++;
	}
}

static void	ft_debug_printenv(t_env *env)
{
	ft_printf("***DEBUG - AFFICHAGE DE ENV***\n");
	ft_printf("Numero salle de depart : %d\n", env->start);
	ft_printf("Numero salle d'arrivee : %d\n", env->end);
	ft_printf("Nombre de salles differentes : %d\n", env->size);
	ft_printf("Nombre de fourmis au depart : %d\n", env->ants_start);
	ft_printf("Nombre de fourmis a l'arrivee' : %d\n", env->ants_end);
	ft_printf("Step : %d\n", env->step);
	ft_printf("\n***DEBUG - AFFICHAGE DES DONNEES ROOM (tab_room)***\n");
	ft_debug_printroom(env);
}

int			main(int ac, char **av)
{
	t_env env;

	env = init_value();
	if (ac > 1)
		ft_parse_bonus(av[1], &env);
	ft_init_parsing(&env);
	write(1, "\n", 1);
	ft_check_parsing(&env);
	if (env.bonus[2] != 0)
		ft_debug_printenv(&env);
	find_path(&env);
	init_ants(&env);
	if (env.bonus[0] != 0 && (env.max_x > 100 || env.max_y > 100))
		ft_printf("Option 'v' not activated : Ant-hill is too large.\n");
	else if (env.bonus[0] != 0)
		ft_init_visual(&env);
	if (env.bonus[5] == 1)
		show_path(&env);
	split_path(&env, 1, 0, 0);
	exit(EXIT_SUCCESS);
	return (0);
}
