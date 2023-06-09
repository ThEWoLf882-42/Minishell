/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:50:08 by agimi             #+#    #+#             */
/*   Updated: 2023/06/09 15:16:48 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_pipe(void)
{
	t_pipe	*sm;

	sm = g_va.sp;
	while (sm)
	{
		if (!sm->lin)
			return (write(2,
					"syntax error near unexpected token `|'\n", 39), 1);
		sm = sm->nxt;
	}
	return (0);
}
