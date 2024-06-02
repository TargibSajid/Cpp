#include <iostream>

using namespace std;

class Stack {
private:
    int* stackarr;
    int MaxSize;
    int top;

public:

    Stack(int Size) : MaxSize(Size), top(-1) {
        stackarr = new int[MaxSize];
    }


    ~Stack() {
        delete[] stackarr;
    }

    bool is_Full() {
        return (top == MaxSize - 1);
    }

    bool is_Empty() {
        return (top == -1);
    }

    void push(int a) {
        if (is_Full()) {
            cout << "Stack Overflow: There is no more space in the stack." << endl;
        } else {
            stackarr[++top] = a;
        }
    }

    void pop() {
        if (is_Empty()) {
            cout << "Stack Underflow: The stack is empty." << endl;
        } else {
            cout << stackarr[top--] << endl;
        }
    }

    void show() {
        if (is_Empty()) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Stack elements:" << endl;
            for (int i = 0; i <= top; i++) {
                cout << stackarr[i] << endl;
            }
        }
    }
};

int main() {

    Stack dynamicStack(5);
    dynamicStack.push(1);
    dynamicStack.push(2);
    dynamicStack.push(3);
    dynamicStack.push(4);
    dynamicStack.push(5);
    dynamicStack.push(6);
    dynamicStack.pop();
    dynamicStack.pop();
    dynamicStack.pop();
    dynamicStack.pop();
    dynamicStack.pop();
    dynamicStack.pop();
    return 0;
}
