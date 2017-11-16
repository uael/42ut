/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_gnl1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:37:09 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/14 17:04:46 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <libft.h>
#include "src/get_next_line.h"
#include <fcntl.h>

int	main(int ac, char **av)
{
	char	*bla;
	int		fd = open(av[1], O_RDONLY);

	(void)ac;
	while (get_next_line(fd, &bla) > 0)
		ft_putendl(bla), free(bla);
	return (EXIT_SUCCESS);
}
