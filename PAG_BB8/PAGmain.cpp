/*
* To change this license header, choose License Headers in Project Properties.
* To change this template file, choose Tools | Templates
* and open the template in the editor.
*/

/*
* File:   main.cpp
* Author: josem
*
* Created on 3 de febrero de 2017, 21:59
*/

#include <iostream>

#include "glew.h"
#include "glm.hpp"

#include "PAGsubdivisionProfile.h"

/*
*
*/
int main(int argc, char** argv)
{
	glm::vec2 perfil[] =
	{
		glm::vec2(0,0),
		glm::vec2(1,1),
		glm::vec2(1,2),
		glm::vec2(0,3)
	};

	PAGsubdivisionProfile profile(perfil, 4);

	profile.subdivision(1);

	for (unsigned int i = 0; i < profile.getSizePoints(); i++)
	{
		std::cout << "Punto " << i << ": " << profile.getPoints()[i].x << " " << profile.getPoints()[i].y << std::endl;
	}

	bool fin;
	std::cin >> fin;
	return 0;
};