#include<iostream>
#include<vector>
#include<string>
#include"header.h"
using namespace std;

ZooAnimal::ZooAnimal()
{
    ID=0;
    name="";
    species="";
    age=0;
    cost=0;
    careEmployee=nullptr;
    currExhibit=nullptr;
    next=nullptr;
}
ZooAnimal::ZooAnimal(int nID, string nname, string nspecies, int nage, int ncost)
{
    ID=nID;
    name=nname;
    species=nspecies;
    age=nage;
    cost=ncost;
    careEmployee=nullptr;
    currExhibit=nullptr;
    next=nullptr;
    //by default the animal is cared for by noone and is in no exhibit - it needs to be assigned first
}
ZooAnimal::~ZooAnimal()
{
    if(careEmployee)
    {
    careEmployee->removeAnimal(ID);        
    }
    if(currExhibit)
    {
    currExhibit->removeAnimal(ID);        
    }
    careEmployee=nullptr;
    currExhibit=nullptr;
    next=nullptr;
}
int& ZooAnimal::refID()
{
    return ID;
}
string& ZooAnimal::refName()
{
    return name;
}
string& ZooAnimal::refSpecies()
{
    return species;
}
int& ZooAnimal::refAge()
{
    return age;
}
int& ZooAnimal::refCost()
{
    return cost;
}
ZooEmployee*& ZooAnimal::refEmp()
{
    return careEmployee;
}
ZooExhibit*& ZooAnimal::refEx()
{
    return currExhibit;
}
ZooAnimal*& ZooAnimal::refNext()
{
    return next;
}
void ZooAnimal::printAnimal()
{
    //method for printing the whole element including its connections
    cout << "ID: " << ID << endl;
    cout << "Name: " << name << endl << "Species: " << species << endl << "Age: " << age << endl << "Cost of care: " << cost << endl;
    if(careEmployee)
    {
        cout << "Currently cared for by: " << careEmployee->refName() << endl;
    }
    else
    {
        cout << "Currently not cared for by anybody" << endl;
    }
    if(currExhibit)
    {
        cout << "Currently in exhibit: " << currExhibit->refName() << endl;
    }
    else
    {
        cout << "Currently not in any exhibit" << endl;
    }
}