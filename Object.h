#pragma once
class Object
{
protected:
	int size_x;
	int size_y;
	bool hardness;

public:
	Object();
	Object(int size_x, int size_y, bool hardness);
	Object(const Object& obj);
	
};

