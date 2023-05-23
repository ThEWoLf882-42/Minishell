/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_fout.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 22:42:49 by agimi             #+#    #+#             */
/*   Updated: 2023/05/23 22:53:21 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	open_fout(t_pipe *sp)
{
	t_fout	*fout;

	fout = sp->fout;
	while (fout)
	{
		fout->fd = open(fout->file, fout->flag, fout->perm);
		if (fout->fd == -1)
			perror("");
		fout = fout->nxt;
	}
}
