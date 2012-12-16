#pragma once
class Obj
{
public:
	int imageIndex;
	int id;
	int width;
	int heigth;

	Obj();
	~Obj(void);
	int getWidth(void);
	int getHeigth(void);
	void render(void);
	void update(void);
	void setID(int id);
};

