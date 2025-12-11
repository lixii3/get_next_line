/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmongili <lmongili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 18:34:32 by lmongili          #+#    #+#             */
/*   Updated: 2025/12/11 18:09:13 by lmongili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	size_t	slen;
	char	*dupe;
	size_t	i;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	dupe = (char *)malloc((slen + 1) * sizeof(char));
	if (!dupe)
		return (malloc(0));
	i = 0;
	while (i < slen)
	{
		dupe[i] = s[i];
		i++;
	}
	dupe[i] = 0;
	return (dupe);
}
