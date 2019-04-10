/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AOperator.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 18:39:08 by bmoiroud          #+#    #+#             */
/*   Updated: 2019/04/10 17:56:00 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AOPERATOR_HPP
# define AOPERATOR_HPP

# include "expert_sys.hpp"

using namespace std;

class	Graph;

class	AOperator
{
	public:
		AOperator(void);
		virtual ~AOperator(void);

		virtual bool	compare(string already_passed) = 0;

	protected:
		vector<Fact*>		_facts;
		vector<AOperator*>	_op;
		Graph				*master;
};

class	And: public AOperator
{
	public:
		And(string liaison, Graph *Master);
		~And(void);

		virtual bool	compare(string already_passed);
};

class	Or: public AOperator
{
	public:
		Or(string liaison, Graph *Master);
		~Or(void);
		
		virtual bool	compare(string already_passed);
};

class	Xor: public AOperator
{
	public:
		Xor(string liaison, Graph *Master);
		~Xor(void);
		
		virtual bool	compare(string already_passed);
};

class	Egal: public AOperator
{
	public:
		Egal(string liaison, Graph *Master);
		~Egal(void);

		virtual bool	compare(string already_passed);
};

class	Not: public AOperator
{
	public:
		Not(string liaison, Graph *Master);
		~Not(void);

		virtual bool	compare(string already_passed);
};

#endif
