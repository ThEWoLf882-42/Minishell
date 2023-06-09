/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_bf_af.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:05:09 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/06/09 15:17:37 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_bef(t_exp_utl *exp, t_line *lm, int start)
{
	if (char_bf(start))
		ft_backline(&exp->newlm, \
			new_lin(ft_substr(lm->shx, 0, start), exp->typ, 0));
}

void	check_af(t_exp_utl *exp, t_line *lm, size_t s, int end)
{
	if (char_af(lm->shx, end))
		ft_backline(&exp->newlm, \
			new_lin(ft_substr(lm->shx, end, s), exp->typ, 0));
}
