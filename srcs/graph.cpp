/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:41:47 by bmoiroud          #+#    #+#             */
/*   Updated: 2019/03/28 17:06:17 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.hpp"

Graph::Graph(void) {}

Graph::~Graph(void) {}

void		Graph::create_fact(string name)
{
	facts.push_back(Fact(name, false));
}

void		Graph::create_rule(vector <string> str)
{
	int		i;

	i = str.size() - 1;
	if (!fact_exist(str[i]))
		create_fact(str[i]);
	facts[get_fact_id(str[i])]->create_operator(str, i - 1);
}

bool		Graph::fact_exist(string name)
{
	int		i;

	i = -1;
	while (++i < facts.size())
		if (facts[i].name == str)
			return (true);
	return (false);
}

bool		Graph::calc_fact()
{

}

int			Graph::get_fact_id(string name)
{
	int		i;

	i = -1;
	while (++i < n_facts)
		if (facts[i].name == name)
			return (i);
	return (-1);
}

static string			get_list(string type)
{

}

static void				print_list()
{
}
