// Oscar Cabrera
// deque

#include <iostream>
#include <fstream>
#include <deque>
using namespace std;

void add(deque<string> &, string);
void serve(deque<string> &);
void print(deque<string>);

int main() {
    string name;
    ifstream fin("data.txt");
    deque<string> line;
    cout << "Format: name added (deque front name, deque back name)\n\n";
    
    while(getline(fin, name))
        add(line, name);
    serve(line);
    serve(line);
    add(line, "Puff");
    add(line, "Pudd");
    while (line.size() != 0)
        serve(line);
    add(line, "Pugg");
    
    return 0;
}

void print(deque<string> d) {
    for (auto val : d) {
        cout << val << " ";
    }
    cout << endl;
}

void add(deque<string> &d, string n) {
    d.push_back(n);
    cout << "Added: " << n << " (" << d.front() << ", " << d.back() << ")\n";
    cout << "Queue: ";
    print(d);
    cout << endl;
}

void serve(deque<string> &d) {
    cout << "Served: " << d.front();
    d.pop_front();
    if (d.size() != 0) {
        cout << " (Front: " << d.front() << ", back: " << d.back() << ")\n";
        cout << "Queue: ";
        print(d);
        cout << endl;
    }
    else
        cout << " Queue is now empty.\n";
    
}
