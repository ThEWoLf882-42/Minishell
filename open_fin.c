/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_fin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 22:42:07 by agimi             #+#    #+#             */
/*   Updated: 2023/05/25 19:06:36 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	open_fin(t_pipe *sp)
{
	t_fin	*fin;

	fin = sp->fin;
	while (fin)
	{
		fin->fd = open(fin->file, fin->flag);
		if (fin->fd == -1)
			print_error(fin->file, 1, 1);
		dup2(fin->fd, 0);
		// if (fin->herdoc == 1)
		// 	herdoc();
		fin = fin->nxt;
	}
}
