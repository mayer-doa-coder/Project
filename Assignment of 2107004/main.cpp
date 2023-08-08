#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

class police_system;
class officer;
class staff;
class criminal;
class police_case;
class witness;

//********** POLICE DEPARTMENT SYSTEM **********//
class police_system
{
    private:

    vector<officer> officers;
    vector<staff> staffs;
    vector<criminal> criminals;
    vector<police_case> cases;
    vector<witness> witnesses;

    public:

    void add_officer();
    void add_criminal();
    void add_staff();
    void add_police_case();
    void add_witness();
    void show_officer_data();
    void show_criminal_data();
    void show_staff_data();
    void show_police_case_data();
    void show_witness_data();
    void search_officer();
    void search_staff();
    void search_criminal();
    void search_police_case();
    void search_witness_data();
    void remove_officer();
    void remove_criminal();
    void remove_staff();
    friend void promote_officer(police_system &people, int id);
    friend void add_initial_data(police_system &people);
};

// ********** OFFICER CLASS ********** //

class officer
{
    private:

    int officer_id;
    string officer_name;
    string officer_position;
    string officer_phone;
    string officer_NID;

    public:

    officer()
    {}

    officer(int officer_id, string officer_name, string officer_position, string officer_phone, string officer_NID)
    {
        this->officer_id=officer_id;
        this->officer_name=officer_name;
        this->officer_position=officer_position;
        this->officer_phone=officer_phone;
        this->officer_NID=officer_NID;
    }

    int get_officer_id()
    {
        return officer_id;
    }

    void get_officer_position(string s)
    {
        officer_position = s;
    }

    void show_officer()
    {
        cout<<endl;
        cout << "ID number of the Officer is: " << officer_id << endl;
        cout << "Name of the Officer is: " << officer_name << endl;
        cout << "Position of the Officer is: " << officer_position << endl;
        cout << "Contact number of the Officer is: " << officer_phone << endl;
        cout << "NID number of the Officer is: " << officer_NID << endl;

        cout<<endl;
    }
};

// ********** CRIMINAL CLASS ********** //

class criminal
{
    private:

    int criminal_id;
    string criminal_name;
    int criminal_cellno;
    string criminal_crime;
    int criminal_punishment;

    public:

    criminal()
    {

    }

    criminal(int criminal_id, string criminal_name, int
    criminal_cellno, string criminal_crime, int criminal_punishment)
    {
        this->criminal_id=criminal_id;
        this->criminal_name=criminal_name;
        this->criminal_cellno=criminal_cellno;
        this->criminal_crime=criminal_crime;
        this->criminal_punishment=criminal_punishment;
    }

    void show_criminal()
    {
        cout<<endl;
        cout << "ID number of the Criminal is: " << criminal_id << endl;
        cout << "Name of the Criminal is: " << criminal_name << endl;
        cout << "Cell no of the Criminal is: " << criminal_cellno << endl;
        cout << "Crime of the Criminal is: " << criminal_crime << endl;
        cout << "Punishment of the Criminal is: " << criminal_punishment <<" yrs"<< endl;

        cout<<endl;
    }

    friend class police_case;
    int get_criminal_id()
    {
        return criminal_id;
    }

    int get_punishment_dur()
    {
        return criminal_punishment;
    }

};

// ********** STAFF CLASS ********** //

class staff
{
    private:

    int staff_id;
    string staff_name;
    string staff_position;
    string staff_phone;
    string staff_NID;

    public:

    staff()
    {

    }

    staff(int staff_id, string staff_name, string staff_position, string staff_phone, string staff_NID)
    {
        this->staff_id=staff_id;
        this->staff_name=staff_name;
        this->staff_position=staff_position;
        this->staff_phone=staff_phone;
        this->staff_NID=staff_NID;
    }

    int get_staff_id()
    {
        return staff_id;
    }

    string get_staff_position()
    {
        return staff_position;
    }

    void show_staff()
    {
        cout<<endl;
        cout << "ID number of the Staff is: " << staff_id << endl;
        cout << "Name of the Staff is: " << staff_name << endl;
        cout << "Position of the Staff is: " << staff_position << endl;
        cout << "Contact number of the Staff is: " << staff_phone << endl;
        cout << "NID number of the Staff is: " << staff_NID << endl;

        cout<<endl;
    }
};

// ********** CASE CLASS ********** //

class police_case
{
    private:

    string criminal_name;
    string case_description;
    int case_id;
    string case_status;

public:
    police_case(string criminal_name, string case_description, int case_id, string case_status)
    {
        this->criminal_name=criminal_name;
        this->case_description=case_description;
        this->case_id=case_id;
        this->case_status=case_status;
    }
    void show_police_case()
    {
        cout<<endl;
        cout << "Case ID: " << case_id << endl;
        cout << "Case Description: " << case_description << endl;
        cout << "Criminal Name: " << criminal_name << endl;
        cout << "Case Status: " << case_status << endl;

        cout<<endl;
    }
    int get_case_id()
    {
        return case_id;
    }
};

// ********** WITNESS CLASS ********** //

class witness
{
    private:

    string wit_name;
    string wit_statement;

public:

    int wit_age;
    witness(string wit_name, int wit_age, string wit_statement)
    {
        this->wit_name=wit_name;
        this->wit_age=wit_age;
        this->wit_statement=wit_statement;
    }

    void show_witness()
    {
        cout << "Name of the Witness is:" << wit_name << endl;
        cout << "Age of the Witness is: " << wit_age<< endl;
        cout << "Statement of the Criminal is: " << wit_statement << endl;

        cout<<endl;
    }

    int witness_age()
    {
        return wit_age;
    }
};

void police_system::add_staff()
{
    int n;
    cout << "HOW MANY STAFFS DO YOU WANT TO ADD: ";
    cin >> n;

    int id[n];
    string name;
    string post;
    string num;
    string nid;

    for(int i = 0; i < n; i++)
    {
        cout << "ENTER A STAFF ID : ";
        cin >> id[i];
        cin.ignore();
        cout << "ENTER THE STAFF NAME : ";
        getline(cin, name);
        cout << "ENTER THE STAFF POSITION : ";
        getline(cin, post);
        cout << "ENTER THE STAFF CONTACT NUMBER : ";
        cin >> num;
        cout << "ENTER THE STAFF NATIONAL ID NUMBER : ";
        cin >> nid;
        staff new_staff(id[i], name, post, num, nid);
        staffs.push_back(new_staff);
    }
}

void police_system::add_criminal()
{
    int n;
    cout << "HOW MANY CRIMINALS DO YOU WANT TO ADD: ";
    cin >> n;

    int id[n];
    string name;
    int punish[n];
    int cell[n];
    string crime;

    for(int i = 0; i < n; i++)
    {
        cout << "ENTER A CRIMINAL ID : ";
        cin >> id[i];
        cin.ignore();
        cout << "ENTER THE CRIMINAL NAME : ";
        getline(cin, name);
        cout << "ENTER THE DURATION OF PUNISHMENT : ";
        cin>>punish[i];
        cout << "ENTER THE CELL NUMBER : ";
        cin >> cell[i];
        cout << "ENTER THE CRIME DESCRIPTION : ";
        cin >> crime;
        criminal new_criminal(id[i], name, cell[i], crime, punish[i]);
        criminals.push_back(new_criminal);
    }
}


void police_system::add_officer()
{
    int n;
    cout << "HOW MANY OFFICERS DO YOU WANT TO ADD: ";
    cin >> n;

    int id[n];
    string name;
    string post;
    string number;
    string nid;

    for(int i = 0; i < n; i++)
    {
        cout << "ENTER A OFFICER ID : ";
        cin >> id[i];
        cin.ignore();
        cout << "ENTER THE OFFICER NAME : ";
        getline(cin, name);
        cout << "ENTER THE OFFICER POSITION : ";
        getline(cin, post);
        cout << "ENTER THE OFFICER CONTACT NUMBER : ";
        cin >> number;
        cout << "ENTER THE OFFICER NATIONAL ID NUMBER : ";
        cin >> nid;
        officer new_officer(id[i], name, post, number, nid);
        officers.push_back(new_officer);
    }
}

void police_system::add_police_case()
{
    string criminal_name;
    string case_description;
    string case_id;
    string case_status;

    int n;
    cout << "HOW MANY CASES DO YOU WANT TO ADD: ";
    cin >> n;

    string name;
    string description;
    int id[n];
    string status;

    for(int i = 0; i < n; i++)
    {
        cout << "ENTER A CASE ID : ";
        cin >> id[i];
        cin.ignore();
        cout << "ENTER THE CASE DESCRIPTION : ";
        getline(cin, description);
        cout << "ENTER THE CRIMINAL WHO COMMITTED THE CRIME : ";
        getline(cin, name);
        cout << "ENTER THE CASE STATUS : ";
        cin >> status;
        police_case new_case(name, description, id[i], status);
        cases.push_back(new_case);
        if(status=="SOLVED")
        {
            int criminal_id=id[i];
            string criminal_name=name;
            srand(static_cast<int>(time(nullptr)));
            int low=1;
            int high=500;
            int cell_no=(rand() % (high- low + 1)) + low;
            string crime=description;
            int lower=1;
            int higher=20;
            int punishment=(rand() % (higher - lower + 1)) + lower;

            criminal new_criminal(criminal_id, criminal_name, cell_no, crime, punishment);
            criminals.push_back(new_criminal);
        }
    }
}

void police_system::add_witness()
{
    int n;
    cout << "HOW MANY WITNESS DO YOU WANT TO ADD: ";
    cin >> n;

    string name;
    int age[n];
    string stmt;

    for(int i = 0; i < n; i++)
    {
        cout << "ENTER THE WITNESS AGE : ";
        cin>>age[i];
        cin.ignore();
        cout << "ENTER A WTINESS NAME : ";
        getline(cin, name);
        cout << "ENTER THE STATEMENT OF THE WITNESS : ";
        getline(cin, stmt);
        witness new_witness(name, age[i], stmt);
        witnesses.push_back(new_witness);
    }
}

void police_system::show_criminal_data()
{
    for (int i = 0; i<criminals.size(); i++)
    {
        criminals[i].show_criminal();
    }
}
void police_system::show_officer_data()
{
    for (int i = 0; i < officers.size(); i++)
    {
        officers[i].show_officer();
    }
}
void police_system::show_staff_data()
{
    for (int i = 0; i < staffs.size(); i++)
    {
        staffs[i].show_staff();
    }
}
void police_system::show_police_case_data()
{
    for (int i = 0; i < cases.size(); i++)
    {
        cases[i].show_police_case();
    }
}
void police_system::show_witness_data()
{
    for (int i = 0; i < witnesses.size(); i++)
    {
        witnesses[i].show_witness();
    }
}

void police_system::search_officer()
{
    int flag{0};
    int id;
    cout<<"Enter the ID you want to search: ";
    cin>>id;
    for(int i=0;i<officers.size();i++)
    {
        if(id==officers[i].get_officer_id())
        {
            cout<<"ID FOUND"<<endl;
            officers[i].show_officer();
            flag=1;
            break;
        }
    }
    if(flag==0)
        cout<<"ID NOT FOUND! OOPS"<<endl;
}

void police_system::search_criminal()
{
    int flag{0};
    int id;
    cout<<"Enter the ID you want to search: ";
    cin>>id;
    for(int i=0;i<criminals.size();i++)
    {
        if(id==criminals[i].get_criminal_id())
        {
            cout<<"ID FOUND"<<endl;
            criminals[i].show_criminal();
            flag=1;
            break;
        }
    }
    if(flag==0)
        cout<<"ID NOT FOUND! OOPS"<<endl;
}

void police_system::search_staff()
{
    int flag{0};
    int id;
    cout<<"Enter the ID you want to search: ";
    cin>>id;
    for(int i=0;i<staffs.size();i++)
    {
        if(id==staffs[i].get_staff_id())
        {
            cout<<"ID FOUND"<<endl;
            staffs[i].show_staff();
            flag=1;
            break;
        }
    }
    if(flag==0)
        cout<<"ID NOT FOUND! OOPS"<<endl;
}

void police_system::search_police_case()
{
    int flag{0};
    int id;
    cout<<"Enter the ID you want to search: ";
    cin>>id;
    for(int i=0;i<cases.size();i++)
    {
        if(id==cases[i].get_case_id())
        {
            cout<<"ID FOUND"<<endl;
            cases[i].show_police_case();
            flag=1;
            break;
        }
    }
    if(flag==0)
        cout<<"ID NOT FOUND! OOPS"<<endl;
}

void police_system::search_witness_data()
{
    int age;
    cout << "Enter the age of the witness you want to search: ";
    cin >> age;
    int flag{0};

    for (int i=0;i<witnesses.size(); i++)
    {
        if (age == witnesses[i].witness_age())
        {
            cout << "WITNESS FOUND" << endl;
            witnesses[i].show_witness();
            flag=1;
            break;
        }
    }
    if (flag==0)
        cout << "WITNESS NOT FOUND! OOPS" << endl;
}


void promote_officer(police_system &people, int id)
{
    for (int i = 0; i < people.officers.size(); i++)
    {
        if (people.officers[i].get_officer_id() == id)
        {
            cout << "ENTER THE POST HE IS PROMOTED :";
            cin.ignore();
            string s;
            getline(cin,s);
            people.officers[i].get_officer_position(s);
            cout << people.officers[i].get_officer_id() << " SUCESSFULLY PROMOTED" << endl;
            return;
        }
    }
    cout<<"ID NOT FOUND!! OOPS"<<endl;
}

void police_system::remove_officer()
{
    int id;
    cout << "Enter the ID of the Officer you want to remove: ";
    cin >> id;

    for (int i = 0; i < officers.size(); i++)
    {
        if (officers[i].get_officer_id() == id)
        {
            officers.erase(officers.begin() + i);
            cout << "Officer with ID " << id << " has been removed." << endl;
            return;
        }
    }

    cout << "Officer with ID " << id << " not found" << endl;
}

void police_system::remove_staff()
{
    int id;
    cout << "Enter the ID of the Staff you want to remove: ";
    cin >> id;

    for (int i = 0; i < staffs.size(); i++)
    {
        if (staffs[i].get_staff_id() == id)
        {
            staffs.erase(staffs.begin() + i);
            cout << "Staff with ID " << id << " has been removed." << endl;
            return;
        }
    }

    cout << "Staff with ID " << id << " not found" << endl;
}

void police_system::remove_criminal()
{
    int id,dur;
    cout << "Enter the ID of the Criminal you want to remove: ";
    cin >> id;
    cout<<"Enter the Duration of the Punishment: ";
    cin>>dur;

    for (int i = 0; i < criminals.size(); i++)
    {
        if (criminals[i].get_criminal_id() == id)
        {
            if(criminals[i].get_punishment_dur()<=dur)
            {
                criminals.erase(criminals.begin() + i);
                cout << "Criminal with ID " << id << " has been removed." << endl;
                return;
            }
            else
            {
                cout<<"You are acting against the Law. You are under arrest!!!"<<endl;
                return;
            }
        }
    }

    cout << "Criminal with ID " << id << " not found" << endl;
}

void add_initial_data(police_system &people)
{
    officer officer1(01,"Tawhidul Hasan","Commissioner","01795808433","1000");
    officer officer2(02,"Sarawad Hossain","Deputy Commissioner","01795841234","2000");
    officer officer3(03,"Sayeed Bin Omar","Officer-In-Charge","01716516524","3000");
    people.officers.push_back(officer1);
    people.officers.push_back(officer2);
    people.officers.push_back(officer3);

    criminal criminal1(11,"Dewan Ziswan",420, "Cyber Crime",10);
    criminal criminal2(22,"Oitijya Avru",205, "Traffic Violation",2);
    criminal criminal3(33,"Sabid Zenith",550, "Molesty",20);
    people.criminals.push_back(criminal1);
    people.criminals.push_back(criminal2);
    people.criminals.push_back(criminal3);

    staff staff1(15,"Maruf Shafiq","Food Observer","01857373782","1111");
    staff staff2(16,"Soup Rohan","Floor Cleaner","01918765234","2222");
    staff staff3(17,"Shejan Saif","Security Guard","01654565461","3333");
    people.staffs.push_back(staff1);
    people.staffs.push_back(staff2);
    people.staffs.push_back(staff3);

    police_case case1("Dewan Ziswan", "Cyber Crime", 100, "SOLVED");
    police_case case2("Unknown", "Terrorist Attack", 220, "UNSOLVED");
    police_case case3("Nafiz Ahmed", "Bank Robbery",123, "ONGOING");
    people.cases.push_back(case1);
    people.cases.push_back(case2);
    people.cases.push_back(case3);
}


int main()
{

    police_system people;
    add_initial_data(people);
    int choice1,choice2,choice3,choice4,choice5,ids;
    char c;
    cout<<"Enter Your Name: ";
    string s;
    getline(cin,s);
    cout<<endl<<"**********WELCOME MR/MRS "<<s<<"**********"
    <<endl;
    cout<<endl;
    string pass{"tutturu"};
    string entry (7,'a');
    cout<<"For Entering into the World of Police Department System you have to enter PASSWORD"<<endl;
    cout<<"Enter Password: ";
    for(int i=0;i<7;i++)
    {
        entry.at(i)=getch();
        cout<<"*";
    }
    if(entry==pass)
    {
    do
    {
        cout<<endl;
        cout<<"**********WELCOME TO DEPARTAMENTO DE POLICIA**********"<<endl;
        cout<<endl<<endl;
        cout<<"Which Option do you want to select?"<<endl<<endl;
        cout<<"1.Show the Information of the Police Department"<<endl;
        cout<<"2.Search the Information of the Police Department"<<endl;
        cout<<"3.Add the Information of the Police Department"<<endl;
        cout<<"4.Remove the Information of the Police Department"<<endl;
        cout<<"5.Promote a Police in the Department"<<endl;
        cout<<"6.Quit"<<endl<<endl;
        cout<<"Enter the option:";
        cin>>choice1;
        switch (choice1)
        {
        case 1:
        {
            cout<<endl;
            cout<<"**********WELCOME TO THE INFORMATION SHOWING SECTION**********"<<endl;
            cout<<endl<<endl;
            cout<<"1.Show the Information of Police"<<endl;
            cout<<"2.Show the Information of Criminal"<<endl;
            cout<<"3.Show the Information of Staff"<<endl;
            cout<<"4.Show the Information of Case Desk"<<endl;
            cout<<"5.Show the Information of Witness"<<endl<<endl;
            cout<<"Enter the option:";
            cin>>choice2;
            switch (choice2)
            {
            case 1:
                people.show_officer_data();
                break;
            case 2:
                people.show_criminal_data();
                break;
            case 3:
                people.show_staff_data();
                break;
            case 4:
                people.show_police_case_data();
                break;
            case 5:
                people.show_witness_data();
                break;
            default:
                cout<<"Invalid input ! Please try again"<<endl;
                break;
            }
            break;
        }
        case 2:
        {
            cout<<endl;
            cout<<"**********WELCOME TO INFORMATION SEARCHING SECTION**********"<<endl;
            cout<<endl<<endl;
            cout<<"1.Search the Information of Police"<<endl;
            cout<<"2.Search the Information of Criminal"<<endl;
            cout<<"3.Search the Information of Staff"<<endl;
            cout<<"4.Search the Information of Case Desk"<<endl;
            cout<<"5.Search the Information of Witness" << endl<<endl;
            cout<<"Enter the option:";
            cin>>choice3;
            switch (choice3)
            {
            case 1:
                people.search_officer();
                break;
            case 2:
                people.search_criminal();
                break;
            case 3:
                people.search_staff();
                break;
            case 4:
                people.search_police_case();
                break;
            case 5:
                people.search_witness_data();
                break;
            default:
                cout<<"Invalid input ! Please try again"<<endl;
                break;
            }
            break;
        }
        case 3:
        {
            cout<<endl;
            cout<<"**********WELCOME TO THE INFORMATION ADDING SECTION**********"<<endl;
            cout<<endl<<endl;
            cout<<"1.Add the Information of Officer"<<endl;
            cout<<"2.Add the Information of Criminal"<<endl;
            cout<<"3.Add the Information of Staff"<<endl;
            cout<<"4.Add the Information of Case Desk"<<endl;
            cout<<"5.Add the Information of Witness" <<endl<<endl;
            cout<<"Enter the option:";
            cin>>choice4;
            switch (choice4)
            {
            case 1:
                people.add_officer();
                break;
            case 2:
                people.add_criminal();
                break;
            case 3:
                people.add_staff();
                break;
            case 4:
                people.add_police_case();
                break;
            case 5:
                people.add_witness();
                break;
            default:
                cout<<"Invalid input ! Please try again"<<endl;
                break;
            }
            break;
        }
        case 4:
        {
            cout<<"**********WELCOME TO THE INFORMATION REMOVING SECTION**********"<<endl;
            cout<<endl<<endl;
            cout<<"1.Remove the Information of Officer"<<endl;
            cout<<"2.Remove the Information of Criminal"<<endl;
            cout<<"3.Remove the Information of Staff"<<endl<<endl;
            cout<<"Enter the option:";
            cin>>choice5;
            switch (choice5)
            {
            case 1:
                people.remove_officer();
                break;
            case 2:
                people.remove_criminal();
                break;
            case 3:
                people.remove_staff();
                break;
            default:
                cout<<"Invalid input ! Please try again"<<endl;
                break;
            }
            break;
        }
        case 5:
        {
            cout<<endl;
            cout<<"**********WELCOME TO THE PROMOTION SECTION**********"
            <<endl;
            cout<<endl<<endl;
            cout<<"Enter the ID of Officer you want to promote: ";
            cin>>ids;
            promote_officer(people,ids);
            break;
        }
        case 6:
        {
            cout<< "Thank You for visiting us :)"<<endl;
            break;
        }
        }
        if(choice1!=6)
        {
            cout<<endl;
            cout<<"Wanna Continue?(Y/N): ";
            cin>>c;
        }
    } while (c=='Y' || c=='y');
    }
    else
    {
        cout<<endl<<"HEY, YOU ARE NOT REAL MR/MRS "<<s<<"!!!"<<endl;
    }
    return 0;
}
