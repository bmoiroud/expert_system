/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graph.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:41:43 by bmoiroud          #+#    #+#             */
/*   Updated: 2019/04/16 19:09:27 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_HPP
# define GRAPH_HPP

# include "expert_sys.hpp"

using namespace std;

class		Fact;

class		Graph
{
	public:
		Graph(vector<string> data);
		~Graph(void);

		void					create_fact(char name, bool value = false);
		bool					fact_exist(string name);
		int						get_fact_id(char name);
		void					resolve();

		vector<Fact>			facts;
		bool					nonsense;
		string					to_find;
};

#endif
