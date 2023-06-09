/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 20:06:33 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/06/09 15:19:13 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_fin(t_pipe *sp)
{
	t_fin	*fin;
	t_fin	*tfin;

	while (sp)
	{
		fin = sp->fin;
		while (fin)
		{
			tfin = fin->nxt;
			free(fin);
			fin = tfin;
		}
		sp = sp->nxt;
	}
}

void	free_fout(t_pipe *sp)
{
	t_fout	*fout;
	t_fout	*tfout;

	while (sp)
	{
		fout = sp->fout;
		while (fout)
		{
			tfout = fout->nxt;
			free(fout);
			fout = tfout;
		}
		sp = sp->nxt;
	}
}

void	free_env(t_env **env)
{
	t_env	*tenv;

	while (*env)
	{
		tenv = (*env)->nxt;
		free((*env)->arg);
		free(*env);
		*env = tenv;
	}
}

void	free_exp(t_exp **exp)
{
	t_exp	*texp;

	while (*exp)
	{
		texp = (*exp)->nxt;
		free((*exp)->xarg);
		free(*exp);
		*exp = texp;
	}
}
