/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 17:32:49 by ndelest           #+#    #+#             */
/*   Updated: 2018/04/19 12:08:15 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_check_coord(char *str, int *coord)
{
	int		i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
		i++;
	}
	if (!ft_checkint_positive(str, coord, i))
		return (0);
	return (1);
}

t_room		*init_room(char **tab)
{
	t_room	*new;

	if (!(new = malloc(sizeof(*new))))
		exit(EXIT_FAILURE);
	if (!(new->name = ft_strdup(tab[0])))
		exit(EXIT_FAILURE);
	if (!ft_check_coord(tab[1], &new->coord_x) ||
			!ft_check_coord(tab[2], &new->coord_y))
		return (NULL);
	new->finder = -1;
	new->link = NULL;
	new->ant_id = 0;
	new->next = NULL;
	return (new);
}
