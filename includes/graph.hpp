/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graph.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:41:43 by bmoiroud          #+#    #+#             */
/*   Updated: 2019/03/27 16:51:58 by bmoiroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_HPP
# define GRAPH_HPP

# include "node.hpp"

class		Graph
{
	public:
		Graph(void);
		Graph(const Graph &src);
		Graph(const Fact *facts);
		~Graph(void);

		void			create_fact(string name);
		void			create_rule(vector <string> str);
		bool			fact_exist(string name);
		bool			calc_fact(string name);
		int				get_fact_id(string name)

		int				n_facts;
		vector <Fact*>	facts;
};

#endif