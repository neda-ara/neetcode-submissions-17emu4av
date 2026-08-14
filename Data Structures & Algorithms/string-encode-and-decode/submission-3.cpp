class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.empty()) {
            return "";
        }

        vector<int> sizes;
        string res = "";

        for(const string& str : strs) {
            sizes.push_back(str.length());
        }

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

        int i = 0;
        vector<int> sizes;
        vector<string> res;

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
            res.push_back(s.substr(i,sz));
            i += sz;
        }
        return res;
    }
};
