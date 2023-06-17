#include <iostream>
#include <string>
using namespace std;
void print_menu() {
    cout << "Choose a function" << endl;
    cout << "1. Add number to the end of the list" << endl;
    cout << "2. Remove last number" << endl;
    cout << "3. Add number to the begining of the list " << endl;
    cout << "4. Remove first number" << endl;
    cout << "5. Add number in certain position" << endl;
    cout << "6. Remove number from certain position" << endl;
    cout << "7. Find the number on certain position" << endl;
    cout << "8. Find the position of certain number" << endl;
}

struct Node {
    public: int val;
    public: Node* next;
};

class List {
    Node* first;
    Node* last;
public: List() { first = NULL; last = NULL; }


      bool is_empty() {
          return first == nullptr;
      }

      void push_back(int elem) {
          Node* newNode = new Node();
          newNode->val = elem;
          if (is_empty()) {
              first = newNode;
              last = newNode;
              return;
          }
          last->next = newNode;
          last = newNode;
      }
      void push_front(int elem) {
          Node* newNode = new Node();
          newNode->val = elem;
          if (is_empty()) {
              first = newNode;
              last = newNode;
              return;
          }
          newNode->next = first;
          first = newNode;
      }

      void print() {
          if (is_empty()) return;
          Node* current = first;
          while (current) {
              cout << current->val << " ";
              current = current->next;
          }
          cout << endl;
      }

      void findByVal(int elem) {
          Node* current = first;
          int pos = 1;
          while (current != nullptr && current->val != elem) {
              current = current->next;
              pos++;
          }
          if (current != nullptr && current->val == elem) {
              cout << pos << endl;
          }
          else cerr << "This element does not exist" << endl;

      }
      void findByPos(int pos) {
          Node* current = first;
          for (int i = 0; current != nullptr && i < pos - 1; i++) {
              current = current->next;
          }
          if (current != nullptr) {
              cout << current->val << endl;
          }
          else cerr << "This element does not exist" << endl;
          

      }

      void remove_first() {
          if (is_empty()) return;
          Node* current = first;
          first = current->next;
          delete current;
      }

      void remove_last() {
          if (is_empty()) return;
          if (first == last) {
              remove_first();
              return;
          }
          Node* current = first;
          while (current->next != last) current = current->next;
          current->next = nullptr;
          delete last;
          last = current;
      }

      void remove(int elem) {
          if (is_empty()) return;
          if (first->val == elem) {
              remove_first();
              return;
          }
          else if (last->val == elem) {
              remove_last();
              return;
          }
          Node* previous = first;
          Node* current = first->next;
          while (current && current->val != elem) {
              current = current->next;
              previous = previous->next;
          }
          if (!current) {
              cerr << "This element does not exist" << endl;
              return;
          }
          previous->next = current->next;
          delete current;
      }
      void removeValbyPosition(int pos) {
          if (is_empty()) {
              return;
          }
          Node* current = first;
          if (pos == 1) {
              first = current->next;
              delete current;
              return;
          }
          for (int i = 1; current != nullptr && i < pos - 1; i++) {
              current = current->next;
          }
          if (current == nullptr || current->next == nullptr) {
              return;
          }
          Node* tmp = current->next;
          current->next = tmp->next;
          delete tmp;
          return;
      }
      void addNumberByPosition(int elem, int pos) {
          Node* newNode = new Node();
          newNode->val = elem;
          if (is_empty()) {
              first = newNode;
              last = newNode;
          }
          Node* current = first->next;
          Node* previous = first;

          if (pos == 1) {
              push_front(newNode->val);
              return;
          }
          for (int i = 1; current != nullptr && i < pos - 1; i++) {
              current = current->next;
              previous = previous->next;
          }
          previous->next = newNode;
          newNode->next = current;




      }


};
int input() {
    int elem = 0;
    string inputt;
    while (true) {


        try {
            cin >> inputt;
            elem = stoi(inputt);
            return elem;
        }
        catch (const exception& ex) {
            cerr << "error, try again : "<<ex.what()<<std::endl;
        }
    }



};
int main()
{
    List l;
    print_menu();
    int option = 0;
    int elem = 0, pos = 0;
    do {



        cin >> option;

        switch (option) {
        case 1:
            cout << "type a number you want to add: ";
            elem = input();
            l.push_back(elem);
            cout << "your list: ";
            l.print();
            break;

        case 2:
            l.remove_last();
            cout << "your list: ";
            l.print();
            break;

        case 3:
            cout << "type a number you want to add: ";

            elem = input();
            l.push_front(elem);
            cout << "your list: ";
            l.print();
            break;

        case 4:
            l.remove_first();
            cout << "your list: ";
            l.print();
            break;
        case 5:
            cout << "type the the number you want to add: ";
            elem = input();
            cout << "type the position of the number you want to add: ";
            pos = input();
            l.addNumberByPosition(elem, pos);
            cout << "your list: ";
            l.print();
            break;
        case 6:
            cout << "type the position of the number you want to remove: ";
            elem = input();
            l.removeValbyPosition(elem);
            cout << "your list: ";
            l.print();
            break;
        case 7:
            cout << "type the position: ";
            pos = input();
            cout << "the number on this position is: ";
            l.findByPos(pos);
            break;

        case 8:
            cout << "enter the number: ";
            elem = input();
            cout << "the position of this number is: ";
            l.findByVal(elem);
            break;

        }
    } while (option != 9);
    return 0;
}

