#include "stdafx.h"
#include "object.h"


object::object()
{
}


object::~object()
{
	delete this;
}

void object::setLocation(float x, float y)
{
	pos_x = x;
	pos_y = y;
}

void object::getLocation(float *x, float *y)
{
	*x = pos_x;
	*y = pos_y;
}

void object::setSize(float minX, float minY, float maxX, float maxY)
{
	this->minX = minX;
	this->minY = minY;
	this->maxX = maxX;
	this->maxY = maxY;
}

void object::getSize(float * minX, float * minY, float * maxX, float * maxY)
{
	*minX = this->minX;
	*minY = this->minY;
	*maxX = this->maxX;
	*maxY = this->maxY;


}
