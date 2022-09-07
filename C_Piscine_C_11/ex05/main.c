/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 20:46:05 by heejikim          #+#    #+#             */
/*   Updated: 2022/09/08 00:26:02 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
int		ft_atoi(char *str);
int		ft_strcmp(char *s1, char *s2);
void	ft_putnbr(int nb);
void	ft_putstr(char *str);

void	div(int a, int b)
{
	if (!b)
		ft_putstr("Stop : division by zero");
	else
		ft_putnbr(a / b);
}

void	mod(int a, int b)
{
	if (!b)
		ft_putstr("Stop : modulo by zero");
	else
		ft_putnbr(a % b);
}

int	main(int argc, char **argv)
{
	if (argc != 4)
		return (1);
	if (ft_strcmp(argv[2], "+") == 0)
		ft_putnbr(ft_atoi(argv[1]) + ft_atoi(argv[3]));
	else if (ft_strcmp(argv[2], "-") == 0)
		ft_putnbr(ft_atoi(argv[1]) - ft_atoi(argv[3]));
	else if (ft_strcmp(argv[2], "*") == 0)
		ft_putnbr(ft_atoi(argv[1]) * ft_atoi(argv[3]));
	else if (ft_strcmp(argv[2], "/") == 0)
		div(ft_atoi(argv[1]), ft_atoi(argv[3]));
	else if (ft_strcmp(argv[2], "%") == 0)
		mod(ft_atoi(argv[1]), ft_atoi(argv[3]));
	else
		ft_putnbr(0);
	ft_putchar('\n');
	return (0);
}
