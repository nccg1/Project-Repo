#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int score;
    Student(string n, int s) : name(n), score(s) {}

    public:
    void getGrade() {
        if (score >= 50) {
            cout << name << " Pass" << endl;
        } else {
            cout << name << " Fail" << endl;
        }
    }

    ~Student() {
        cout << name << " record closed" << endl;    
    }
};
    int main() {
        Student s1("Noah", 85);
        s1.getGrade();
        return 0;
    }
