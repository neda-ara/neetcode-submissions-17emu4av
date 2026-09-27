class DoublyLinkedList {
public:
    string val;
    DoublyLinkedList* prev;
    DoublyLinkedList* next;

    DoublyLinkedList(string val, DoublyLinkedList* prev=nullptr, DoublyLinkedList* next = nullptr) {
        this->val = val;
        this->next = next;
        this->prev = prev;
    }
};

class Solution {
    unordered_set<string> ops = {"+", "-", "*", "/"};

public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.size() == 1) {
            return stoi(tokens[0]);
        }

        DoublyLinkedList* head = new DoublyLinkedList(tokens[0]);
        DoublyLinkedList* curr = head;

        for(int i=1; i<tokens.size(); i++) {
            curr->next = new DoublyLinkedList(tokens[i],curr,nullptr);
            curr = curr->next;
        }

        int answer;

        while(head) {
            if(ops.count(head->val)) {
                int a = stoi(head->prev->prev->val);
                int b = stoi(head->prev->val);
                answer = calc(head->val,a,b);
                head->val = to_string(answer);

                DoublyLinkedList* prev1 = head->prev;
                DoublyLinkedList* prev2 = head->prev->prev;
                DoublyLinkedList* prev3 = prev2->prev ? prev2->prev : nullptr;

                delete prev1;
                delete prev2;

                if(prev3) {
                    head->prev = prev3;
                    prev3->next = head;
                } else {
                    head->prev = nullptr;
                }
            } else {
                answer = stoi(head->val);
            }
            if(head->next) {
                curr = head->next;
            }
            head = head->next;
        }
        delete curr;
        return answer;
    }

    int calc(string op, int a, int b) {
        switch(op[0]) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return a / b;
            default: return 0;
        }
    }
};
