/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:14:50 by agimi             #+#    #+#             */
/*   Updated: 2023/05/27 14:35:32 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	open_fin(t_pipe *sp, int x)
{
	t_fin	*fin;

	fin = sp->fin;
	while (fin)
	{
		fin->fd = open(fin->file, fin->flag);
		if (fin->fd == -1)
		{
			print_error(fin->file, 1, x);
			return (1);
		}
		dup2(fin->fd, 0);
		if (fin->herdoc == 1)
			heredoc(fin);
		close(fin->fd);
		fin = fin->nxt;
	}
	return (0);
}

int	open_fout(t_pipe *sp, int x)
{
	t_fout	*fout;

	fout = sp->fout;
	while (fout)
	{
		fout->fd = open(fout->file, fout->flag, fout->perm);
		if (fout->fd == -1)
		{
			print_error(fout->file, 1, x);
			return (1);
		}
		dup2(fout->fd, 1);
		close(fout->fd);
		fout = fout->nxt;
	}
	return (0);
}

int	open_file(t_pipe *sp, int x)
{
	dup2(0, 69);
	dup2(1, 88);
	if (open_fin(sp, x))
		return (1);
	if (open_fout(sp, x))
		return (1);
	return (0);
}
