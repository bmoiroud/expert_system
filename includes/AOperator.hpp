/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AOperator.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 18:39:08 by bmoiroud          #+#    #+#             */
/*   Updated: 2019/03/22 14:26:29 by bmoiroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AOPERATOR_HPP
# define AOPERATOR_HPP

# define	EGAL 0
# define	AND 1 
# define	OR 2
# define	XOR 3

# include	"Fact.hpp"

class	AOperator
{
	public:
		AOperator(void);
		AOperator(int type, Fact *prev_f, Fact *next_f, AOperator *prev_op, AOperator *next_op);
		AOperator(const AOperator & src);
		~AOperator(void);

		virtual bool	compare() = 0;
	
	private:
		int				_type;
		Fact			*_prev_facts;
		Fact			*_next_facts;
		AOperator		*_prev_op;
		AOperator		*_next_op;
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

#endif