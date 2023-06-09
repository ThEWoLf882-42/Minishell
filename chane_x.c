/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chane_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:47:39 by agimi             #+#    #+#             */
/*   Updated: 2023/06/09 15:15:43 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change_envarg(t_env *em, char *narg)
{
	free(em->arg);
	em->arg = ft_strdup(narg);
}

void	change_xarg(t_exp *xm, char *narg)
{
	free(xm->xarg);
	xm->xarg = copy_exp(narg);
}
