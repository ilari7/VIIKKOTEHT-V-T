#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


class Student
{
private:
    string name;
    int Age;

public:
    Student(string n, int A)
    {
        name=n;
        Age=A;
    }

    void setAge(int A)
    {
        Age=A;
    }
    void setName(string n)
        {
        name=n;
        }
    string getName()
    {
        return name;
    }
    int getAge()
    {
        return Age;
    }
    void printStudentInfo()
    {
        cout << "nimi: " << name << "\n" << "ika : " << Age << "\n" << endl;
    }
};


int main ()
{
    int selection =0;
    vector<Student>studentList;

    do
    {
        cout<<endl;
        cout<<"Select"<<endl;
        cout<<"Add students = 0"<<endl;
        cout<<"Print all students = 1"<<endl;
        cout<<"Sort and print students according to Name = 2"<<endl;
        cout<<"Sort and print students according to Age = 3"<<endl;
        cout<<"Find and print student = 4"<<endl;
        cin>>selection;


        switch(selection)
        {
        case 0:
        {
            // Kysy käyttäjältä uuden opiskelijan nimi ja ikä
            // Lisää uusi student StudentList vektoriin.
            cout << "anna uuden opiskelijan nimi: " << endl;
            string name;
            cin >> name;
            cout << "anna uuden opiskelijan ika: " << endl;
            int Age;
            cin >> Age;
            studentList.emplace_back(name, Age);


            break;
        }
        case 1:
        {
            // Tulosta StudentList vektorin kaikkien opiskelijoiden
            // nimet.
            for (auto& student : studentList)
            {
                student.printStudentInfo();
            }
            break;
        }
        case 2:
        {
            // Järjestä StudentList vektorin Student oliot nimen mukaan
            // algoritmikirjaston sort funktion avulla
            // ja tulosta printStudentInfo() funktion avulla järjestetyt
            // opiskelijat
                 sort(studentList.begin(), studentList.end(), [](Student& a, Student& b)
            {
                return a.getName() < b.getName();
            });
            break;
        }
        case 3:
            // Järjestä StudentList vektorin Student oliot iän mukaan
            // algoritmikirjaston sort funktion avulla
            // ja tulosta printStudentInfo() funktion avulla järjestetyt
            // opiskelijat
            {
                sort(studentList.begin(), studentList.end(), [](Student& a, Student& b)
                     {
                         return a.getAge() < b.getAge();
                     });
                for (auto& student : studentList)
                {
                    student.printStudentInfo();
                }
                break;
            }
        case 4:
        {
            cout << "anna opiskelijan nimi " << endl;
            string name2;
            cin >> name2;
            auto x = find_if(studentList.begin(), studentList.end(), [&name2](Student& student)
                    {
                return student.getName() == name2;
            });
            if(x != studentList.end())
            {
                x->printStudentInfo();
            }
            else
            {
                cout << "ei loydy " << endl;
            }
            // Kysy käyttäjältä opiskelijan nimi
            // Etsi studentListan opiskelijoista algoritmikirjaston
            // find_if funktion avulla löytyykö käyttäjän antamaa nimeä
            // listalta. Jos löytyy, niin tulosta opiskelijan tiedot.
            break;
        }
    default:
        cout<< "Wrong selection, stopping..."<<endl;
        break;
    }
}while(selection < 5);


return 0;
}
