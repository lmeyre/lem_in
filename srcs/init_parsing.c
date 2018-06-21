/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 14:46:47 by ndelest           #+#    #+#             */
/*   Updated: 2018/04/22 16:24:41 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_parse_ants(char *line, t_env *env)
{
	int		i;

	i = 0;
	while (line[i] != 0)
	{
		if (line[i] < 48 || line[i] > 57)
			return (0);
		i++;
	}
	if (!ft_checkint_positive(line, &env->ants, i))
		return (0);
	env->ants_start = env->ants;
	return (1);
}

static int	ft_parse_command(char *line, t_env *env)
{
	if (ft_strcmp(line, "##start") == 0)
	{
		if (env->end < -1)
		{
			env->start = -3;
			env->end = -2;
		}
		else
			env->start = -2;
	}
	else if (ft_strcmp(line, "##end") == 0)
	{
		if (env->start < -1)
		{
			env->end = -3;
			env->start = -2;
		}
		else
			env->end = -2;
	}
	return (1);
}

static int	ft_parse_args(char *line, t_env *env, t_room **room_chained)
{
	if (env->ants_start == -1 && line[0] != '#')
		ft_parse_ants(line, env);
	else if (line[0] == '#')
		return (ft_parse_command(line, env));
	else if (line[0] == 'L')
		return (0);
	else
		return (ft_parse_room(line, env, room_chained));
	return (1);
}

int			ft_init_parsing(t_env *env)
{
	char	*line;
	t_room	*room_chained;

	room_chained = NULL;
	while (get_next_line(0, &line) != 0)
	{
		if (line != NULL)
			if (!ft_parse_args(line, env, &room_chained))
			{
				ft_strdel(&line);
				return (1);
			}
		ft_printf("%s\n", line);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	room_chained = NULL;
	return (1);
}
