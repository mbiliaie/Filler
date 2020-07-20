/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 16:54:08 by mbiliaie          #+#    #+#             */
/*   Updated: 2018/10/17 16:54:17 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

short int		dump_memory(void **mem)
{
	if (mem != NULL)
	{
		free(*mem);
		*mem = NULL;
	}
	return (0);
}

static void		fill_tok_struct(int stepup, struct s_obj *figure, char *txt)
{
	char		needle;
	char		*aim;

	needle = ' ';
	aim = ft_strchr(txt, needle);
	clear_object(figure, stepup);
	figure->vert_dim = ft_atoi(txt);
	figure->hor_dim = ft_atoi(aim);
	figure->vol = figure->vert_dim * figure->hor_dim;
}

short int		dump_string(char **txt)
{
	if (txt != NULL)
	{
		free(*txt);
		*txt = NULL;
	}
	return (0);
}

short int		clear_object(struct s_obj *figure, int stepup)
{
	int			x;
	short int	out;
	char		*txt;

	out = -1;
	x = out;
	if (!figure->keys)
	{
		return (out);
	}
	while (figure->vert_dim > ++x)
	{
		txt = figure->keys[x] - stepup;
		dump_string(&txt);
	}
	dump_memory((void **)&figure->keys);
	return (x);
}

short int		load_object(char *txt, int stepup, struct s_obj *figure)
{
	short		stdin;
	short		out;
	int			x;
	char		needle;

	needle = ' ';
	stdin = 0;
	txt = ft_strchr(txt, needle) + 1;
	out = -1;
	x = out;
	fill_tok_struct(stepup, figure, txt);
	if (stepup)
	{
		get_next_line(stdin, &txt);
		dump_string(&txt);
	}
	figure->keys = ft_memalloc(figure->vert_dim * sizeof(char *));
	while (figure->vert_dim > ++x)
	{
		get_next_line(stdin, &txt);
		figure->keys[x] = txt + stepup;
	}
	return (out);
}
