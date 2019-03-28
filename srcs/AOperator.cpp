/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AOperator.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 19:17:12 by bmoiroud          #+#    #+#             */
/*   Updated: 2019/03/28 15:19:37 by bmoiroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AOperator.hpp"

AOperator::AOperator(void)
{
	this.type = 0;
	this->_facts = NULL;
	this->_op = NULL;
}

AOperator::AOperator(int type, Fact *facts, AOperator *op)
{
	this.type = type;
	this->_facts = next_f;
	this->_op = next_op;
}

AOperator::AOperator(const AOperator & src)
{
	*this = src;
}

AOperator::~AOperator(void) {}

void	AOperator::connect_fact(vector <string> str, int i)
{
	if (!this->graph.fact_exist(str[i]))
		this->graph.create_fact(str[i]);
}

void	AOperator::connect_op(vector <string> str, int i)
{
	
}



And::And(void): AOperator(AND, NULL, NULL, NULL, NULL) {}

And::And(void): AOperator(int type, Fact *facts, AOperator *op) {}

And::And(const And & src)
{
	*this = src;
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



Or::Or(void): AOperator(OR, NULL, NULL, NULL, NULL) {}

Or::Or(void): AOperator(int type, Fact *facts, AOperator *op) {}

Or::Or(const Or & src)
{
	*this = src
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



Xor::Xor(void): AOperator(XOR, NULL, NULL, NULL, NULL) {}

Xor::Xor(void): AOperator(int type, Fact *facts, AOperator *op) {}

Xor::Xor(const Xor & src)
{
	*this = src
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



Egal::Egal(void): AOperator(EGAL, NULL, NULL, NULL, NULL) {}

Egal::Egal(void): AOperator(int type, Fact *facts, AOperator *op) {}

Egal::Egal(const Egal & src)
{
	*this = src
}

Egal::~Egal(void) {}

bool 	Egal::compare()
{
	return (this->_prev_facts[0].calc());
}



Not::Not(void): AOperator(NOT, NULL, NULL, NULL, NULL) {}

Not::Not(void): AOperator(int type, Fact *facts, AOperator *op) {}

Not::Not(const Not & src)
{
	*this = src
}

Not::~Not(void) {}

bool 	Not::compare()
{
	return (!this->_prev_facts[0].calc());
}
