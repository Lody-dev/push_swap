/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viaremko <viaremko@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:41:04 by viaremko          #+#    #+#             */
/*   Updated: 2025/02/28 15:48:07 by viaremko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* BENCHMARK
	- Mininum validation:
	100 random numbers in fewer than 700 operations.

	- Maximum validation:
	500 random numbers in fewer than 5500 operations (required for bonus).
*/

/* POSSIBLE ERRORS:
	-> arguments are not integers (chars, strings...)
	-> some argument are under/above the range for integers
	-> integers are duplicates
	-> no input given (should exit and return the control to user)
*/

/* POSSIBLE ARGUMENTS:
	ARG="1 3 2"; ./push_swap $ARG 	<- OK
	./push_swap 1 3 2				<- OK
	./push_swap "1 3 2"				<- OK
	./push_swap "1 3" 2				<- OK
	./push_swap "1 3" "2 4" 9		<- OK
	./push_swap -2147483648 4 		<- OK
	./push_swap 2147483647 6		<- OK
	./push_swap -2147483649 3		<- Error
	./push_swap 2147483648 7		<- Error
	./push_swap "G 4 T 0"			<- Error
	./push_swap 					<- exit(1)
*/

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	char	**args;
	int		args_count;
	t_stack	stack_a;
	t_stack	stack_b;

	args = input_handler(argc, argv);
	args_count = 0;
	if (args)
	{
		while (args[args_count])
		{
			if (!is_valid_argument(args[args_count]))
				ft_error();
			args_count++;
		}
	}
	stack_init(&stack_a, &stack_b, args_count + 1);
	stack_fill(&stack_a, args);
	if (stack_check_duplicates(&stack_a) == -1)
		ft_error();
	stack_sort(&stack_a, &stack_b);
	stack_free(&stack_a, &stack_b);
	return (0);
}
