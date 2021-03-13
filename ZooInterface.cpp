#include<iostream>
#include<vector>
#include<string>
#include"header.h"
using namespace std;

ZooInterface::ZooInterface()
{
    location="";
    name="";
    empHead=nullptr;
    exHead=nullptr;
    aniHead=nullptr;
}
ZooInterface::~ZooInterface()
{
    ZooExhibit* exCurr=exHead;
    //Clear all lists
    while (exCurr)
    {
        ZooExhibit* prev=exCurr;
        exCurr=exCurr->refNext();
        delete prev;
    }
    ZooEmployee* empCurr=empHead;
    while (empCurr)
    {
        ZooEmployee* prev=empCurr;
        empCurr=empCurr->refNext();
        delete prev;
    }
    ZooAnimal* aniCurr=aniHead;
    while (aniCurr)
    {
        ZooAnimal* prev=aniCurr;
        aniCurr=aniCurr->refNext();
        delete prev;
    }
    exHead=nullptr;
    empHead=nullptr;
    aniHead=nullptr;
}
ZooInterface::ZooInterface(string nlocation, string nname)
{
    location=nlocation;
    name=nname;
    empHead=nullptr;
    exHead=nullptr;
    aniHead=nullptr;
}
bool ZooInterface::addEmployee(string nname, int nwage)
{
    if(nname=="" || nwage<=0)
    {
        cout << "Error in adding employee, wrong data" << endl;
        return false;
    }
    if(!empHead)
    {
        //adding a new element as a head
        empHead= new ZooEmployee(1,nname,nwage);
        return true;
    }
    ZooEmployee * curr=empHead;
    while(curr->refNext())
    {
        //find last element in list
        curr=curr->refNext();
    }
    //create a new last element
    curr->refNext() = new ZooEmployee(curr->refID() + 1, nname, nwage);
    return true;
}
bool ZooInterface::addAnimal(string nname, string nspecies, int nage, int ncost)
{
    if(nname=="" || nspecies=="" || nage<0 || ncost<=0)
    {
        cout << "Error in adding animal, wrong data" << endl;
        return false;
    }
    if (!aniHead)
    {
        //adding a new element as a head
        aniHead= new ZooAnimal(1,nname,nspecies,nage,ncost);
        return true;
    }
    ZooAnimal* curr=aniHead;
    while(curr->refNext())
    {
        //find last element in list
        curr=curr->refNext();
    }
    //create a new last element
    curr->refNext()=new ZooAnimal(curr->refID()+1,nname,nspecies,nage,ncost);
    return true;
}
bool ZooInterface::addExhibit(string nname, int ncost)
{
    if(nname=="" || ncost <0)
    {
        cout << "Error in adding exhibit, wrong data" << endl;
        return false;
    }
    if(!exHead)
    {
        //adding a new element as a head
        exHead= new ZooExhibit(1,nname,ncost);
        return true;
    }
    ZooExhibit* curr = exHead;
    while(curr->refNext())
    {
        //find last element in list
        curr=curr->refNext();
    }
    //create a new last element
    curr->refNext()=new ZooExhibit(curr->refID()+1,nname,ncost);
    return true;
}
bool ZooInterface::assignAni2Emp(int aniID,int empID)
{
    if(!isEmp(empID) || !isAni(aniID))
    {
        cout << "Error in assignment, at least one of given objects doesn't exist" << endl;
        return false;
    }
    ZooAnimal* currAni=aniHead;
    ZooEmployee* currEmp=empHead;
    while (currAni->refID()!=aniID)
    {
        //finding the correct animal - checking for end of list isn't necessary as it is checked in isAni() at the beggining
        currAni=currAni->refNext();
    }
    if(currAni->refEmp() && currAni->refEmp()->refID()==empID)
    {
        //if the animal is already connected to the chosen employee do nothing
        return true;
    }
    if (currAni->refEmp() && currAni->refEmp()->refID() != empID)
    {
        //if the animal is connected to a different employee remove the connection from the employee
        currAni->refEmp()->removeAnimal(currAni->refID());
    }
    while (currEmp->refID()!=empID)
    {
        //find the chosen employee
        currEmp=currEmp->refNext();
    }
    //set the connection between both elements
    currAni->refEmp()=currEmp;
    currEmp->addAnimal(currAni);
    return true;
}
bool ZooInterface::assignAni2Ex(int aniID,int exID)
{
    //function works almost the same as assigning animal to employee
    if(!isEx(exID) || !isAni(aniID))
    {
        cout << "Error in assignment, at least one of given objects doesn't exist" << endl;
        return false;
    }
    ZooAnimal* currAni=aniHead;
    ZooExhibit* currEx=exHead;
    while (currAni->refID()!=aniID)
    {
        currAni=currAni->refNext();
    }
    if(currAni->refEx() && currAni->refEx()->refID()==exID)
    {
        return true;
    }
    if (currAni->refEx() && currAni->refEx()->refID() != exID)
    {
        currAni->refEx()->removeAnimal(currAni->refID());
    }
    while (currEx->refID()!=exID)
    {
        currEx=currEx->refNext();
    }
    currAni->refEx()=currEx;
    currEx->addAnimal(currAni);
    return true;
}
bool ZooInterface::deAssignAniFromEmp(int aniID)
{
    if(!isAni(aniID))
    {
        cout << "Error in unassignment, animal doesn't exist" << endl;
        return false;
    }
    ZooAnimal* currAni=aniHead;
    while (currAni->refID()!=aniID)
    {
        //as in assignment, find the animal with given id
        currAni=currAni->refNext();
    }
    if(!currAni->refEmp())
    {
        //if the animal doesnt have a connection, dont do anything
        return true;
    }
    //delete connection from animal and from connected employee
    currAni->refEmp()->removeAnimal(aniID);
    currAni->refEmp()=nullptr;
    return true;
}
bool ZooInterface::deAssignAniFromEx(int aniID)
{
    //works similarly to previous method, refer to previous comments 
    if(!isAni(aniID))
    {
        cout << "Error in unassignment, animal doesn't exist" << endl;
        return false;
    }
    ZooAnimal* currAni=aniHead;
    while (currAni->refID()!=aniID)
    {
        currAni=currAni->refNext();
    }
    if(!currAni->refEx())
    {
        return true;
    }
    currAni->refEx()->removeAnimal(aniID);
    currAni->refEx()=nullptr;
    return true;
}
int ZooInterface::countAni()
{
    //simple counting function - counts number of elements in list
    int count=0;
    if(aniHead)
    {
        ZooAnimal* curr=aniHead;
        while(curr)
        {
            curr=curr->refNext();
            count++;
        }
    }
    return count;
}
int ZooInterface::countEmp()
{
    //simple counting function - counts number of elements in list
    int count=0;
    if(empHead)
    {
        ZooEmployee* curr=empHead;
        while(curr)
        {
            curr=curr->refNext();
            count++;
        }
    }
    return count;
}
int ZooInterface::countEx()
{
    //simple counting function - counts number of elements in list
    int count=0;
    if(exHead)
    {
        ZooExhibit* curr=exHead;
        while(curr)
        {
            curr=curr->refNext();
            count++;
        }
    }
    return count;
}
bool ZooInterface::isAni(int aniID)
{
    //simple function - goes through the list, returns true if object of given id exists
    if(!aniHead || aniID<=0)
    {
        return false;
    }
    ZooAnimal* curr=aniHead;
    while(curr)
    {
        if(curr->refID()==aniID)
        {
            return true;
        }
        curr=curr->refNext();
    }
    return false;
}
bool ZooInterface::isEmp(int empID)
{
    if(!empHead || empID<=0)
    {
        return false;
    }
    ZooEmployee* curr=empHead;
    while(curr)
    {
        if(curr->refID()==empID)
        {
            return true;
        }
        curr=curr->refNext();
    }
    return false;
}
bool ZooInterface::isEx(int exID)
{
    if(!exHead || exID<=0)
    {
        return false;
    }
    ZooExhibit* curr=exHead;
    while(curr)
    {
        if(curr->refID()==exID)
        {
            return true;
        }
        curr=curr->refNext();
    }
    return false;
}
int ZooInterface::sumCosts()
{
    //Sums up costs of every object is all three lists
    int sum=0;
    if(aniHead)
    {
        ZooAnimal* curr=aniHead;
        while(curr)
        {
            sum=curr->refCost()+sum;
            curr=curr->refNext();
        }
    }
    if(exHead)
    {
        ZooExhibit* curr=exHead;
        while(curr)
        {
            sum=curr->refCost()+sum;
            curr=curr->refNext();
        }
    }
    if(empHead)
    {
        ZooEmployee* curr=empHead;
        while(curr)
        {
            sum=curr->refWage()+sum;
            curr=curr->refNext();
        }
    }
    return sum;
}
bool ZooInterface::removeAni(int aniID)
{
    if(!isAni(aniID))
    {
        cout << "Error in deletion, no such animal exists" << endl;
        return false;
    }
    if(aniHead->refID()==aniID)
    {
        //deletion of first element in list
        if(aniHead->refEmp())
        {
            aniHead->refEmp()->removeAnimal(aniID);
            //remove connections from object
        }
        if(aniHead->refEx())
        {
            aniHead->refEx()->removeAnimal(aniID);
        }
        ZooAnimal* curr=aniHead->refNext();
        delete aniHead;
        aniHead=curr;
        //find new head
        while(curr)
        {
            curr->refID()=curr->refID()-1;
            curr=curr->refNext();
            //update IDs after deletion
        }
        return true;
    }
    ZooAnimal* prev=aniHead;
    ZooAnimal* curr=aniHead->refNext();
    while(curr->refID()!=aniID)
    {
        //finding element for deletion in list
        prev=curr;
        curr=curr->refNext();
    }
    if(curr->refEmp())
    {
        //remove connections from element
        curr->refEmp()->removeAnimal(aniID);
    }
    if(curr->refEx())
    {
        curr->refEx()->removeAnimal(aniID);
    }
    //repair "break" in the list
    prev->refNext()=curr->refNext();
    delete curr;
    prev=prev->refNext();
    while(prev)
    {
        //update IDs
        prev->refID()=prev->refID()-1;
        prev=prev->refNext();
    }
    return true;
}
bool ZooInterface::removeEmp(int empID)
{
    //Method very similar to previous functions, refer to comments in removeAni()
    if(!isEmp(empID))
    {
        cout << "Error in deletion, no such employee exists" << endl;
        return false;
    }
    if(empHead->refID()==empID)
    {
        empHead->clearList();
        ZooEmployee* curr=empHead->refNext();
        delete empHead;
        empHead=curr;
        while(curr)
        {
            curr->refID()=curr->refID()-1;
            curr=curr->refNext();
        }
        return true;
    }
    ZooEmployee* prev=empHead;
    ZooEmployee* curr=empHead->refNext();
    while(curr->refID()!=empID)
    {
        prev=curr;
        curr=curr->refNext();
    }
    curr->clearList();
    prev->refNext()=curr->refNext();
    delete curr;
    prev=prev->refNext();
    while(prev)
    {
        prev->refID()=prev->refID()-1;
        prev=prev->refNext();
    }
    return true;
}
bool ZooInterface::removeEx(int exID)
{
    //Method very similar to previous functions, refer to comments in removeAni()
    if(!isEx(exID))
    {
        cout << "Error in deletion, no such exhibit exists" << endl;
        return false;
    }
    if(exHead->refID()==exID)
    {
        exHead->clearList();
        ZooExhibit* curr=exHead->refNext();
        delete exHead;
        exHead=curr;
        while(curr)
        {
            curr->refID()=curr->refID()-1;
            curr=curr->refNext();
        }
        return true;
    }
    ZooExhibit* prev=exHead;
    ZooExhibit* curr=exHead->refNext();
    while(curr->refID()!=exID)
    {
        prev=curr;
        curr=curr->refNext();
    }
    curr->clearList();
    prev->refNext()=curr->refNext();
    delete curr;
    prev=prev->refNext();
    while(prev)
    {
        prev->refID()=prev->refID()-1;
        prev=prev->refNext();
    }
    return true;
}
void ZooInterface::printAniList()
{
    //prints all the animals and their connections
    if(!aniHead)
    {
        cout << "No animals in list." << endl;
        return;
    }
    ZooAnimal* curr=aniHead;
    while (curr)
    {
        curr->printAnimal();
        curr=curr->refNext();
    }
}
void ZooInterface::printEmpListFull()
{
    //prints all employees with connections
    if(!empHead)
    {
        cout << "No employees in list." << endl;
        return;
    }
    ZooEmployee* curr=empHead;
    while (curr)
    {
        curr->printEmployee();
        curr=curr->refNext();
    }
}
void ZooInterface::printEmpList()
{
    //prints list of employees without connections - used in printZoo()
    if(!empHead)
    {
        cout << "No employees in list." << endl;
        return;
    }
    ZooEmployee* curr=empHead;
    while (curr)
    {
        cout << "ID: " << curr->refID() << endl << "Name: " << curr->refName() << endl << "Wage: " << curr->refWage() << endl;
        curr=curr->refNext();
    }
}
void ZooInterface::printExListFull()
{
    //print all Exhibits with connections
    if(!exHead)
    {
        cout << "No exhibits in list." << endl;
        return;
    }
    ZooExhibit* curr=exHead;
    while (curr)
    {
        curr->printExhibit();
        curr=curr->refNext();
    }
}
void ZooInterface::printExList()
{
    //print all exhibits without connections - used in printZoo()
    if(!exHead)
    {
        cout << "No exhibits in list." << endl;
        return;
    }
    ZooExhibit* curr=exHead;
    while (curr)
    {
        cout << "ID: " << curr->refID() << endl << "Name: " << curr->refName() << endl << "Cost of Operation: " << curr->refCost() << endl;
        curr=curr->refNext();
    }
}
void ZooInterface::printAni(int aniID)
{
    //print specific element with given ID
    ZooAnimal* curr=aniHead;
    while(curr)
    {
        if(curr->refID()==aniID)
        {
            curr->printAnimal();
            return;
        }
        curr=curr->refNext();
    }
    cout << "No such animal in list" << endl;
}
void ZooInterface::printEmp(int empID)
{
    //print specific element with given ID
    ZooEmployee* curr=empHead;
    while(curr)
    {
        if(curr->refID()==empID)
        {
            curr->printEmployee();
            return;
        }
        curr=curr->refNext();
    }
    cout << "No such employee in list" << endl;
}
void ZooInterface::printEx(int exID)
{
    //print specific element with given ID
    ZooExhibit* curr=exHead;
    while(curr)
    {
        if(curr->refID()==exID)
        {
            curr->printExhibit();
            return;
        }
        curr=curr->refNext();
    }
    cout << "No such exhibit in list" << endl;
}
void ZooInterface::printZoo()
{
    //Prints out zoo data, all animals with connections and then the other two lists without their connections 
    cout << "Name: " << name << endl << "Location: " << location << endl << endl << "List of Animals:" << endl;
    printAniList();
    cout << endl << "List of Employees: " << endl;
    printEmpList();
    cout << endl << "List of Exhibits: " << endl;
    printExList();
}
bool ZooInterface::modAni(int aniID, int choose, string newstring)
{
    //modify specific animal data
     if(aniID<=0)
    {
        cout << "Error, wrong ID given" << endl;
        return false;
    }
    ZooAnimal* curr=aniHead;
    while(curr)
    {
        if(curr->refID()==aniID)
        {
            break;
        }
        curr=curr->refNext();
    }
    if(!curr)
    {
        cout << "Error, ID given larger than amount of animals in database" << endl;
        return false;
    }
    switch(choose)
    {
        case 1:
        {
            //choose is a variable to pick which data in the element we want to modify
            curr->refName()=newstring;
            break;
        }
        case 2:
        {
            curr->refSpecies()=newstring;
            break;
        }
        default:
        {
            cout << "Error, no such variable number exists" << endl;
            return false;
        }
    }
    return true;
}
bool ZooInterface::modAni(int aniID, int choose, int newvalue)
{
    //modify specific animal data
    if(aniID<=0)
    {
        cout << "Error, wrong ID given" << endl;
        return false;
    }
    ZooAnimal* curr=aniHead;
    while(curr)
    {
        if(curr->refID()==aniID)
        {
            break;
        }
        curr=curr->refNext();
    }
    if(!curr)
    {
        cout << "Error, ID given larger than amount of animals in database" << endl;
        return false;;
    }
    switch(choose)
    {
        case 1:
        {
            //choose is a variable to pick which data in the element we want to modify
            curr->refAge()=newvalue;
            return true;
        }
        case 2:
        {
            curr->refCost()=newvalue;
            return true;
        }
        default:
        {
            cout << "Error, no such variable number exists" << endl;
            return false;
        }
    }
}
bool ZooInterface::modEmp(int empID, string newstring)
{
    //modify given data value in element
    if(empID<=0)
    {
        cout << "Error, wrong ID given" << endl;
        return false;
    }
    ZooEmployee* curr=empHead;
    while(curr)
    {
        if(curr->refID()==empID)
        {
            break;
        }
        curr=curr->refNext();
    }
    if(!curr)
    {
        cout << "Error, ID given larger than amount of employees in database" << endl;
        return false;
    }
    curr->refName()=newstring;
    return true;
}
bool ZooInterface::modEmp(int empID, int newvalue)
{
    if(empID<=0)
    {
        cout << "Error, wrong ID given" << endl;
        return false;
    }
    ZooEmployee* curr=empHead;
    while(curr)
    {
        if(curr->refID()==empID)
        {
            break;
        }
        curr=curr->refNext();
    }
    if(!curr)
    {
        cout << "Error, ID given larger than amount of employees in database" << endl;
        return false;
    }
    curr->refWage()=newvalue;
    return true;
}
bool ZooInterface::modEx(int exID, string newstring)
{
    if(exID<=0)
    {
        cout << "Error, wrong ID given" << endl;
        return false;
    }
    ZooExhibit* curr=exHead;
    while(curr)
    {
        if(curr->refID()==exID)
        {
            break;
        }
        curr=curr->refNext();
    }
    if(!curr)
    {
        cout << "Error, ID given larger than amount of exhibitss in database" << endl;
        return false;
    }
    curr->refName()=newstring;
    return true;
}
bool ZooInterface::modEx(int exID, int newvalue)
{
    if(exID<=0)
    {
        cout << "Error, wrong ID given" << endl;
        return false;
    }
    ZooExhibit* curr=exHead;
    while(curr)
    {
        if(curr->refID()==exID)
        {
            break;
        }
        curr=curr->refNext();
    }
    if(!curr)
    {
        cout << "Error, ID given larger than amount of exhibitss in database" << endl;
        return false;
    }
    curr->refCost()=newvalue;
    return true;
}