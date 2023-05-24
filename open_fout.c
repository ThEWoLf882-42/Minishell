/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_fout.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 22:42:49 by agimi             #+#    #+#             */
/*   Updated: 2023/05/24 15:07:03 by zouaraqa         ###   ########.fr       */
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
			print_error(fout->file);
		dup2(fout->fd, 1);
		fout = fout->nxt;
	}
}
