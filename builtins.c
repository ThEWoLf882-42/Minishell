/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 18:24:34 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/05/27 15:30:16 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtins(t_line *lm, int x)
{
	while (lm && ft_strcmp(lm->typ, "cmd"))
		lm = lm->nxt;
	if (!ft_strcmp(lm->shx, "cd"))
		cd_cmd(lm, x);
	else if (!ft_strcmp(lm->shx, "pwd"))
		pwd_cmd(x);
	else if (!ft_strcmp(lm->shx, "echo"))
		echo_cmd(lm->nxt, x);
	else if (!ft_strcmp(lm->shx, "export"))
		export_cmd(lm, x);
	else if (!ft_strcmp(lm->shx, "unset"))
		unset_cmd(lm, x);
	else if (!ft_strcmp(lm->shx, "env"))
		env_cmd(lm, x);
	else if (!ft_strcmp(lm->shx, "exit"))
		exit_cmd(x);
	else
		return (0);
	return (1);
}
