void	list_error_input()
{
}

void	combinaison_fact(std::string input, std::vector<std::string> &data, std::string base = "")
{
	int		i = 0;

	while (i < input.size() && base.size())
	{
		data.push_back(base + input[i]);
		//std::cout << base + input[i] << std::endl;
		++i;
	}
	base += input[0]; 
	if (1 < input.size())
	{
		std::string tmp = &(input.c_str()[1]);
		combinaison_fact(tmp, data, base);
	}
}

// envoie en parametre =ABD et doit avoira accès à la liste des règles
bool	check_case(std::string result)
{
}
