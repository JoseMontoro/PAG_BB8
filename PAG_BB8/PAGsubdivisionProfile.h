/*
* To change this license header, choose License Headers in Project Properties.
* To change this template file, choose Tools | Templates
* and open the template in the editor.
*/

/*
* File:   newClass.h
* Author: josem
*
* Created on 3 de febrero de 2017, 22:01
*/


#ifndef PAGSUBDIVISIONPROFILE_H
#define PAGSUBDIVISIONPROFILE_H

#include "glm.hpp"

class PAGsubdivisionProfile
{
private:

	glm::vec2* points;
	unsigned int sizePoints;
	bool top;
	bool bot;

public:

	PAGsubdivisionProfile();
	PAGsubdivisionProfile(glm::vec2* points, unsigned int sizePoints);
	PAGsubdivisionProfile(const PAGsubdivisionProfile& origin);
	~PAGsubdivisionProfile();

	void subdivision(unsigned int n);

	glm::vec2* getPoints() { return points; };
	unsigned int getSizePoints() { return sizePoints; };
	bool getTop() { return top; };
	bool getBot() { return bot; };

private:

	void subdivision();
};

#endif // !PAGSUBDIVISIONPROFILE_H

