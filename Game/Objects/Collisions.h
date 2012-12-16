#pragma once
#include "GameObject.h"
#include "Map.h"
class Collisions
{
private:
	Map* map;
	struct Vector2
	{
		float x;
		float y;
		Vector2(float x, float y)
		{
			this->x=x;
			this->y=y;
		};
		Vector2(float *x, float *y)
		{
			this->x=*x;
			this->y=*y;
		};
	};
	vector<int> GetIdForObj(GameObject* obj,int cellsize);
	void AddBucket(Vector2* vec,float width,vector<int> &buckettoaddto,int cellsize);
	void Collisions::RegisterObject(GameObject* obj,int cellsize,vector < vector < GameObject* > > &Buckets);

public:
	Collisions(void);
	virtual ~Collisions(void);
	void detectCollisions();
	void setMap(Map* map);

};

