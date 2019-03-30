#include <iostream>
#include <vector>
#include <string.h>

void	recurse(std::string input, std::vector<std::string> &data, std::string base = "")
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
		recurse(tmp, data, base);
	}
}

void	recu(std::string input, std::vector<std::string> &data)
{
	while (input.size())
	{
		data.push_back(input.substr(0 ,1));
		//std::cout << input[0] << std::endl;
		recurse(input, data);
		input.erase(0,1);
	}

}

int main()
{
	std::string test = "ABCD";
	std::vector<std::string>	data;
	recu(test, data);

	for (int a = 0; a < data.size(); ++a)
	{
		std::cout << data[a] << std::endl;
	}
	return 0;
}
