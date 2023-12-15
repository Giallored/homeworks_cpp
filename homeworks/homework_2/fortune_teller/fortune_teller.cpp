#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;


string get_end(vector<string>& endings, string& name){
    int n_end = endings.size();
    int n_name = name.size();
    int div = n_name % n_end;
    string end = endings.at(div);
    return end;
}

string get_adj(vector<string>& adjectives, string& name){
    int n_adj = adjectives.size();
    int n_name = name.size();
    int div = n_name % n_adj;
    string adj = adjectives.at(div);
    return adj;
}

int main(){
    string name,noun,adj_1,adj_2,season;

    vector<string> adjectives;

    map<string,string> nouns ={
        {"spring", "STL guru"},
        {"summer", "C++ expert"},
        {"autumn", "coding beast"},
        {"winter", "software design hero"}}; 

    vector<string> endings = {"eats UB for breakfast",
    "finds errors quicker than the compiler",
    "is not afraid of C++ error messages"};

    cout << "Welcome to the fortune teller program!\n";
    
    cout << "Please enter your name: "; 
    cin >> name; 
    
    cout << "\nPlease enter the time of year when you were born:";
    cout << "(pick from 'spring', 'summer', 'autumn', 'winter'): ";
    cin >> season;

    cout << "\nPlease enter an adjective: "; 
    cin >> adj_1; 
    adjectives.push_back(adj_1);

    cout << "\nPlease enter another adjective: "; 
    cin >> adj_2;
    adjectives.push_back(adj_2);

    auto adj = get_adj(adjectives,name);
    auto end = get_end(endings,name);

    //<NAME>, the <ADJECTIVE> <NOUN> that <ENDING>
    printf("\n\nHere is your description:\n%s, the %s %s that %s\n", name.c_str(), adj.c_str(),
                                     nouns.at(season).c_str(),end.c_str());
    return 0;
}
