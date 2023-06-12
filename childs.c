/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:10:25 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/06/12 16:12:09 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	childs(t_pipe *sp, int i)
{
	char	**cmd;
	t_line	*lm;

	if (g_va.y)
		exit(1);
	which_pipe(i);
	open_file(sp, 1);
	lm = sp->lin;
	while (sp->lin && ft_strcmp(sp->lin->typ, "cmd"))
		sp->lin = sp->lin->nxt;
	builtins(lm, 1);
	if (!sp->lin || !sp->lin->shx)
		exit(0);
	if_nopath(sp->lin);
	if (!sp->lin->path || !*sp->lin->shx)
		exit_print(sp->lin->shx);
	cmd = join_arg(lm);
	if (execve(sp->lin->path, cmd, g_va.envp))
		print_error(sp->lin->shx, 127, 1);
	exit (0);
}
