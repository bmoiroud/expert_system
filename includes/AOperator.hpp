/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AOperator.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 18:39:08 by bmoiroud          #+#    #+#             */
/*   Updated: 2019/03/27 16:56:54 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AOPERATOR_HPP
# define AOPERATOR_HPP

# define	EGAL 0
# define	NOT 1
# define	AND 2 
# define	OR 3
# define	XOR 4

# include	"Graph.hpp"
# include	"Fact.hpp"

class	AOperator
{
	public:
		AOperator(void);
		AOperator(int type, Fact *prev_f, Fact *next_f, AOperator *prev_op, AOperator *next_op);
		AOperator(const AOperator & src);
		~AOperator(void);

		virtual bool	compare() = 0;
		void			connect_fact(vector <string> str, int i, Graph *graph);
	
	private:
		int					_type;
		vector <Fact*>		_facts;
		vector <AOperator>	_op;
};

class	And: public AOperator
{
	public:
		And(void);
		And(int type, Fact *prev_f, Fact *next_f, AOperator *prev_op, AOperator *next_op);
		And(const And & src);
		~And(void);

		virtual bool	compare();
};

class	Or: public AOperator
{
	public:
		Or(void);
		Or(int type, Fact *prev_f, Fact *next_f, AOperator *prev_op, AOperator *next_op);
		Or(const Or & src);
		~Or(void);
		
		virtual bool	compare();
};

class	Xor: public AOperator
{
	public:
		Xor(void);
		Xor(int type, Fact *prev_f, Fact *next_f, AOperator *prev_op, AOperator *next_op);
		Xor(const Xor & src);
		~Xor(void);
		
		virtual bool	compare();
};

class	Egal: public AOperator
{
	public:
		Egal(void);
		Egal(int type, Fact *prev_f, Fact *next_f, AOperator *prev_op, AOperator *next_op);
		Egal(const Egal & src);
		~Egal(void);

		virtual bool	compare();
};

class	Not: public AOperator
{
	public:
		Not(void);
		Not(int type, Fact *prev_f, Fact *next_f, AOperator *prev_op, AOperator *next_op);
		Not(const Not & src);
		~Not(void);

		virtual bool	compare();
};

#endif
