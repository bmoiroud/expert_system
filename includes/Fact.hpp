/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fact.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 18:17:06 by bmoiroud          #+#    #+#             */
/*   Updated: 2019/04/16 18:53:01 by bmoiroud         ###   ########.fr       */
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

		bool		calc(string already_passed);
		void		create_operator(string condition, string conclusion);

		string		name;
		bool		value;
		bool		sure;
		
	protected:
		vector<AOperator*>	_cond;	//condition
		vector<bool>		_concl;	//conclusion
		Graph				*master;
};

#endif
