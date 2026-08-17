class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;
        for(const string& str : strs) {
            encoded.append(to_string(str.length()));
            encoded.push_back('#');
            encoded.append(str);
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;

        int i=0;
        while(i < s.size()) {
            int j = i;
            while(s[j] != '#') {
                j++;
            }
            int len = stoi(s.substr(i,j-i));
            i = j+1;
            j = i+len;
            decoded.push_back(s.substr(i,len));
            i = j;
        }
        return decoded;
    }
};
