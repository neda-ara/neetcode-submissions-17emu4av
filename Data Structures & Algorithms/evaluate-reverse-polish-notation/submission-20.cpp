class DoublyLinkedList {
public:
    string val;
    DoublyLinkedList* prev;
    DoublyLinkedList* next;

    DoublyLinkedList(string val, DoublyLinkedList* next  = nullptr, DoublyLinkedList* prev = nullptr) {
        this->val = val;
        this->next = next;
        this->prev = prev;
    }
};

class Solution {
    unordered_set<string> ops = {"+", "-", "/", "*"};
public:
    int evalRPN(vector<string>& tokens) {
        DoublyLinkedList* head = new DoublyLinkedList(tokens[0]);
        DoublyLinkedList* curr = head;

        for(int i=1; i<tokens.size(); i++) {
            curr->next = new DoublyLinkedList(tokens[i],nullptr,curr);
            curr = curr->next;
        }

        int ans = 0;
        while(head) {
            if(ops.count(head->val)) 
            {
                int a = stoi(head->prev->prev->val);
                int b = stoi(head->prev->val);
                head->val = to_string(calc(head->val,a,b));

                DoublyLinkedList* prev1 = head->prev;
                DoublyLinkedList* prev2 = prev1->prev;
                DoublyLinkedList* prev3 = prev2->prev;

                delete prev1;
                delete prev2;

                head->prev = prev3;
                if(head->prev) {
                    head->prev->next = head;
                }
            }
            ans = stoi(head->val);
            curr = head;
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
