#include<iostream>
#include<vector>
#include<string>
#include"header.h"
using namespace std;
//This class is very similar to ZooEmployee, all comments in that class are applicable to this one 

ZooExhibit::ZooExhibit()
{
    ID=0;
    name="";
    cost=0;
    next=nullptr;
    aniList.clear();
}
ZooExhibit::~ZooExhibit()
{
    this->clearList();
    next=nullptr;
}
ZooExhibit::ZooExhibit(int nID, string nname, int ncost)
{
    ID=nID;
    name=nname;
    cost=ncost;
    next=nullptr;
    aniList.clear();
}
int& ZooExhibit::refID()
{
    return ID;
}
int& ZooExhibit::refCost()
{
    return cost;
}
string& ZooExhibit::refName()
{
    return name;
}
ZooExhibit*& ZooExhibit::refNext()
{
    return next;
}
void ZooExhibit::addAnimal(ZooAnimal* nAnimal)
{
    aniList.push_back(nAnimal);
}
bool ZooExhibit::removeAnimal(int aniID)
{
    int size=aniList.size();
    int i=0;
    while(i<size)
    {
        if(aniList[i]->refID()==aniID)
        {
            aniList.erase(aniList.begin()+i);
            return true;
        }
    }
    return false;
}
void ZooExhibit::clearList()
{
    for(int i=0;i++;i<=aniList.size())
    {
        aniList[i]->refEx()=nullptr;
    }
    aniList.clear();
}
void ZooExhibit::printExhibit()
{
    cout << "ID: " << ID << endl << "Name: " << name << endl << "Cost of operation: " << cost << endl << "Animals in exhibit: " << endl;
    printAniList();
}
void ZooExhibit::printAniList()
{
    for(int i=0;i++;i<=aniList.size())
    {
        cout << "ID: " << aniList[i]->refID() << endl;
        cout << "Name: " << aniList[i]->refName() << endl << "Species: " << aniList[i]->refSpecies() << endl << "Age: " << aniList[i]->refAge() << endl << "Cost of care: " << aniList[i]->refCost() << endl;
        if(aniList[i]->refEmp())
        {
            cout << "Cared for by: " << aniList[i]->refEmp()->refName() << endl;
        }
        else
        {
            cout << "Currently not cared for by anybody" << endl;
        }
        cout << endl;
    }
}