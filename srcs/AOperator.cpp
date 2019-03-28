/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AOperator.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 19:17:12 by bmoiroud          #+#    #+#             */
/*   Updated: 2019/03/28 18:58:11 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AOperator.hpp"

AOperator::~AOperator(void) {}

void	AOperator::connect_fact(vector <string> str, int i)
{
	if (!this->graph.fact_exist(str[i]))
		this->graph.create_fact(str[i]);
}

void	AOperator::connect_op(vector <string> str, int i)
{
	
}

And::And(char *liaison, Fact *parent)
{

}

And::~And(void) {}

bool 	And::compare()
{
	int		i = -1;
	bool	a = false;
	bool	b = false;

	if (this->_prev_facts[0])
		a = this->_prev_facts[0].calc();
	if (this->_prev_facts[1])
		b = this->_prev_facts[1].calc();
	else
		b = this->_prev_op.compare();
	return (a && b);
}

Or::Or(char *liaison, Fact *parent)
{

}

Or::~Or(void) {}

bool	Or::compare()
{
	int		i = -1;
	bool	a = false;
	bool	b = false;

	if (this->_prev_facts[0])
		a = this->_prev_facts[0].calc();
	if (this->_prev_facts[1])
		b = this->_prev_facts[1].calc();
	else
		b = this->_prev_op.compare();
	return (a || b);
}

Xor::Xor(char *liaison, Fact *parent)
{

}

Xor::~Xor(void) {}

bool 	Xor::compare()
{
	int		i = -1;
	bool	a = false;
	bool	b = false;

	if (this->_prev_facts[0])
		a = this->_prev_facts[0].calc();
	if (this->_prev_facts[1])
		b = this->_prev_facts[1].calc();
	else
		b = this->_prev_op.compare();
	return (a ^ b);
}



Egal::Egal(char *liaison, Fact *parent)
{

}

Egal::~Egal(void) {}

bool 	Egal::compare()
{
	return (this->_prev_facts[0].calc());
}

Not::Not(char *liaison, Fact *parent)
{

}

Not::~Not(void) {}

bool 	Not::compare()
{
	return (!this->_prev_facts[0].calc());
}
