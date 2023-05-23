/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_fin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 22:42:07 by agimi             #+#    #+#             */
/*   Updated: 2023/05/23 22:49:16 by agimi            ###   ########.fr       */
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
			perror("");
		if (fin->herdoc == 1)
			herdoc();
		fin = fin->nxt;
	}
}
