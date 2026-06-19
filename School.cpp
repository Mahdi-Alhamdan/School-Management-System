#include<iostream>
using namespace std;
#define max_st 100

class Student
{
public:
	string Name;
	int ID;
	float GPA;
};

Student database[max_st];
int st_count = 0;

void AddStudent();
void ShowList();
void ShowStudent();
void UpdateStudentInfo();
void DeleteStudent();
void ClearInput();
int CountDigit(int number);
bool AlreadyExist(int id);

int main()
{
	cout << "\nWelcome to the system\n";
	int ch;
	do
	{
		cout << "\n";
		cout << "|----Main Menu----|\n";
		cout << "|1. Add Student.  |\n";
		cout << "|2. Show list.    |\n";
		cout << "|3. Show student. |\n";
		cout << "|4. Update info.  |\n";
		cout << "|5. Delete student|\n";
		cout << "|0. Exit.         |\n";
		cout << "|-----------------|\n";

		cout << "\nEnter your choice: ";
		while(!(cin >> ch))
		{
			ClearInput();
			cout << "Only numbers allowed!\nEnter your choice: ";
			cin >> ch;
		}

		switch(ch)
		{
		case 1:
			AddStudent();
			break;
		case 2:
		    ShowList();
		    break;
		case 3:
		    ShowStudent();
		    break;
		case 4:
		    UpdateStudentInfo();
		    break;
		case 5:
		    DeleteStudent();
		    break;
		case 0:
		    cout << "\nYou exited the system succesfully.";
		    break;
		default:
		    cout << "\nInvalid input!\n";
		}
	}
	while(ch != 0);
	return 0;
}

bool AlreadyExist(int id)
{
    for(int i = 0; i < st_count; i++)
    {
        if(database[i].ID == id)
        {
            return true;
        }
    }
    
    return false;
}

int CountDigit(int number)
{
   int count = 0;
   while(number > 0)
   {
       number /= 10;
       count++;
   }
   return count;
}

void ClearInput()
{
	cin.clear();
	cin.ignore(10000, '\n');
}

void AddStudent()
{
    if(st_count >= max_st)
    {
        cout << "\nData base is full\n";
        return;
    }
    
    cin.ignore();
    cout << "\nEnter student's name: ";
    getline(cin, database[st_count].Name);
    
    cout << "Enter student's ID: ";
    while(!(cin >> database[st_count].ID))
    {
		ClearInput();
        cout << "Only numbers allowed!\nEnter student's ID: ";
        cin >> database[st_count].ID;
    }
    
    while(CountDigit(database[st_count].ID) != 9)
    {
		ClearInput();
        cout << "ID must be 9 digits!\nEnter student's ID: ";
        cin >> database[st_count].ID;
    }
    
    if(AlreadyExist(database[st_count].ID))
    {
        cout << "Student already exist.\n";
        return;
    }
    
    cout << "Enter student's GPA: ";
    while(!(cin >> database[st_count].GPA))
    {
		ClearInput();
        cout << "Only numbers allowed!\nEnter student's ID: ";
        cin >> database[st_count].GPA;
    }
    
    st_count++;
    cout << "\nStudent have added.\n";
}

void ShowList()
{
    if(st_count == 0)
    {
        cout << "\nData base is empty.\n";
        return;
    }
    
    for(int i = 0; i < st_count; i++)
    {
        cout << "\nStudent_" << i+1 << endl;
        cout << "Name: " << database[i].Name << endl;
        cout << "ID: " << database[i].ID << endl;
        cout << "GPA: " << database[i].GPA << endl;
        cout << "------------------\n";
    }
}

void ShowStudent()
{
    if(st_count == 0)
    {
        cout << "\nData base is empty.\n";
        return;
    }
    
    int SearchID;
    bool found = false;
    cout << "Enter Id to search: ";
    while(!(cin >> SearchID))
    {
		ClearInput();
        cout << "Only numbers allowed!\nEnter ID to search: ";
        cin >> SearchID;
    }
    
    for(int i = 0; i < st_count; i++)
    {
        if(database[i].ID == SearchID)
        {
            cout << "\nStudent_" << i+1 << endl;
            cout << "Name: " << database[i].Name << endl;
            cout << "ID: " << database[i].ID << endl;
            cout << "GPA: " << database[i].GPA << endl;
            found = true;
        }
    }
    
    if(!found)
    {
        cout << "\nStudent not found.\n";
    }
}

void UpdateStudentInfo()
{
    if(st_count == 0)
    {
        cout << "\nData base is empty.\n";
        return;
    }
    
    int SearchID;
    bool found = false;
    cout << "Enter Id to search: ";
    while(!(cin >> SearchID))
    {
		ClearInput();
        cout << "Only numbers allowed!\nEnter ID to search: ";
        cin >> SearchID;
    }
    
    for(int i = 0; i < st_count; i++)
    {
        if(database[i].ID == SearchID)
        {
            cin.ignore();
            cout << "\nStudent found\n";
            cout << "Enter new name: ";
            getline(cin, database[i].Name);
            
            cout << "Enter new ID: ";
            while(!(cin >> database[i].ID))
            {
				ClearInput();
                cout << "Only numbers allowed!\nEnter new ID: ";
                cin >> database[i].ID;
            }
            
            while(CountDigit(database[i].ID) != 9)
            {
				ClearInput();
                cout << "ID must be 9 digits!\nEnter student's ID: ";
                cin >> database[i].ID;
            }
            
            if(AlreadyExist(database[i].ID))
            {
                cout << "Student already exist.\n";
                return;
            }
            cout << "Enter new GPA: ";
            while(!(cin >> database[i].GPA))
            {
				ClearInput();
                cout << "Only numbers allowed!\nEnter new ID: ";
                cin >> database[i].GPA;
            }
            
            cout << "\nStudent info have updated.\n";
            found = true;
        }
    }
    
    if(!found)
    {
        cout << "\nStudent not found.\n";
    }
}

void DeleteStudent()
{
    if(st_count == 0)
    {
        cout << "\nData base is empty.\n";
        return;
    }
    
    int SearchID;
    bool found = false;
    cout << "Enter ID to search: ";
    while(!(cin >> SearchID))
    {
		ClearInput();
        cout << "Only numbers allowed!\nEnter ID to search: ";
        cin >> SearchID;
    }
    
    for(int i = 0; i < st_count; i++)
    {
        if(database[i].ID == SearchID)
        {
            for(int j = i; j < st_count - 1; j++)
            {
                database[j] = database[j+1];
            }
            
            cout << "\nStudent have deleted.\n";
            st_count--;
            found = true;
        }
    }
    
    if(!found)
    {
        cout << "\nStudent not found.\n";
    }
}


