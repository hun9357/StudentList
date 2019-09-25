#include <iostream>
#include <string>

using namespace std;

class student
{
public:
	string name;
	unsigned int id;
	double gpa;

	student()
	{
		name = "ghost";
		id = 0;
		gpa = 0;
	}
	student(string _name, unsigned int _id, double _gpa)
	{
		id = _id;
		gpa = _gpa;
		name = _name;
	}
};
class studentList
{
private:
	//Implement a doubly linked list of students

	class node
	{
	public:
		student data;
		node * next;
		node * prev;

		node(student x)
		{
			data = x;
			next = NULL;
			prev = NULL;
		}
	};

	node * head;
	node * tail;

public:
	studentList()
	{
		head = nullptr;
		tail = nullptr;
	}
	//add a student to the list.
	//Must run in O(1) time.
	void insert(student s)
	{
		node *babynode = new node(s);
		if (head == nullptr)
		{
			head = babynode;
			tail = babynode;
		}
		else
		{
			tail->next = babynode;
			babynode->prev = tail;
			tail = babynode;
		}
	}

	//find the student with the given id number and return it
	//What is the worst case run time of this? - O(n) run time because if the list size is getting bigger, it will take more time to search.
	//What is the average case run time of this? - O(n) run time
	student retrieveStudent(unsigned int idnumber)
	{
		student x;
		node*temp = head;
		if (head == nullptr)
		{
			cout << "Empty list" << endl;
			return x;
		}
		else
		{
			while (temp->next != nullptr)
			{
				temp = temp->next;
				if (temp->data.id == idnumber)
				{
					x = temp->data;
					return x;
				}
			}
			cout << "There is no student with ID: " << idnumber << endl;
			return x;
		}
	}
	//Change the gpa of the student with given id number to newGPA
	//What is the run time?  - O(n) run time since every item in the list must check for condition
	void updateGPA(unsigned int idnumber, double newGPA)
	{
		node*temp = head;
		if (head == nullptr)
		{
			cout << "Empty list" << endl;
		}
		else
		{
			while (temp->next != nullptr)
			{
				if (temp->data.id == idnumber)
				{
					break;
				}
				else
				{
					temp = temp->next;
				}
			}
			if (temp->data.id != idnumber)
			{
				cout << "There is no student with ID: " << idnumber << endl;
			}
			else
			{
				temp->data.gpa = newGPA;
			}
		}
	}
	//Add all students from otherlist to this list.
	//otherlist should be empty after this operation.
	//Must run in O(1) time.
	void mergeList(studentList &otherlist)
	{
		if (head == nullptr&&otherlist.head == nullptr)
		{
			cout << "Both lists are empty" << endl;;
		}
		else
		{
			if (head == nullptr)
			{
				head = otherlist.head;
				tail = otherlist.tail;
			}
			else if (otherlist.head == nullptr)
			{
				cout << "Other list is empty" << endl;
			}
			else
			{
				tail->next = otherlist.head;
				otherlist.head->prev = tail;
				tail = otherlist.tail;
				otherlist.head = nullptr;
				otherlist.tail = nullptr;
			}
		}
	}
	//create a list of students whose gpa is at least minGPA.
	//Return this list.  The original list should
	//not be modified (do not remove the students from the original list).
	//Run time? - O(n) run time. 
	studentList honorRoll(double minGPA)
	{
		studentList Honor;
		node*temp = head;
		if (head == nullptr)
		{
			cout << "Empty list" << endl;
			return Honor;
		}
		if (minGPA < 0)
		{
			cout << "Please re-enter the minimum GPA" << endl;
			return Honor;
		}
		else
		{
			while (temp != nullptr)
			{
				if (temp->data.gpa >= minGPA)
				{
					Honor.insert(temp->data);
				}
				temp = temp->next;
			}
			if (Honor.head == nullptr)
			{
				cout << "There is no student with minimum GPA: " << minGPA << endl;
			}
			return Honor;
		}
	}
	
	//sort the list by the given field ("name", "id", or "gpa").
	//Run time? - O(n) run time, run time depends on the size of the lists.
	void sort(string field)
	{
		node*start = head;
		node*end = head->next;
		student x;
		if (field == "name")
		{
			while (start->next != nullptr)
			{
				if (start->data.name > end->data.name)
				{
					node *save = new node(x);
					save->data = start->data;
					start->data = end->data;
					end->data = save->data;
					delete save;
				}
				else if (end->next == nullptr)
				{
					start = start->next;
					end = start->next;
				}
				else
				{
					end = end->next;
				}
			}
		}
		else if (field == "id")
		{
			while (start->next != nullptr)
			{
				if (start->data.id > end->data.id)
				{
					node *save = new node(x);
					save->data = start->data;
					start->data = end->data;
					end->data = save->data;
					delete save;
				}
				else if (end->next == nullptr)
				{
					start = start->next;
					end = start->next;
				}
				else
				{
					end = end->next;
				}
			}
		}
		else if (field == "gpa")
		{
			while (start->next != nullptr)
			{
				if (start->data.gpa > end->data.gpa)
				{
					node *save = new node(x);
					save->data = start->data;
					start->data = end->data;
					end->data = save->data;
					delete save;
				}
				else if (end->next == nullptr)
				{
					start = start->next;
					end = start->next;
				}
				else
				{
					end = end->next;
				}
			}
		}
		else
		{
			cout << "Please enter correct field name " << endl;
		}
	}
	//Print out each student in the list.  This is mainly for testing purposes.
	void printList()
	{
		node*temp = head;
		if (head == nullptr)
		{
			cout << "List is empty!!" << endl;
		}
		else
		{
			while (temp != nullptr)
			{
				cout << "Student name: " << temp->data.name << "  ID: " << temp->data.id << "  GPA: " << temp->data.gpa << endl;
				temp = temp->next;
			}
		}
	}
};
