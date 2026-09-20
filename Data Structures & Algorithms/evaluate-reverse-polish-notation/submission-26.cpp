class DoublyLinkedList {
public:
    string val;
    DoublyLinkedList* next;
    DoublyLinkedList* prev;

    DoublyLinkedList(string val, DoublyLinkedList* prev = nullptr, DoublyLinkedList* next = nullptr) {
        this->val = val;
        this->next = next;
        this->prev = prev;
    }
};

class Solution {
    unordered_set<string> ops = {"+","-","*","/"};

public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        if(n == 1) {
            return stoi(tokens[0]);
        }

        DoublyLinkedList* head = new DoublyLinkedList(tokens[0]);
        DoublyLinkedList* curr = head;

        for(int i=1; i<n; i++) {
            curr->next = new DoublyLinkedList(tokens[i],curr,nullptr);
            curr = curr->next;
        }

        int ans = 0;
        while(head) {
            if(ops.count(head->val)) {
                int a = stoi(head->prev->prev->val);
                int b =stoi(head->prev->val);
                head -> val = to_string(calc(head->val,a,b));

                DoublyLinkedList* prev1 = head->prev;
                DoublyLinkedList* prev2 = prev1->prev;
                DoublyLinkedList* prev3 = prev2 ? prev2->prev : nullptr;

                if(prev3) {
                    head->prev = prev3;
                    prev3->next = head;
                } else {
                    head->prev = nullptr;
                }

                delete prev1;
                delete prev2;
            }
            if(!head->next) {
                curr = head;
            }
            ans = stoi(head->val);
            head = head->next;
        }
        delete curr;
        return ans;
    }

private:
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
