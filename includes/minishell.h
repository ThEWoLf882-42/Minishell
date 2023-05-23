/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 12:07:45 by agimi             #+#    #+#             */
/*   Updated: 2023/05/23 15:52:48 by agimi            ###   ########.fr       */
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
	int			len;
	struct line	*nxt;
	struct line	*prv;
}	t_line;
//struct pipe
typedef struct vars
{
	char	*line;
	t_pipe	*sp;
}	t_vars;

t_vars	g_va;

/***********************LIBFT***********************/
void	ft_backpipe(t_pipe **sp, t_pipe *new);
void	ft_backline(t_line **lin, t_line *new);
void	ft_lstclear(t_pipe **sp);
t_pipe	*ft_lastpipe(t_pipe *sp);
t_line	*ft_lastline(t_line *lin);
t_pipe	*new_sp(char *str);
t_line	*new_lin(char *str);
char	*ft_strdup(char *s1);
size_t	ft_strlen(char *str);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_isspace(char c);
int		ft_isred(char c);
int		ft_isquot(char c);
int		ft_isspec(char c);
int		ft_isdlr(char c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
void	ft_free(void);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char *s, int start, int len);
/***********************LIBFT***********************/

int		fill_sp(char *line);
void	fill_lin(void);
void	trim_space(char *line);
void	delete_space(void);
void	clean_lin(void);
int		check_error(void);
int		check_pipe(void);
int		check_quote(void);
int		check_red(void);
void	lin_type(void);
void	expand(void);
int		charloc(char *str, int n);
void	copy_bef(char *new, int start, char *lin);
void	copy_mid(char *new, int start, char *found);
void	copy_af(char *new, int start, int nst, char *lin);

#endif