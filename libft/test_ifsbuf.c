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
	t_ifs ifs;
	ssize_t s;

	ifs.fd = open("CMakeLists.txt", O_RDONLY);
	ifs.buf = NULL;
	s = ft_ifsbuf(&ifs, 32);
	ft_putnbr((t_i32)s);
	ft_putchar('\n');
	((t_car *)ifs.buf->content)[ifs.buf->content_size] = 0;
	ft_putendl(ifs.buf->content);
	close(ifs.fd);
	return (EXIT_SUCCESS);
}
