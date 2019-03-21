/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:41:43 by bmoiroud          #+#    #+#             */
/*   Updated: 2019/03/21 16:06:39 by bmoiroud         ###   ########.fr       */
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
		~Graph(void);

		

	private:
		Fact	*_facts;
};

#endif