/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_ek_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 14:16:14 by sadahan           #+#    #+#             */
/*   Updated: 2020/03/10 16:28:24 by sadahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static void		fill_mat_capacity(t_anthill *a, int i, int **m)
{
	int			j;

	j = -1;
	while (++j < a->nb_room * 2)
		m[i][j] = 0;
	if (i < a->nb_room)
		m[i][i + a->nb_room] = 1;
	else
	{
		j = -1;
		while (++j < a->inter_nodes[i]->size)
			if (a->inter_nodes[i]->tab[j] != i - a->nb_room)
				m[i][a->inter_nodes[i]->tab[j]] = 1;
	}
}

int				**init_mat_capacity(t_anthill *a)
{
	int			**m;
	int			i;

	i = -1;
	if (!(m = (int **)malloc(sizeof(int *) * a->nb_room * 2)))
		exit(-2);
	while (++i < a->nb_room * 2)
	{
		if (!(m[i] = (int *)malloc(sizeof(int) * a->nb_room * 2)))
			exit(-2);
		fill_mat_capacity(a, i, m);
	}
	m[a->start][a->start + a->nb_room] = MAX_ANT;
	m[a->start + a->nb_room][a->start] = MAX_ANT;
	m[a->end][a->end + a->nb_room] = MAX_ANT;
	m[a->end + a->nb_room][a->end] = MAX_ANT;
	return (m);
}

int				**init_matrice(int size, int nb)
{
	int			**m;
	int			i;
	int			j;

	i = -1;
	if (!(m = (int **)malloc(sizeof(int *) * size)))
		exit(-2);
	while (++i < size)
	{
		if (!(m[i] = (int *)malloc(sizeof(int) * size)))
			exit(-2);
		j = -1;
		while (++j < size)
			m[i][j] = nb;
	}
	return (m);
}

int				*init_parent(int size)
{
	int			*parent;
	int			i;

	i = -1;
	if (!(parent = (int *)malloc(sizeof(int) * size)))
		exit(-2);
	while (++i < size)
		parent[i] = -1;
	return (parent);
}

void			reset_parent(int *parent, int size, t_anthill *a)
{
	int			i;

	i = -1;
	while (++i < size)
		parent[i] = -1;
	parent[a->start] = -2;
}
