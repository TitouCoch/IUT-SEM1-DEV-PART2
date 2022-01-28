#include <iostream>
using namespace std;

void incrementerDe1 (int& valeur);

int main (void)
{
    int val = 1;
    cout <<"Valeur avant incrementer :"<<val<<endl;
    incrementerDe1(val);
    cout <<"Valeur apres incrementer :"<<val<<endl;
    incrementerDe1(val);
    cout <<"Valeur apres incrementer :"<<val<<endl;
    incrementerDe1(val);
    cout <<"Valeur apres incrementer :"<<val<<endl;
    incrementerDe1(val);
    cout <<"Valeur apres incrementer :"<<val<<endl;
    return 0;
}
void incrementerDe1(int& valeur)
{
    valeur++;
}