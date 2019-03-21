/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 17:41:20 by bmoiroud          #+#    #+#             */
/*   Updated: 2019/03/21 16:00:52 by bmoiroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert_sys.hpp"

void	parse(string file)
{
	
}

int		main(int argc, char const *argv[])
{
	Graph	graph;
	
	if (argc < 2)
		cout << "usage" << endl;
	else if (argc >= 3)
		cout << "trop d'arg" << endl;
	else
		parse(argv[1]);
	
	return (0);
}