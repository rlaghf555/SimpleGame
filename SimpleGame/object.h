#pragma once
class object
{
	int hp;
	float pos_x, pos_y;
	float minX, minY, maxX, maxY;
public:
	object();
	~object();
	void setLocation(float x, float y);
	void getLocation(float *x,float *y);
	void setSize(float minX, float minY, float maxX, float maxY);
	void getSize(float *minX, float *minY, float *maxX, float *maxY);
};
