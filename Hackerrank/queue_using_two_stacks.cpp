#include <iostream>
#include <stack>

class Queue{
    private:
        std::stack<int> enq; // Input stack
        std::stack<int> deq; // Output stack

        // Helper function to move the elements in one stack to another
        void MoveToDeq(){
            while (!enq.empty()){
                deq.push(enq.top());
                enq.pop();
            }
        }

    public:
        Queue():enq(), deq(){}
        ~Queue(){};

        // Push elements into the input stack
        void Enqueue(int elem){
            enq.push(elem);
        }

        // Pop elements from the output stack
        void Dequeue(){
            // Bring elements from input stack if there's nothing to pop
            if (deq.empty()){
                MoveToDeq();
            }

            deq.pop();
        }

        int Front(){
            // Bring elements from input stack if there's nothing to pop
            if (deq.empty()){
                MoveToDeq();
            }

            return deq.top();
        }
};


int main() {
    int Q, type, x;
    Queue q;
    std::cin >> Q;

    for (int i=0; i<Q; ++i){
        std::cin >> type;

        // Execute a query depending on the input type
        switch(type){
            case 1:
                std::cin >> x;
                q.Enqueue(x);
                break;
            case 2:
                q.Dequeue();
                break;
            case 3:
                std::cout << q.Front() << std::endl;
        }
    }
}
