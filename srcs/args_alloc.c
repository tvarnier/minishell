/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   args_alloc.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/02 05:43:05 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/02 05:47:59 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int		alloc_arg_env(t_shell *s, char *arg, char *line, int *a)
{
	int		len;
	char	*tmp;
	char	*env;

	line++;
	len = 0;
	while (ft_ispath(line[len]))
		len++;
	if (!len)
	{
		*a = ft_strins(arg, "$", *a);
		return (1);
	}
	tmp = ft_strsub(line, 0, len);
	if ((env = ft_strdup(get_env(s->env, tmp))))
	{
		*a = ft_strins(arg, env, *a);
		ft_strdel(&env);
	}
	ft_strdel(&tmp);
	return (len);
}

char	*alloc_arg(t_shell *s, char *line, int len, int y)
{
	char	*arg;
	char	quote;
	int		i;
	int		a;
	int		tmp;

	arg = NULL;
	if (!(arg = ft_strnew(len)))
		return (NULL);
	i = -1;
	a = 0;
	quote = 0;
	while (++i < y)
	{
		tmp = quote;
		quote = check_quote(line, i, quote);
		if (a == 0 && line[i] == '~' && quote == 0 && get_env(s->env, "HOME"))
			a = ft_strins(arg, get_env(s->env, "HOME"), a);
		else if (line[i] == '$' && quote != '\'')
			i += alloc_arg_env(s, arg, line + i, &a);
		else if (tmp == quote)
			arg[a++] = line[i];
	}
	return (arg);
}

int		arg_len_env(t_shell *s, char *line, int *i)
{
	int		len;
	char	*tmp;

	len = 0;
	(*i)++;
	while (ft_ispath(line[*i + len]))
		len++;
	if (!len)
		return (1);
	tmp = ft_strsub(line, *i, len);
	*i += len;
	len = ft_strlen(get_env(s->env, tmp));
	ft_strdel(&tmp);
	return (len);
}

int		arg_len(t_shell *s, char *line, int *len)
{
	char	quote;
	char	tmp;
	int		i;

	i = 0;
	*len = 0;
	quote = 0;
	while (line[i])
	{
		tmp = quote;
		if (quote == 0 && line[i] == ' ')
			break ;
		quote = check_quote(line, i, quote);
		if (*len == 0 && line[i] == '~' && !quote && get_env(s->env, "HOME"))
			*len += (int)ft_strlen(get_env(s->env, "HOME"));
		else if (line[i] == '$' && quote != '\'')
			*len += arg_len_env(s, line, &i);
		else
			*len += (tmp == quote);
		i++;
	}
	return (i);
}

void	alloc_args(t_shell *s, char **args, char *line)
{
	int		i;
	int		y;
	int		num;
	int		len;

	num = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] != ' ')
		{
			len = 0;
			y = arg_len(s, line + i, &len);
			args[num] = NULL;
			args[num++] = alloc_arg(s, line + i, len, y);
			i += y;
		}
		else
			i++;
	}
}
