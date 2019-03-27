/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fact.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 17:08:36 by bmoiroud          #+#    #+#             */
/*   Updated: 2019/03/27 15:10:10 by bmoiroud         ###   ########.fr       */
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

	while ()
	{
		n = this._prev.size();
		if (str[i] == "|")
			this._prev.push_back(new Or());
		else if (str[i] == "+")
			this._prev.push_back(new And());
		else if (str[i] == "^")
			this._prev.push_back(new Xor());
		else
			this._prev.push_back(new Egal());
		if (is_fact(str[i + 1]))
			this._prev.connect_fact(str, i + 1, graph);
		else
			this._prev.connect_op(str, i + 1, graph);
	}
}