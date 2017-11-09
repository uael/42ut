/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_gnl1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:37:09 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/09 16:58:20 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <libft.h>
#include <get_next_line.h>

t_i32	main(void)
{
	char *bla;

	while (get_next_line(0, &bla))
		ft_putendl(bla), free(bla);
	return (EXIT_SUCCESS);
}
