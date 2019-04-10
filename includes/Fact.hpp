/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fact.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 18:17:06 by bmoiroud          #+#    #+#             */
/*   Updated: 2019/04/10 18:34:57 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FACT_HPP
# define FACT_HPP

# include "expert_sys.hpp"

using namespace std;

class	Graph;
class	AOperator;

class	Fact
{
	public:
		Fact(Graph *Master, const string name, const bool state);
		~Fact(void);

		// TODO
		bool		calc(string already_passed);
		bool		get_state(void);
		void		create_operator(string condition, string conclusion);
		bool		change_state();

		string		name;
		bool		value;
		
	protected:
		vector<AOperator*>	_cond;	//condition
		vector<bool>		_concl;	//conclusion
		Graph				*master;
};

#endif
