/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:14:50 by agimi             #+#    #+#             */
/*   Updated: 2023/05/30 17:51:19 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redirect_error(char *str, int x)
{
	dup2(1, 2);
	printf("minishell-69: %s: ambiguous redirect\n", str);
	if (x)
		exit(1);
	dup2(2, 1);
}

int	open_fin(t_pipe *sp, int x)
{
	t_fin	*fin;

	fin = sp->fin;
	while (fin)
	{
		if (fin->lm->nxt->space)
			redirect_error(fin->lm->nxt->bex, x);
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
		if (fout->lm->nxt->space)
			redirect_error(fout->lm->nxt->bex, x);
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
	if (open_fout(sp, x))
		return (1);
	if (open_fin(sp, x))
		return (1);
	return (0);
}
