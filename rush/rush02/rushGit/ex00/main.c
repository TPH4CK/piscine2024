/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 14:10:07 by pamallet          #+#    #+#             */
/*   Updated: 2024/09/28 14:32:37 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//int	ft_rush02(void);

int	ft_errors_handling(int argc, char **argv);

int	main(int argc, char **argv)
{
	if (!ft_errors_handling(argc, argv))
		return (0);
	//ft_rush02();
	return (0);
}
