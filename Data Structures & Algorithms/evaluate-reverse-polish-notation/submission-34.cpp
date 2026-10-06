class DoublyLinkedlist {
public:
    string val;
    DoublyLinkedlist* next;
    DoublyLinkedlist* prev;

    DoublyLinkedlist(string val, DoublyLinkedlist* prev = nullptr, DoublyLinkedlist* next = nullptr) {
        this->val = val;
        this->prev = prev;
        this->next = next;
    }
};

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_set<string> ops{"+","-","*","/"};

        if(tokens.size() == 1) {
            return stoi(tokens[0]);
        }

        DoublyLinkedlist* head = new DoublyLinkedlist(tokens[0]);
        DoublyLinkedlist* curr = head;
        for(int i=1; i<tokens.size(); i++) {
            curr->next = new DoublyLinkedlist(tokens[i],curr,nullptr);
            curr = curr->next;
        }

        int ans;

        while(head) {
            if(ops.count(head->val)) {
                int a = stoi(head->prev->prev->val); 
                int b = stoi(head->prev->val);

                ans = calc(head->val,a,b);
                head->val = to_string(ans);

                DoublyLinkedlist* prev1 = head->prev;
                DoublyLinkedlist* prev2 = head->prev->prev;
                DoublyLinkedlist* prev3 = prev2->prev ? prev2->prev : nullptr;

                delete prev1;
                delete prev2;

                if(prev3) {
                    head->prev = prev3;
                    prev3->next = head;
                } else {
                    head->prev = nullptr;
                }
            } else {
                ans = stoi(head->val);
            }

            if(head->next) {
                curr = head->next;
            }
            head = head->next;
        }
        delete curr;
        return ans;
    }

    int calc(string op, int a, int b) {
        switch(op[0]) {
            case '+' : return a + b;
            case '-' : return a - b;
            case '*' : return a * b;
            case '/' : return a / b;
            default: return 0;
        }
    }
};
