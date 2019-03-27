/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AOperator.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 19:17:12 by bmoiroud          #+#    #+#             */
/*   Updated: 2019/03/27 18:57:25 by bmoiroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AOperator.hpp"

AOperator::AOperator(void)
{
	this.type = 0;
	this->_next_facts = NULL;
	this->_prev_facts = NULL;
	this->_next_op = NULL;
	this->_prev_op = NULL;
}

AOperator::AOperator(int type, Fact *prev_f, Fact *next_f, AOperator *prev_op, AOperator *next_op)
{
	this.type = type;
	this->_next_facts = next_f;
	this->_prev_facts = prev_f;
	this->_next_op = next_op;
	this->_prev_op = prev_op;
}

AOperator::AOperator(const AOperator & src)
{
	*this = src;
}

AOperator::~AOperator(void) {}

void	AOperator::connect_fact(vector <string> str, int i)
{
}

void	AOperator::connect_op(vector <string> str, int i)

And::And(void): AOperator(AND, NULL, NULL, NULL, NULL) {}

And::And(void): AOperator(int type, Fact *prev_f, Fact *next_f, AOperator *prev_op, AOperator *next_op) {}

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

Or::Or(void): AOperator(int type, Fact *prev_f, Fact *next_f, AOperator *prev_op, AOperator *next_op) {}

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

Xor::Xor(void): AOperator(int type, Fact *prev_f, Fact *next_f, AOperator *prev_op, AOperator *next_op) {}

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

Egal::Egal(void): AOperator(int type, Fact *prev_f, Fact *next_f, AOperator *prev_op, AOperator *next_op) {}

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

Not::Not(void): AOperator(int type, Fact *prev_f, Fact *next_f, AOperator *prev_op, AOperator *next_op) {}

Not::Not(const Not & src)
{
	*this = src
}

Not::~Not(void) {}

bool 	Not::compare()
{
	return (!this->_prev_facts[0].calc());
}
