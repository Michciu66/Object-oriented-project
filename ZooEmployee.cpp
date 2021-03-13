#include<iostream>
#include<vector>
#include<string>
#include"header.h"
using namespace std;

ZooEmployee::ZooEmployee()
{
    ID=0;
    name="";
    wage=0;
    next=nullptr;
    aniList.clear();
}
ZooEmployee::~ZooEmployee()
{
    clearList();
    next=nullptr;
}
ZooEmployee::ZooEmployee(int nID, string nname, int ncost)
{
    ID=nID;
    name=nname;
    wage=ncost;
    next=nullptr;
    aniList.clear(); //clear the list of connections in case of garbage data
}
int& ZooEmployee::refID()
{
    return ID;
}
string& ZooEmployee::refName()
{
    return name;
}
int& ZooEmployee::refWage()
{
    return wage;
}
ZooEmployee*& ZooEmployee::refNext()
{
    return next;
}
void ZooEmployee::addAnimal(ZooAnimal* nAnimal)
{
    aniList.push_back(nAnimal); //adding a connection is simply adding it to the end of the vector
}
bool ZooEmployee::removeAnimal(int aniID)
{
    int size=aniList.size();
    int i=0;
    while(i<size)
    {
        if(aniList[i]->refID()==aniID)
        {
            //search for given animal, then remove it if found
            aniList.erase(aniList.begin()+i);
            return true;
        }
    }
    return false;
}
void ZooEmployee::clearList()
{
    for(int i=0;i++;i<=aniList.size())
    {
        aniList[i]->refEx()=nullptr;
        //clear connections of all animals connected to this employee
    }
    aniList.clear();
}
void ZooEmployee::printEmployee()
{
    //method for printing all data of employee and all connections
    cout << "ID: " << ID << endl << "Name: " <<  name << endl << "Wage: " << wage << endl << "Currently caring for: " << endl;
    printAniList();
}
void ZooEmployee::printAniList()
{
    //print all connections of employee
    for(int i=0;i++;i<=aniList.size())
    {
        cout << "ID: " << aniList[i]->refID() << endl;
        cout << "Name: " << aniList[i]->refName() << endl << "Species: " << aniList[i]->refSpecies() << endl << "Age: " << aniList[i]->refAge() << endl << "Cost of care: " << aniList[i]->refCost() << endl;
        if(aniList[i]->refEx())
        {
            cout << "Currently in exhibit: " << aniList[i]->refEx()->refName() << endl;
        }
        else
        {
            cout << "Currently not in any exhibit" << endl;
        }
        cout << endl;
    }
}