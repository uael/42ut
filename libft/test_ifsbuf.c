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
#include <fcntl.h>
#include <libft.h>

t_i32	main(void)
{
	t_ifs	ifs;
	t_car	*buf;

	ifs.fd = open("CMakeLists.txt", O_RDONLY);
	ifs.buf = NULL;
	while (ft_ifsgetln(&ifs, &buf))
		ft_putendl(buf);
	close(ifs.fd);
	return (EXIT_SUCCESS);
}
