/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:14:50 by agimi             #+#    #+#             */
/*   Updated: 2023/06/09 15:21:17 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redirect_error(char *str, int x)
{
	ft_putstr_fd("minishell-69: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": ambiguous redirect\n", 2);
	if (x)
		exit(1);
	g_va.exit_s = 1;
}

int	open_fin(t_pipe *sp, int x)
{
	t_fin	*fin;

	fin = sp->fin;
	while (fin)
	{
		if (fin->lm->nxt->space || !fin->lm->nxt->shx)
		{
			redirect_error(fin->lm->nxt->bex, x);
			return (1);
		}
		if (!fin->herdoc)
		{
			fin->fd = open(fin->file, fin->flag);
			if (fin->fd == -1)
			{
				print_error(fin->file, 1, x);
				return (1);
			}
		}
		dup2(fin->fd, 0);
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
		if (fout->lm->nxt->space || !fout->lm->nxt->shx)
		{
			redirect_error(fout->lm->nxt->bex, x);
			return (1);
		}
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
	if (g_va.y && !x)
	{
		g_va.exit_s = 1;
		g_va.y = 0;
		return (1);
	}
	dup2(0, 69);
	dup2(1, 88);
	if (open_fout(sp, x))
		return (1);
	if (open_fin(sp, x))
		return (1);
	return (0);
}
