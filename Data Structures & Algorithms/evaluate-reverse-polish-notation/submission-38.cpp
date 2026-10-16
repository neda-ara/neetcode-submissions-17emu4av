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
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.size() == 1) {
            return stoi(tokens[0]);
        }

        unordered_set<string> ops = {"+", "-", "*", "/"};

        DoublyLinkedList* head = new DoublyLinkedList(tokens[0]);
        DoublyLinkedList* curr = head;

        for(int i=1; i<tokens.size(); i++) {
            curr->next = new DoublyLinkedList(tokens[i], curr, nullptr);
            curr = curr->next;
        }

        int ans;
        while(head) {
            if(ops.count(head->val)) {
                int a = stoi(head->prev->prev->val);
                int b = stoi(head->prev->val);
                
                ans = calc(head->val,a,b);
                head -> val = to_string(ans);

                DoublyLinkedList* prev1 = head->prev;
                DoublyLinkedList* prev2 = prev1->prev;
                DoublyLinkedList* prev3 = prev2->prev ? prev2->prev : nullptr;

                delete prev1;
                delete prev2;

                if(prev3) {
                    head -> prev = prev3;
                    prev3 -> next = head;
                } else {
                    head -> prev = nullptr;
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

private:
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
