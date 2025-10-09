#include <ostream>
#include <string>
#include <iostream>
#include <fstream>

void replace_str(std::string &str, std::string &s1, std::string &s2)
{
	std::size_t pos = 0;

	while ((pos = str.find(s1, pos)) != std::string::npos)
	{
		str.erase(pos, s1.length());
		str.insert(pos, s2);
		pos += s2.length();
	}
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Provide exactly 3 arguments: filename, s1, s2.\n";
		return 1;
	}
	std::string fileName = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	if (!s1.c_str()  || !s2.c_str() || !s1[0] || !s2[0])
	{
		std::cout << "s1 and s2 can't be empty.\n";
		return 1;
	}

	std::ifstream inputFile(fileName.c_str());
	if (!inputFile)
	{
		std::cerr << "Error while opening file!\n";
		return 1;
	}
	std::ofstream outFile((fileName + ".replace").c_str());
	if (!outFile)
	{
		std::cerr << "Error while creating .replace file!\n";
		return 1;
	}
	std::string line;
	while (std::getline(inputFile, line))
	{
		replace_str(line, s1, s2);
		outFile << line << std::endl;
		line.clear();
	}
	outFile.close();
	inputFile.close();
	return 0;
}
