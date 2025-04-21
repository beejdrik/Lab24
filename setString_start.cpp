#include<iostream>
#include<set>
#include<string>
using std::cout;
using std::endl;
using std::string;
using std::set;
using std::pair;
int main() {
    set<string> setOfNames;
    set<string>::iterator it;
    // Lets insert four names
    setOfNames.insert("John");
    setOfNames.insert("Jane");
    setOfNames.insert("Nick");
    setOfNames.insert("Steve");
    string mynames[]={"Adam", "Sue"};

    //insert the values in mynames array to your set.
    setOfNames.insert (mynames, mynames+2);

    //Try to insert Adam again, and using the return value which is a pair to
    pair<set<string>::iterator, bool> ret;
    ret = setOfNames.insert("Adam");

    if (ret.second == false) {
        cout << "Adam already exists" << endl;}
    else {cout << "Adam was inserted successfully" << endl;}


    //Use iterator to print current values.
    cout << "setOfNames contains the following: " << endl;
    for (it = setOfNames.begin(); it != setOfNames.end(); it++) {
        cout << ' ' << *it << endl;
    }

    // Search for element in set using find member function
    it = setOfNames.find ("John");
    if(it != setOfNames.end())
        cout<<"'John' found"<<endl;
    else
        cout<<"'John' not found"<<endl;

    // Use the example above to perform a search for another name such as "adam"
    it = setOfNames.find("adam");
    if(it != setOfNames.end())
        cout<<"'adam' found"<<endl;
    else
        cout<<"'adam' not found"<<endl;


    setOfNames.erase ("Adam");

    return 0;
}
