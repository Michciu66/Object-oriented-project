#include"header.h"
#include<iostream>
#include<string>
using namespace std;


int main()
{   
    int choose=0;
    while(true)
    {
        cout << "Enter test number" << endl;
        cin >> choose;
        switch(choose)
        {
            case -1:
            {
                cout << "Goodbye";
                return 0;
            }
            case 1:
            {
                //ZooInterface Initialization
                ZooInterface zoo("New zoo","Warsaw");
                zoo.printZoo(); //test of printZoo, and the printList functions with empty lists
                cout << endl;
                zoo.addAnimal("TestAnimal1","Cat",2,2);
                zoo.addEmployee("TestEmployee1",2);
                zoo.addExhibit("TestExhibit1",2); //adding new elements to empty lists
                cout << "printZoo with single elements" << endl;
                zoo.printZoo(); //test of printZoo and printLists with single elements
                cout << endl;
                break;
            }
            case 2:
            {
                //Testing addition to non-empty lists
                ZooInterface zoo("New zoo", "Warsaw");
                zoo.addAnimal("TestAnimal1", "Cat", 2, 2);
                zoo.addEmployee("TestEmployee1", 2);
                zoo.addExhibit("TestExhibit1", 2);
                zoo.addAnimal("TestAnimal2", "Cat", 2, 2);
                zoo.addEmployee("TestEmployee2", 2);
                zoo.addExhibit("TestExhibit2", 2); //adding new elements to non-empty lists;
                cout << "printZoo with multiple elements" << endl;
                zoo.printZoo();
                cout << endl;
                break;
            }
            case 3:
            {
                //Testing removal of elements
                ZooInterface zoo("New zoo", "Warsaw");
                zoo.addAnimal("", "Horse", -6345, 236346); // adding new elements - wrong data
                zoo.addAnimal("TestAnimal1", "Cat", 2, 2);
                zoo.addEmployee("TestEmployee1", 2);
                zoo.addExhibit("TestExhibit1", 2);
                zoo.addAnimal("TestAnimal2", "Cat", 2, 2);
                zoo.addEmployee("TestEmployee2", 2);
                zoo.addExhibit("TestExhibit2", 2);
                zoo.removeAni(-1); //remove element - wrong data
                zoo.removeEmp(2); //remove element - not the head
                zoo.removeEx(1); //remove element - head
                cout << "printZoo after removal - should contain two animals, TestEmployee1 and TestExhibit2" << endl;
                zoo.printZoo(); //printing after removal
                break;
            }
            case 4:
            {
                //Testing printing and modification of elements
                ZooInterface zoo("New zoo", "Warsaw");
                zoo.addAnimal("TestAnimal1", "Cat", 2, 2);
                zoo.addEmployee("TestEmployee1", 2);
                zoo.addExhibit("TestExhibit1", 2);
                zoo.addAnimal("TestAnimal2", "Cat", 2, 2);
                zoo.addEmployee("TestEmployee2", 2);
                zoo.addExhibit("TestExhibit2", 2);
                cout << "Print specific element - should print TestAnimal2" << endl;
                zoo.printAni(2);
                cout << endl;
                cout << "Print specific element - should print 'No such employee in List' " << endl;
                zoo.printEmp(4);
                cout << endl;
                zoo.modAni(2, 1, "ChangedName");
                zoo.modAni(2, 2, "Dog");
                zoo.modAni(2, 1, 22);
                zoo.modAni(2, 2, 66);
                zoo.modEmp(1, 69);
                zoo.modEmp(1, "ChangedName");//modify element data
                cout << "Print specific animal after modifying data - should print ChangedName with age 22 and cost 66" << endl;
                zoo.printAni(2);
                cout << "Print specific employee after modifying data - should print ChangedName with wage 69" << endl;
                cout << endl;
                zoo.printEmp(1);
                cout << "Modifying non-existant element - should print 'Error, wrong ID given'" << endl;
                zoo.modAni(-5, 1, 22);
                cout << "Modifying non-existant data value - should print 'Error, no such variable number exists'" << endl;
                zoo.modAni(2, 5, 11);
                break;
            }
            case 5:
            {
                //Testing creation of connections between elements
                ZooInterface zoo("New zoo", "Warsaw");
                zoo.addAnimal("TestAnimal1", "Cat", 2, 2);
                zoo.addEmployee("TestEmployee1", 2);
                zoo.addExhibit("TestExhibit1", 2);
                zoo.addAnimal("TestAnimal2", "Cat", 2, 2);
                zoo.addEmployee("TestEmployee2", 2);
                zoo.addExhibit("TestExhibit2", 2);
                zoo.assignAni2Emp(1, 1); //assignment test to employee
                zoo.assignAni2Ex(2, 1); //assignment to exhibit
                cout << "printZoo after all assignments are made - TestAnimal1 connected to Employee1, Animal2 connected to Exhibit1" << endl;
                zoo.printZoo();
                cout << endl;
                zoo.assignAni2Emp(1, 2); //changing assigned employee
                zoo.assignAni2Ex(2, 2);
                cout << "assignment to non-existant employee - should print 'Error in assignment, at least one of given objects doesn't exist'" << endl;
                zoo.assignAni2Emp(2, 3); //assigning to non-existant employee (assignment with wrong data)
                cout << "printZoo after all assignments are made - TestAnimal1 connected to Employee2, Animal2 connected to Exhibit2" << endl;
                zoo.printZoo();
                break;
            }
            case 6:
            {
                //Testing deletion of connection between elements
                ZooInterface zoo("New zoo", "Warsaw");
                zoo.addAnimal("TestAnimal1", "Cat", 2, 2);
                zoo.addEmployee("TestEmployee1", 2);
                zoo.addExhibit("TestExhibit1", 2);
                zoo.addAnimal("TestAnimal2", "Cat", 2, 2);
                zoo.addEmployee("TestEmployee2", 2);
                zoo.addExhibit("TestExhibit2", 2);
                zoo.addAnimal("TestAnimal3", "Cat", 2, 2);
                zoo.assignAni2Emp(1, 1);
                zoo.assignAni2Emp(3, 1);
                zoo.deAssignAniFromEmp(1); //Deassignment 
                zoo.deAssignAniFromEmp(2); //Deassignment for animal with no connection
                zoo.deAssignAniFromEmp(3); //Deassignment for nonexistant animal
                cout << "printZoo after all deassignments are done - TestAnimal3 connected to Employee1" << endl;
                zoo.printZoo();
                break;
            }
            case 7:
            {
                //Testing of counting functions and summation of costs
                ZooInterface zoo("New zoo", "Warsaw");
                zoo.addAnimal("TestAnimal1", "Cat", 2, 2);
                zoo.addEmployee("TestEmployee1", 2);
                zoo.addExhibit("TestExhibit1", 2);
                zoo.addAnimal("TestAnimal2", "Cat", 2, 2);
                zoo.addEmployee("TestEmployee2", 2);
                zoo.addExhibit("TestExhibit2", 2);
                cout << "Number of animals (should be 2): " << zoo.countAni() << " Number of Employees (should be 2): " << zoo.countEmp() << " Number of Exhibits (should be 2): " << zoo.countEx() << endl;
                cout << "Daily costs (should be equal to 12): " << zoo.sumCosts() << endl; //Sum costs and count functions test
                break;
            }
            case 8:
            {
                //Testing various methods for an empty zoo
                ZooInterface zoo("New zoo", "Warsaw");
                zoo.assignAni2Emp(1, 1);
                zoo.deAssignAniFromEmp(1);
                zoo.removeAni(1);
                zoo.printAni(1);
                break;
            }
            case 9:
            {
                //Testing multiple top-level elements at the same time
                ZooInterface zoo1("New zoo", "Warsaw");
                ZooInterface zoo2("Newer zoo", "Cracow");
                zoo1.addAnimal("TestAnimal1", "Cat", 2, 2);
                zoo1.addEmployee("TestEmployee1", 2);
                zoo1.addExhibit("TestExhibit1", 2);
                zoo2.addAnimal("TestAnimal2", "Cat", 2, 2);
                zoo2.addEmployee("TestEmployee2", 2);
                zoo2.addExhibit("TestExhibit2", 2);
                zoo1.printZoo();
                zoo2.printZoo();
                break;
            }
        }
    }
}