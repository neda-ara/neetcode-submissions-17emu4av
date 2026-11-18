class DoublyLinkedList {
   public:
    string val;
    DoublyLinkedList* prev;
    DoublyLinkedList* next;

    DoublyLinkedList(string v, DoublyLinkedList* prev = nullptr, DoublyLinkedList* next = nullptr)
        : val(v), prev(prev), next(next) {};
};

class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        unordered_set<string> ops{"+", "-", "*", "/"};

        if (tokens.size() == 1) {
            return stoi(tokens[0]);
        }

        DoublyLinkedList* head = new DoublyLinkedList(tokens[0], nullptr, nullptr);
        DoublyLinkedList* curr = head;

        for (int i = 1; i < tokens.size(); i++) {
            curr->next = new DoublyLinkedList(tokens[i], curr, nullptr);
            curr = curr->next;
        }

        int res = 0;

        while(head) {
            if(ops.count(head->val)) {
                DoublyLinkedList* prev1 = head->prev;
                DoublyLinkedList* prev2 = head->prev->prev;

                res = calc(stoi(prev2->val), stoi(prev1->val), head->val);
                head->val = to_string(res);

                DoublyLinkedList* prev3 = prev2->prev;
                if(prev3) {
                    head->prev = prev3;
                    prev3->next = head;
                } else {
                    head->prev = nullptr;
                }

                delete prev1;
                delete prev2;
            }
            curr = head;
            head = head->next;
        }
        
        delete curr;
        return res;
    }

    int calc(int a, int b, string op) {
        switch (op[0]) {
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '*':
                return a * b;
            case '/':
                return a / b;
            default:
                return 0;
        }
    }
};
