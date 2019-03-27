/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fact.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 17:08:36 by bmoiroud          #+#    #+#             */
/*   Updated: 2019/03/27 16:59:17 by bmoiroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fact.hpp"

Fact::Fact(void) {}

Fact::Fact(const string name, const bool state)
{
	this.name = name;
	this._state = state;
}

Fact::Fact(const Fact & src)
{
	*this = src;
}

Fact::~Fact(void) {}

bool	Fact::calc(void)
{
	
}

void	Fact::create_operator(vector <string> str, int i, Graph *graph)
{
	int		n;

	while (str[i])
	{
		n = this._prev.size();
		if (str[i] == "|")
			this._prev.push_back(Or());
		else if (str[i] == "+")
			this._prev.push_back(And());
		else if (str[i] == "^")
			this._prev.push_back(Xor());
		else
			this._prev.push_back(Egal());
		if (is_fact(str[i - 1]))
			this._prev[n].connect_fact(str, i - 1, graph);
		else
			this._prev[n].connect_op(str, i - 1, graph);
		i++;
	}
}