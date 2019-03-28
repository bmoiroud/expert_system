/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:41:43 by bmoiroud          #+#    #+#             */
/*   Updated: 2019/03/28 14:20:59 by bmoiroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_HPP
# define GRAPH_HPP

using namespace std;

class		Graph
{
	public:
		Graph(void);
		~Graph(void);

		void			create_fact(string name);
		void			create_rule(vector <string> str);
		bool			fact_exist(string name);
		bool			calc_fact(string name);
		int				get_fact_id(string name);

		int				n_facts;
		vector <Fact*>	facts;
};

#endif
