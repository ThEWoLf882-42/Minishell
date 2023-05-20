/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 12:07:45 by agimi             #+#    #+#             */
/*   Updated: 2023/05/20 19:21:54 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
//pipe line
//line struct
typedef struct pipe
{
	char		*pl;
	struct line	*lin;
	struct pipe	*nxt;
}	t_pipe;
//Shanks
//type
//error
typedef struct line
{
	char		*shx;
	char		*typ;
	int			err;
	struct line	*nxt;
}	t_line;
//struct pipe
typedef struct vars
{
	t_pipe	*sp;
}	t_vars;

t_vars	g_va;

/*						LIBFT						*/
void	ft_backpipe(t_pipe **sp, t_pipe *new);
void	ft_backline(t_line **lin, t_line *new);
t_pipe	*ft_lastpipe(t_pipe *sp);
t_line	*ft_lastline(t_line *lin);
t_pipe	*new_sp(char *str);
t_line	*new_lin(char *str);
char	*ft_strdup(char *s1);
size_t	ft_strlen(char *str);
/*						LIBFT						*/

void	fill_lin(void);
void	fill_sp(char *line);
void	init(void);


#endif