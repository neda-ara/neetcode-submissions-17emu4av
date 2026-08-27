class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.empty()) {
            return "";
        }
        string encoded;

        for(const string& str : strs) {
            encoded.append(to_string(str.length()));
            encoded.push_back('#');
            encoded.append(str);
        }

        return encoded;
    }

    vector<string> decode(string s) {
        if(s.empty()) {
            return {};
        }

        vector<string> decoded;
        int i=0;

        while(i < s.length()) {
            int j = i;
            while(s[j] != '#') {
                j++;
            }
            int len = stoi(s.substr(i, j-i));
            i=j+1;
            decoded.push_back(s.substr(i, len));
            i += len;
        }

        return decoded;
    }
};
