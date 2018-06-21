/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 02:30:13 by lmeyre            #+#    #+#             */
/*   Updated: 2018/04/19 20:45:12 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/includes/libft.h"

typedef struct			s_room
{
	char				*name;
	int					finder;
	int					coord_x;
	int					coord_y;
	int					ant_id;
	t_list				*link;
	struct s_room		*next;

}						t_room;

typedef struct			s_ant
{
	int					id;
	char				*room;
	int					path_nbr;
	int					manage;
	int					awake;
}						t_ant;

typedef struct			s_env
{
	t_room				**tab_room;
	int					start;
	int					end;
	int					tube;
	t_list				*queue;
	t_list				*scanned;
	t_list				*blackroom;
	int					step;
	int					ants;
	t_list				*tab_path;
	t_list				*clone;
	struct s_ant		**tab_ant;
	int					size;
	int					ants_start;
	int					ants_end;
	int					path_nbr;
	int					bonus[6];
	int					max_x;
	int					max_y;
	int					tmp;
	t_list				*ant_path;
	int					activ_ant;
}						t_env;

/*
 ** Initialisation  & Free_list
*/
t_env					init_value(void);
void					init_ants(t_env *env);
void					free_list(t_list **lst);

/*
 ** Parseur
*/
int						ft_parse_room(char *line,
						t_env *env, t_room **room_chained);
t_room					*init_room(char **tab);
int						ft_init_parsing(t_env *env);
int						ft_parse_room(char *line,
						t_env *env, t_room **room_chained);
int						ft_parse_error(int error, t_env *env);
int						ft_check_parsing(t_env *env);
void					ft_parse_bonus(char *str, t_env *env);
int						ft_deltab(char **tab);
int						exception_link(t_env *env, int room);
int						ft_checkint_positive(char *str, int *k, int i);

/*
 ** Fonction de l'algorithme
*/
int						find_path(t_env *env);
int						queue_work(t_env *env, t_list *tmp, t_list *head);
int						check_scanned(t_env *env, int room);
void					split_path(t_env *env, int round, int i, int good_path);
void					send_ant(t_env *env, int i, int ant, char **path);
void					ant_no_path(t_env *env, char ***path, int ant);
void					link_ant_path(char ***path,
						t_env *env, int ant, t_list *tmppath);
int						sort_true_ants(t_env *env);
void					reset_true_ants(t_env *env);
void					awake_ant(t_env *env);
void					choose_color(int nbr, t_env *env);

/*
 ** Utilitaire algorithme
*/
int						reset_queue(t_env *env);
void					reset_scan(t_env *env);
void					reset_path(t_env *env);
void					reset_link(t_env *env, int room);
void					reset_clone(t_env *env);
void					reset_blackroom(t_env *env);
void					reset_value(t_env *env);
void					free_path_element(t_list **lst);
t_list					*clone_lst(t_list *lst, t_env *env, int i);

/*
 ** Bonus
*/
int						ft_init_visual(t_env *env);
void					display_bonus_path(t_env *env, int i, int j);
int						ft_launch_map(char **map, t_env *env);
void					ft_launch_path(t_env *env, char **map,
						t_list *tmp, int j);
void					ft_map_link(t_env *env, char **map);
t_env					*ft_create_envtab(t_env *env, t_room *room_chained);
int						ft_check_link(char *line, t_env *env, int i, int j);
void					show_path(t_env *env);

# define BLACK "\x1B[30m"
# define BGWHITE "\x1b[47m"
# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define YELLOW "\x1B[33m"
# define BLUE "\x1B[34m"
# define MAGENTA "\x1B[35m"
# define CYAN "\x1B[36m"
# define EOC "\033[0m"

#endif
