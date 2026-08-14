class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for(const string& str : strs) {
            res.append(to_string(str.length()));
            res.push_back('#');
            res.append(str);
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;

        while(i < s.size()) {
            int j = i;
            while(s[j] != '#') {
                j++;
            }
            
            string substr = "";
            for(int k=i; k<j; k++) {
                substr.push_back(s[k]);
            }

            int length = stoi(substr);

            i = j+1;
            j = i + length;
            res.push_back(s.substr(i,length));
            i = j;
        }
        return res;
    }
};
