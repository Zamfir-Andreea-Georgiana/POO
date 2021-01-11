#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main() {
    //Stiva cu elementele de tip char
    stack<char> s;
    //Coada cu elementele de tip int
    queue<int> q;

    //Adaugare elemente in varful stivei folosind push
    s.push('a');
    s.push('b');
    s.push('c');

    //Adaugare elemente la sfarsitul cozii folosind push
    q.push(0);
    q.push(1);
    q.push(2);

    //Cat timp stiva nu este goala
    while (!s.empty()) {
        cout << s.top() << ' ';	//Afisam elementul din varful stivei
	s.pop();    //Eliminam elementul din varful stivei
    }
    cout << endl;
    //Se va afisa:
    //c b a

    //Cat timp coada nu este goala
    while (!q.empty()) {
        cout << q.front() << ' ';    //Afisam elementul de la inceputul cozii
	q.pop();    //Eliminam elementul de la inceputul cozii
    }
    //Se va afisa:
    //0 1 2

    return 0;
}
