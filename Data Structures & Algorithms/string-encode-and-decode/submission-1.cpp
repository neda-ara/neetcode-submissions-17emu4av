class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.empty()) {
            return "";
        }
        vector<int> sizes;
        for(const string& str : strs) {
            sizes.push_back(str.length());
        }

        string res = "";
        for(int sz : sizes) {
            res.append(to_string(sz));
            res.push_back(',');
        }
        res.push_back('#');

        for(const string& str : strs) {
            res.append(str);
        }
        return res;
    }

    vector<string> decode(string s) {
        if(s.empty()) {
            return {};
        }
        vector<int> sizes;
        vector<string> strs;

        int i = 0;
        while(s[i] != '#') {
            int j = i;
            while(s[j] != ',') {
                j++;
            }
            sizes.push_back(stoi(s.substr(i,j-i)));
            i = j+1;
        }
        i++;
        for(int sz : sizes) {
            strs.push_back(s.substr(i,sz));
            i += sz;
        }
        return strs;
    }
};
