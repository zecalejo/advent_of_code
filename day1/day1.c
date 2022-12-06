/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:01:14 by jnuncio-          #+#    #+#             */
/*   Updated: 2022/12/06 20:05:21 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	numcount(FILE *stream)
{
	char	buff[100];
	int		cnt;

	cnt = 0;
	while (1)
	{
		fgets(s, 20, input);
		cnt++;
		if (feof(stream))
			break ;
	}
	return (cnt);
}

sor

int	main(void)
{
	FILE	*input;
	char	s[100];
	int		*n;
	int		sum;
	int		i;
	int		j;

	sum = 0;
	i = -1;
	j = -1;
	input = fopen("input.txt", "r");
	if (input == NULL)
		return (0);
	n = malloc(numcount(input) * sizeof(int));
	if (!n)
		return (0);
	while (1)
	{
		fgets(s, 20, input);
		if (s == NULL)
			return (0);
		while (s[++i])
		{
			if (i != 0 && s[i] == '\n')
				s[i] = '\0';
		}
		if (s[0] == '\n')
		{
			n[j] = sum;
			j++;
			sum = 0;
			continue ;
		}
		sum += atoi(s);
		if (feof(input))
			break ;
	}

}
