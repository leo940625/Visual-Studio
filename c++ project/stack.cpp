#include <iostream>
#include <stdexcept> // �Ω� std::out_of_range

class Stack
{
private:
    int *arr;     // �Ω�s�x���|���}�C
    int capacity; // ���|���e�q
    int top;      // ���|����������

public:
    // �غc�l�A��l�ư��|
    Stack(int size)
    {
        arr = new int[size];
        capacity = size;
        top = -1; // ���|���ŮɡAtop �� -1
    }

    // �Ѻc�l�A����ʺA���t���O����
    ~Stack()
    {
        delete[] arr;
    }

    // �N�����K�[����|����
    void push(int x)
    {
        if (isFull())
        {
            throw std::overflow_error("Stack overflow");
        }
        arr[++top] = x;
    }

    // �q���|������������
    int pop()
    {
        if (isEmpty())
        {
            throw std::underflow_error("Stack underflow");
        }
        return arr[top--];
    }

    // �d�ݰ��|����������
    int peek()
    {
        if (isEmpty())
        {
            throw std::out_of_range("Stack is empty");
        }
        return arr[top];
    }

    // �ˬd���|�O�_����
    bool isEmpty()
    {
        return top == -1;
    }

    // �ˬd���|�O�_�w��
    bool isFull()
    {
        return top == capacity - 1;
    }
};

int main()
{
    Stack head(5);

    head.push(1);
    head.push(2);
    head.push(3);

    std::cout << "Top element is: " << head.peek() << std::endl;

    head.pop();
    head.pop();

    if (head.isEmpty())
    {
        std::cout << "Stack is empty." << std::endl;
    }
    else
    {
        std::cout << "Stack is not empty." << std::endl;
    }

    return 0;
}