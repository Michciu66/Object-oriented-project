#pragma once
#include<string>
#include<vector>
using namespace std;
 
class ZooAnimal;
class ZooEmployee;
class ZooExhibit;

class ZooEmployee 
{
    private:
    int ID;
    string name;
    int wage;
    vector<ZooAnimal*> aniList;
    ZooEmployee* next;
    public:
    ZooEmployee();
    ~ZooEmployee();
    ZooEmployee(int nID,string nname,int nwage);
    int& refID();
    string& refName();
    int& refWage(); //return references to work as both setters and getters for data
    ZooEmployee*& refNext();
    void printAniList();
    void printEmployee();
    void addAnimal(ZooAnimal* nAnimal);
    bool removeAnimal(int aniID);
    void clearList();
};

class ZooExhibit
{
    private:
    int ID;
    string name;
    int cost;
    ZooExhibit* next;
    vector<ZooAnimal*> aniList;
    public:
    ZooExhibit();
    ~ZooExhibit();
    ZooExhibit(int nID, string nname, int ncost);
    int& refID();
    string& refName();
    int& refCost(); //return references to work as both setters and getters for data
    ZooExhibit*& refNext();
    void printAniList();
    void printExhibit();
    void addAnimal(ZooAnimal* nAnimal);
    bool removeAnimal(int aniID);
    void clearList();
};

class ZooAnimal
{
    private:
    int ID;
    string name;
    string species;
    int age;
    int cost;
    ZooEmployee* careEmployee;
    ZooExhibit* currExhibit;
    ZooAnimal* next;
    public:
    ZooAnimal();
    ~ZooAnimal();
    ZooAnimal(int nID, string nname, string nspecies, int nage, int ncost);
    int& refID();
    string& refName();
    string& refSpecies();
    int& refAge();
    int& refCost(); //return references to work as both setters and getters for data
    ZooEmployee*& refEmp();
    ZooExhibit*& refEx();
    ZooAnimal*& refNext();
    void printAnimal();
};

class ZooInterface
{
    private:
    string location;
    string name;
    ZooEmployee* empHead;
    ZooAnimal* aniHead;
    ZooExhibit* exHead;
    public:
    ZooInterface();
    ~ZooInterface();
    ZooInterface(string nlocation, string nname);
    bool addEmployee(string nname, int nwage);
    bool addAnimal(string nname, string nspecies, int nage, int ncost);
    bool addExhibit(string nname, int ncost); //objects are added at the end of list, IDs are dynamically allocated 
                                              //by time of addition (first added object has ID 1, second has ID 2 and so on)
    void printZoo(); //prints out all three lists and zoo data
    int sumCosts();    //sum of costs of all objects
    bool modAni(int aniID, int choose, string newstring);
    bool modAni(int aniID, int choose, int newvalue);
    bool modEmp(int empID, string newstring);
    bool modEmp(int empID, int newvalue);
    bool modEx(int exID, string newstring);
    bool modEx(int exID, int newvalue); //modify aspects of  specific objects
    bool assignAni2Emp(int aniID, int empID);
    bool assignAni2Ex(int aniID, int exID); //assign objects to lists contained in other objects
    bool deAssignAniFromEmp(int AniID);
    bool deAssignAniFromEx(int AniID); //break connection between objects
    int countAni();
    int countEx();
    int countEmp(); //returns number of specific objects;
    void printAniList();
    void printEmpListFull();
    void printEmpList();
    void printExListFull();
    void printExList();
    void printAni(int aniID);
    void printEmp(int empID);
    void printEx(int exID);//print specific object
    bool isAni(int aniID);
    bool isEmp(int empID);
    bool isEx(int exID); //returns true if an object of given ID can be found in its respective list
    bool removeEmp(int empID);
    bool removeAni(int aniID);
    bool removeEx(int exID); //removes object of given ID than updates the IDs of other objects of the same type
};
