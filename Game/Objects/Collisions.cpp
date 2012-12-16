#include "Collisions.h"
#include <vector>
#include "Player.h"
#include <math.h>


using namespace std;

Collisions::Collisions(void)
{

}

Collisions::~Collisions(void)
{

}


bool Collides( GameObject* obj/*this*/,  GameObject* obj2)  {

    if ((obj->getX() - (obj->getWidth()/2)) > (obj2->getX() + (obj2->getWidth()/2)) || (obj->getX() + (obj->getWidth()/2)) < (obj2->getX() - (obj2->getWidth()/2)) 
		|| (obj->getY() + (obj->getHeigth()/2)) < (obj2->getY() - (obj2->getHeigth()/2)) || (obj->getY() - (obj->getHeigth()/2)) > (obj2->getY() + (obj2->getHeigth()/2))) //ten if nie dziala nie wiadomo czemu
	{
        return false;
    }
    return true;
}

// czy this jest powy¿ej box
bool IsOver( GameObject* obj/*this*/, GameObject* obj2)  {
    return Collides(obj,obj2) 
            && obj->getY() - (obj->getHeigth()/2) < obj2->getY() + (obj2->getHeigth()/2) 
            && obj2->getY() + (obj2->getHeigth()/2) > obj->getY() + (obj->getHeigth()/2);
}
 
// czy this jest poni¿ej box
bool IsUnder( GameObject* obj/*this*/, GameObject* obj2)  {
    // czyli czy box jest powy¿ej this
	return Collides(obj,obj2)
		&& obj->getY() - (obj->getHeigth()/2) < obj2->getY() - (obj2->getHeigth()/2) 
		&& obj2->getY() - (obj2->getHeigth()/2) < obj->getY() + (obj->getHeigth()/2);
}
 
// czy this jest po lewej stronie box'a
bool IsOnLeftOf( GameObject* obj/*this*/, GameObject* obj2)  {
    return Collides(obj,obj2) 
            && obj->getX() - (obj->getWidth()/2) < obj2->getX() - (obj2->getWidth()/2)
            && obj2->getX() - (obj2->getWidth()/2) < obj->getX() + (obj->getWidth()/2);
}
 
// czy this jest po prawej stronie box'a
bool IsOnRightOf( GameObject* obj/*this*/, GameObject* obj2)  {
	return Collides(obj,obj2)
		&& obj2->getX() + (obj2->getWidth()/2) < obj->getX() + (obj->getWidth()/2)
		&& obj->getX() - (obj->getWidth()/2) < obj2->getX() + (obj2->getWidth()/2);
}



void Collisions::AddBucket(Vector2* vec,float width,vector<int> &buckettoaddto,int cellsize)
    {  
        int cellPosition = (int)(
                   (floor(vec->x / cellsize)) +
                   (floor(vec->y / cellsize)) *
                   width   
        );
		bool contain = false;
		for (int i = 0; i<buckettoaddto.size() ; i++)
		{
			if(buckettoaddto[i] == cellPosition) 
			{
				contain = true;
			}
		}
        if(contain!=true)
		{
			buckettoaddto.push_back(cellPosition);
		}
		
            
    }

vector<int> Collisions::GetIdForObj(GameObject* obj,int cellsize) //rozdziela obiekty po koszykach
    {
        vector<int> bucketsObjIsIn;
           
        Vector2 *min = new Vector2(
			obj->getX() - (obj->getWidth()/2),
            obj->getY() - (obj->getHeigth()/2));   
        Vector2 *max = new Vector2(
            obj->getX() + (obj->getWidth()/2),
            obj->getY() + (obj->getHeigth()/2));
		
        float width = map->getWidth() / cellsize;   
        //TopLeft
        AddBucket(min,width,bucketsObjIsIn,cellsize);
        //TopRight
        AddBucket(new Vector2(max->x, min->y), width, bucketsObjIsIn,cellsize);
        //BottomRight
        AddBucket(new Vector2(max->x, max->y), width, bucketsObjIsIn,cellsize);
        //BottomLeft
        AddBucket(new Vector2(min->x, max->y), width, bucketsObjIsIn,cellsize);

	return bucketsObjIsIn;    
    }


void Collisions::RegisterObject(GameObject* obj,int cellsize,vector < vector < GameObject* > > &Buckets) //wpisuje rozdzielone obiekty do koszykow
    {
        vector<int> cellIds = GetIdForObj(obj,cellsize); //do ktorego koszyka trafi ten obiekt?
        for (int i = 0 ; i<cellIds.size() ; i++)
		{
			Buckets[cellIds[i]].push_back(obj);
		}
    }

void Collisions::detectCollisions() //typ obj do podmienienia
{
	int cellsize = map->getHeigth()/2; //to mozna zmienic zak³ada to ¿e bêdziemy mieli parzyst¹ wysokosc mapy, typu 2000x480 , xxxx/600 etc. w pionie bedziemy miec 2 koszyki
	//w poziomie bedzie szerokoscmapy/cellsize koszykow dlatego najlepiej zeby szerokosc mapy byla wielokrotnoscia polowy wysokosci. (jeœli ten warunek nie bedzie wam odpowiadac, wystarczy wziasc o ile sie nie myle sufit z szerokoscmapy/cellsize)
		int Cols= map->getWidth() / cellsize;
		int Rows= map->getHeigth() / cellsize;
		
		vector < vector < GameObject* > > Buckets(Cols*Rows); //koszyki utworzone
		
		//tworz zbiory 
		for (int i=0 ; i<Buckets.size(); i++)
		{
			Buckets[i].push_back(new GameObject());
			Buckets[i][0]->setID(0); 
		}

		for (int i = 0 ; i<map->objects.size(); i++)
		{
		RegisterObject(map->objects[i],cellsize,Buckets);
		}
		
		//funkcja bedzie wywolywana co update(), wiec koszyki i obiekty w koszykach beda sie przemieszczac po kazdym updacie().

		//sprawdzanie kolizji AABB
		for (int i = 0 ; i<Buckets.size() ; i++)
		{
			
			if (Buckets[i].size()>=3)
			{
				for (int j = 1 ; j<Buckets[i].size()-1 ; j++)
				{
					for (int k = j+1 ; k<Buckets[i].size() ; k++)
					{
						//sprawdzanie poszczegolnych par w danym regionie
						if (Collides(Buckets[i][j],Buckets[i][k])==true)
						{	
							cout<<"\nZaszla kolizja: ";
							if (IsOver(Buckets[i][j],Buckets[i][k])==true)
							{
								cout<<"ObiektID: "<<Buckets[i][j]->id <<" jest powyzej ObiektID: "<<Buckets[i][k]->id<<"\n";
								if (Buckets[i][j]->getY()!=Buckets[i][j]->getoldY())
								{
									Buckets[i][j]->setY(Buckets[i][j]->getY() - abs((Buckets[i][j]->getY()+(Buckets[i][j]->getHeigth()/2)) - (Buckets[i][k]->getY()-(Buckets[i][k]->getHeigth()/2))));
								}
								else if (Buckets[i][k]->getY()!=Buckets[i][k]->getoldY())
								{
									Buckets[i][k]->setY(Buckets[i][k]->getY() + abs((Buckets[i][j]->getY()+(Buckets[i][j]->getHeigth()/2)) - (Buckets[i][k]->getY()-(Buckets[i][k]->getHeigth()/2))));
								}
								//Buckets[i][j]->script.parseCollision();  //okomentowane bo nie mam probnej klasy script xd
								//Buckets[i][k]->script.parseCollision();  //wywolujemy parse script dla obu obiektow , jak ktorys jest solid czy cos to i tak sie nic nie wykona.

							}
							if (IsUnder(Buckets[i][j],Buckets[i][k]))
							{
								cout<<"ObiektID: "<<Buckets[i][j]->id <<" jest ponizej ObiektID: "<<Buckets[i][k]->id<<"\n";	
								if (Buckets[i][j]->getY()!=Buckets[i][j]->getoldY())
								{
									Buckets[i][j]->setY(Buckets[i][j]->getY() + abs((Buckets[i][j]->getY()-(Buckets[i][j]->getHeigth()/2)) - (Buckets[i][k]->getY()+(Buckets[i][k]->getHeigth()/2))));
								}
								else if (Buckets[i][k]->getY()!=Buckets[i][k]->getoldY())
								{
									Buckets[i][k]->setY(Buckets[i][k]->getY() - abs((Buckets[i][j]->getY()-(Buckets[i][j]->getHeigth()/2)) - (Buckets[i][k]->getY()+(Buckets[i][k]->getHeigth()/2))));
								}
								//Buckets[i][j]->script.parseCollision();  //okomentowane bo nie mam probnej klasy script xd
								//Buckets[i][k]->script.parseCollision(); 


							}
							if (IsOnLeftOf(Buckets[i][j],Buckets[i][k]))
							{
								cout<<"ObiektID: "<<Buckets[i][j]->id <<" jest na lewo od ObiektID: "<<Buckets[i][k]->id<<"\n";	
								if (Buckets[i][j]->getX()!=Buckets[i][j]->getoldX())
								{
									Buckets[i][j]->setX(Buckets[i][j]->getX() - abs((Buckets[i][j]->getX()+(Buckets[i][j]->getWidth()/2)) - (Buckets[i][k]->getX()-(Buckets[i][k]->getWidth()/2))));
								}
								else if (Buckets[i][k]->getX()!=Buckets[i][k]->getoldX())
								{
									Buckets[i][k]->setX(Buckets[i][k]->getX() + abs((Buckets[i][j]->getX()+(Buckets[i][j]->getWidth()/2)) - (Buckets[i][k]->getX()-(Buckets[i][k]->getWidth()/2))));
								}
								//Buckets[i][j]->script.parseCollision();  //okomentowane bo nie mam probnej klasy script xd
								//Buckets[i][k]->script.parseCollision(); 


							}

							if (IsOnRightOf(Buckets[i][j],Buckets[i][k]))
							{
								cout<<"ObiektID: "<<Buckets[i][j]->id <<" jest na prawo od ObiektID: "<<Buckets[i][k]->id<<"\n";	
								if (Buckets[i][j]->getX()!=Buckets[i][j]->getoldX())
								{
									Buckets[i][j]->setX(Buckets[i][j]->getX() + abs((Buckets[i][j]->getX()+(Buckets[i][j]->getWidth()/2)) - (Buckets[i][k]->getX()-(Buckets[i][k]->getWidth()/2))));
								}
								else if (Buckets[i][k]->getX()!=Buckets[i][k]->getoldX())
								{
									Buckets[i][k]->setX(Buckets[i][k]->getX() - abs((Buckets[i][j]->getX()+(Buckets[i][j]->getWidth()/2)) - (Buckets[i][k]->getX()-(Buckets[i][k]->getWidth()/2))));
								}
								//Buckets[i][j]->script.parseCollision();  //okomentowane bo nie mam probnej klasy script xd
								//Buckets[i][k]->script.parseCollision(); 
							}
						}
						else
						{
							cout <<"\nNie zaszla kolizja\n";
						}
					}
				}
			}
		}
		


}


void Collisions::setMap(Map* map)
{
	this->map=map;	
}

// dodac fix collision i parseCollision.