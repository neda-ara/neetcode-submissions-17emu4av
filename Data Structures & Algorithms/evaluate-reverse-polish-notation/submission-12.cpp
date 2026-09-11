class DoublyLinkedList {
    public:
        string val;
        DoublyLinkedList* next;
        DoublyLinkedList* prev;

        DoublyLinkedList(string val, 
            DoublyLinkedList* next = nullptr,
            DoublyLinkedList* prev = nullptr
        ) {
            this->val = val;
            this->next = next;
            this->prev = prev;
        }
};

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.empty()) {
            return 0;
        }
        if(tokens.size() == 1) {
            return stoi(tokens[0]);
        }
        unordered_set<string> ops = {"+", "-", "*", "/"};

        DoublyLinkedList* head = new DoublyLinkedList(tokens[0]);
        DoublyLinkedList* curr = head;

        for(int i=1; i<tokens.size(); i++) {
            curr->next = new DoublyLinkedList(tokens[i],nullptr,curr);
            curr = curr->next; 
        } 

        int ans = 0;
        head = head->next->next;
        while(head) {
            if(ops.count(head->val)) {
                int l = stoi(head->prev->prev->val);
                int r = stoi(head->prev->val);
                int res = calc(l,r,head->val);

                head->val = to_string(res);

                DoublyLinkedList* prev1 = head->prev;
                DoublyLinkedList* prev2 = head->prev->prev;
                DoublyLinkedList* prev3 = head->prev->prev->prev;
                delete prev1;
                delete prev2;

                head->prev = prev3;
                if(head->prev) {
                    head->prev->next = head;
                }
            }
            ans = stoi(head->val);
            head = head->next;
            if(!head) {
                curr = head;
            }
        }

        delete curr;
        return ans;
    }

private:
    int calc(int a, int b, string op) {
        switch(op[0]) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return a / b;
            default: return 0;
        }
    }
};
