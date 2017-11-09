/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:37:09 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/09 14:09:40 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <libft.h>

t_i32	main(void)
{
	static struct { char *a; char s; char *b[10]; } tests[] = {
		{ "a", '*', {"a", NULL} },
		{ "*hello**fellow", '*', {"hello", "fellow", NULL} },
		{ "coucou*toi**", '*', {"coucou", "toi", NULL} },
		{ "coucou*tu**veux", '*', {"coucou", "tu", "veux", NULL} },
		{ "lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim"
          " sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, variu"
          "s a, semper congue, euismod non, mi.", '*', { NULL } },
		{ "lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim"
          " sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, variu"
          "s a, semper congue, euismod non, mi.", 'z', { NULL } },
	};

	for (int i = 0; i < 4; ++i)
	{
		t_car **ss = ft_strsplit(tests->a, tests->s);
		t_car **sst = tests->b;
		while (*sst)
		{
			assert(ft_strequ(*sst, *ss));
			assert(ft_strequ(*ss, *sst));
			++ss;
			++sst;
		}
		assert(*sst == NULL);
		assert(*ss == NULL);
	}
}
