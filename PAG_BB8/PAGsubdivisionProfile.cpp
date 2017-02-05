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

#include "PAGsubdivisionProfile.h"

PAGsubdivisionProfile::PAGsubdivisionProfile()
{
	this->sizePoints = 0;
	this->points = NULL;
}

PAGsubdivisionProfile::PAGsubdivisionProfile(glm::vec2 * points, unsigned int sizePoints)
{
	this->sizePoints = sizePoints;
	this->points = new glm::vec2[sizePoints];

	for (unsigned int i = 0; i < sizePoints; i++)
	{
		this->points[i] = points[i];
	}
}

PAGsubdivisionProfile::PAGsubdivisionProfile(const PAGsubdivisionProfile &origin)
{
	this->sizePoints = origin.sizePoints;
	this->points = new glm::vec2[sizePoints];

	for (unsigned int i = 0; i < sizePoints; i++)
	{
		this->points[i] = origin.points[i];
	}
}


PAGsubdivisionProfile::~PAGsubdivisionProfile()
{
	delete points;
}

void PAGsubdivisionProfile::subdivision(unsigned int n)
{
	if (sizePoints < 2)
	{
		//Lanzar mensaje de error
		return;
	}

	for (unsigned int i = 0; i < n; i++)
	{
		this->subdivision();
	}
}

void PAGsubdivisionProfile::subdivision()
{
	unsigned int index = 2;
	unsigned int newSize = (2 * sizePoints) - 1;
	glm::vec2* newPoints = new glm::vec2[newSize];

	newPoints[0] = points[0];
	newPoints[newSize - 1] = points[sizePoints - 1];
	newPoints[1].x = (points[0].x + points[1].x) / 2;
	newPoints[1].y = (points[0].y + points[1].y) / 2;

	//Recorremos el vector de puntos del perfil y realizamos las operaciones de division
	for (unsigned int i = 1; i < sizePoints - 1; i++)
	{
		newPoints[index + 1].x = (points[i].x + points[i + 1].x) / 2;
		newPoints[index + 1].y = (points[i].y + points[i + 1].y) / 2;
		newPoints[index].x = ((3 * points[i].x) / 4) + (points[i - 1].x / 8) + (points[i + 1].x / 8);
		newPoints[index].y = ((3 * points[i].y) / 4) + (points[i - 1].y / 8) + (points[i + 1].y / 8);
		index += 2;
	}

	//Copiamos newPoints en Points, liberamos memoria
	delete[] points;
	points = newPoints;
	sizePoints = newSize;
}
