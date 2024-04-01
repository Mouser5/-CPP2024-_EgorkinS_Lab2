#include <iostream>
#include <vector>
#include <string>
#include "Header.h"
#include <ctime>
using namespace std;

class Student {
private:
    string name;
    char mark;
    vector <double> ans;
public:
    Student(const string _name,const int number) {
        name = _name;
        Get_Mark(mark);
        Get_ans(ans,mark, number);
    }
    void Get_Mark( char& mark  ) {
        srand(time(0));
        int score = rand() % (3) + 3;
        if (score == 3)
            mark='C';
        if (score == 4)
            mark='B';
        else
            mark='A';
    }
    void Get_ans(vector <double> & ans,const char mark, const int number) {
        
        if (mark == 'A') {
            FindRoots(ans, number);
        }
        if (mark == 'C') {
            ans[0] = 0.0;
        }
        if (mark == 'B') {
            int chance = rand() % (20) + 1;
            if (chance <= 11)
                FindRoots(ans, number);
            else
                ans[0] = 0.0;
        }
    }
    void PrintResult(const int number) {
        cout << "№ -" << number<< endl;
        cout << name;
        if (ans[0] == NULL) {
            cout << "There are no roots.";
        }
        else
            cout << ans[0];
        if (ans[1] != NULL) {
            cout << ans[1];
        }
    }
};

int main()
{
    //номер уравнения - number
    // Фамилия - name
    // Ответ - ans
    string name;
    int number;
    cin >> name >> number;
    Student* a = new Student(name,number);
    a->PrintResult(number);
}

