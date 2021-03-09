/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/20 16:13:23 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/01 09:10:45 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

char	*get_pwd(t_shell *s)
{
	char	*tmp;

	if ((tmp = get_env(s->env, "PWD")))
	{
		if (!ft_strcmp(tmp, "/"))
			return ("/");
		else if (get_env(s->env, "HOME")
				&& !ft_strcmp(tmp, get_env(s->env, "HOME")))
			return ("~");
		else
			return (tmp + 1 + ft_strchar_last(tmp, '/'));
	}
	else
		return ("?");
	return (NULL);
}

void	print_prompt(t_shell *s)
{
	ft_putstr("\033[36m\033[1m");
	ft_putstr(get_pwd(s));
	ft_putchar(' ');
	ft_putstr("\033[0m\033[1m");
	if (!s->res)
	{
		ft_putstr("\033[32m");
		ft_putstr("■");
	}
	else
	{
		ft_putstr("\033[31m");
		ft_putstr("□");
	}
	ft_putchar(' ');
	ft_putstr("\033[0m");
}

int		print_quote(char c)
{
	if (c == '"')
		ft_putstr("quote> ");
	else if (c == '\'')
		ft_putstr("dquote> ");
	return (-1);
}
