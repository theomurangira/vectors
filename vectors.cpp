// vectors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<string>
#include<numeric>
#include<functional>
using namespace std;

int main()
{
    vector<int>v1;//empty vector
    srand(time(0));
    for (int i = 0; i < 10; ++i)
        v1.push_back(rand() % 20);
    vector<int> v2(v1);//copy constructor called
    vector<string>names{ "Ange","Claude","Celestin","Josiane" };
    /*Using iterators*/
    for (auto iter = v1.begin(); iter != v1.end(); ++iter)
        cout << *iter << "\t";
    cout << "\n";
    /* Using range for loop*/
    for (auto s : names)
        cout << "Hello " << s << "\n";
    for (auto& i : v2)
        cout << i + 4 << "\t";
    cout << "\n";
    /*using indexing*/
    int total = 0;
    for (size_t i = 0; i < v2.size(); ++i)
        total += v2[i];
    cout << "Total =" << total << "\n";
    /* using algorithms with iterators*/
    cout << "Total= " << accumulate(v2.begin(), v2.end(), 0) << "\n";

    auto dashfold = [](string a, int b) {return
        move(a) + "-" + to_string(b); };
    string s = accumulate(next(v1.begin()), v1.end(), to_string(v1[0]), dashfold);
    cout << s <<"\n";
    string rs = accumulate(next(v1.rbegin()), v1.rend(), to_string(v1.back()), dashfold);
    cout << rs << "\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
