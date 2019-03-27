/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graph.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:41:47 by bmoiroud          #+#    #+#             */
/*   Updated: 2019/03/26 18:24:42 by bmoiroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.hpp"

Graph::Graph(void) {}

Graph::Graph(const Graph &src)
{
	*this = src;
}

Graph::Graph(const Fact *facts)
{
	this->facts = facts;
}

Graph::~Graph(void) {}

void		Graph::create_rule(vector <string> str)
{
	int		i;

	i = 0;
	if (!this.fact_exist(str[i]))
		this.create_fact(str[i]);
	this.facts[this.get_fact_id(str[i])].create_operator(str, i + 1, &this);
}

int			Graph::get_fact_id(string name)
{
	int		i;

	i = -1;
	while (++i < this.n_facts)
		if (this.facts[i].name == name)
			return (i);
	return (-1);
}

void		Graph::create_fact(string name)
{
	this.facts.push_back(new Fact(name, false));
	this.n_facts++;
}

bool		Graph::fact_exist(string name)
{
	int		i;

	i = -1;
	while (++i < this.facts.size())
		if (this.facts[i].name == str)
			return (true);
	return (false);
}

bool		Graph::calc_fact()
{
	
}