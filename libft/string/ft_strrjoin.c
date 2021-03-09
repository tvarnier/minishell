/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrjoin.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/13 03:28:11 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/13 04:31:55 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrjoin(char const *s1, char const *s2, char sep)
{
	char	*str;
	int		i;
	int		y;

	if (!(str = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	str[i] = sep;
	y = -1;
	while (s2[++y])
		str[++i] = s2[y];
	return (str);
}
