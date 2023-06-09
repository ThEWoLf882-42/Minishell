/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 15:56:19 by agimi             #+#    #+#             */
/*   Updated: 2023/06/09 15:19:48 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_pipe	*ft_lastpipe(t_pipe *sp)
{
	if (!sp)
		return (NULL);
	while (sp->nxt)
		sp = sp->nxt;
	return (sp);
}

t_line	*ft_lastline(t_line *lin)
{
	if (!lin)
		return (NULL);
	while (lin->nxt)
		lin = lin->nxt;
	return (lin);
}

t_env	*ft_lastenv(t_env *env)
{
	if (!env)
		return (NULL);
	while (env->nxt)
		env = env->nxt;
	return (env);
}

t_fin	*ft_lastfin(t_fin *fin)
{
	if (!fin)
		return (NULL);
	while (fin->nxt)
		fin = fin->nxt;
	return (fin);
}

t_fout	*ft_lastfout(t_fout *fout)
{
	if (!fout)
		return (NULL);
	while (fout->nxt)
		fout = fout->nxt;
	return (fout);
}
