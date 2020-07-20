/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 16:46:33 by mbiliaie          #+#    #+#             */
/*   Updated: 2018/10/17 16:46:57 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"

struct				s_obj
{
	char			**keys;
	int				hor_dim;
	int				vol;
	int				vert_dim;
};

typedef struct		s_load
{
	short int		sp_x;
	short int		sp_y;
	short int		result;
}					t_load;

struct				s_sp
{
	int				y;
	int				x;
};

struct				s_side
{
	struct s_sp		st;
	char			sign;
};

struct				s_gs
{
	struct s_sp		*d_bff;
	struct s_side	gg;
	int				activated;
	struct s_side	foe;
	struct s_sp		aim;
	struct s_obj	field;
	int				s_num;
	struct s_obj	figure;
	int				d_num;
	char			p_num;
	struct s_sp		*s_bff;
};

short int			clear_object(struct s_obj *figure, int stepup);
short int			load_object(char *line, int stepup, struct s_obj *figure);
short int			run(struct s_gs *gen);
short int			dump_string(char **txt);
short int			dump_memory(void **mem);
short int			start_filler(char player_num, struct s_gs *gen);
int					fill_nearest_arr(struct s_gs *gen);
int					fl_target_check(int a);
short int			interval(struct s_sp a, struct s_sp b);
struct s_sp			nearest_coord(struct s_gs gen);
short int			check_spot(struct s_gs gen, struct s_sp spot);
short int			check_try(struct s_sp spot, struct s_gs gen);
short int			check_position(struct s_sp spot, struct s_gs gen);
short int			form_arr(struct s_gs *gen);
short int			spot_ok(struct s_gs gen, struct s_sp spot);
short int			position(struct s_gs gen);
struct s_sp			count_coord(short	fin_len, struct s_gs gen);
struct s_sp			get_spot(struct s_gs gen);
struct s_sp			loop_for_spot (struct s_gs gen, struct s_sp p);
short				beset(struct s_gs gen, struct s_sp p, struct s_sp *result);

#endif
