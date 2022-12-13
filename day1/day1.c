/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:01:14 by jnuncio-          #+#    #+#             */
/*   Updated: 2022/12/09 22:03:45 by jnuncio-         ###   ########.fr       */
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
		fgets(buff, 20, stream);
		if (buff[0] == '\n')
			continue ;
		cnt++;
		if (feof(stream))
			break ;
	}
	return (cnt);
}

int	*sortn(int *n, int cnt)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = -1;
	while (++j <= cnt)
	{
		if (n[i] < n[i + 1] && i < cnt - 1)
		{
			temp = n[i];
			n[i] = n[i + 1];
			n[i + 1] = temp;
		}
	}
	return (n);
}

int	main(void)
{
	FILE	*input;
	char	s[100];
	int		*n;
	int		sum;
	int		i;
	int		j;
	int		cnt;

	sum = 0;
	j = -1;
	input = fopen("test.txt", "r");
	if (input == NULL)
		return (0);
	cnt = numcount(input);
	printf("cnt = %d\n", cnt);
	n = malloc(cnt * sizeof(int));
	if (!n)
		return (0);
	while (1)
	{
		fgets(s, 100, input);
		if (s == NULL)
			return (0);
		i = -1;
		while (s[++i])
		{
			if (i != 0 && s[i] == '\n')
				s[i] = '\0';
		}
		printf("s = \"%s\"\n", s);
		if (s[0] == '\n')
		{
			n[j] = sum;
			j++;
			sum = 0;
			continue ;
		}
		sum += atoi(s);
		printf("sum = %d\n", sum);
		if (feof(input))
			break ;
	}
	// sortn(n, cnt);
	// i = -1;
	// while (++i < cnt)
	// 	printf("sortn = %d\n", n[i]);
	// printf("\nmax calories = %d\n", n[0]);
	fclose(input);
	free(n);
}
