#include <iostream>
#include <stdexcept> // 用於 std::out_of_range

class Stack
{
private:
    int *arr;     // 用於存儲堆疊的陣列
    int capacity; // 堆疊的容量
    int top;      // 堆疊頂部的索引

public:
    // 建構子，初始化堆疊
    Stack(int size)
    {
        arr = new int[size];
        capacity = size;
        top = -1; // 堆疊為空時，top 為 -1
    }

    // 解構子，釋放動態分配的記憶體
    ~Stack()
    {
        delete[] arr;
    }

    // 將元素添加到堆疊頂部
    void push(int x)
    {
        if (isFull())
        {
            throw std::overflow_error("Stack overflow");
        }
        arr[++top] = x;
    }

    // 從堆疊頂部移除元素
    int pop()
    {
        if (isEmpty())
        {
            throw std::underflow_error("Stack underflow");
        }
        return arr[top--];
    }

    // 查看堆疊頂部的元素
    int peek()
    {
        if (isEmpty())
        {
            throw std::out_of_range("Stack is empty");
        }
        return arr[top];
    }

    // 檢查堆疊是否為空
    bool isEmpty()
    {
        return top == -1;
    }

    // 檢查堆疊是否已滿
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