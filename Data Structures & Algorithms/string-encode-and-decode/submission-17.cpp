class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.empty()) {
            return "";
        }

        string combinedStr;
        vector<int> sizes;

        for(const string& str : strs) {
            combinedStr += str;
            sizes.push_back(str.length());
        }

        string encoded;
        for(int sz : sizes) {
            encoded.append(to_string(sz));
            encoded.push_back(',');
        }
        encoded.push_back('#');
        return encoded + combinedStr;
    }

    vector<string> decode(string s) {
        if(s.empty()) {
            return {};
        }

        vector<string> decoded;

        vector<int> sizes;
        int i = 0;
        while(s[i] != '#') {
            int j = i;
            while(s[j] != ',') {
                j++;
            }
            int len = stoi(s.substr(i, j-i));
            sizes.push_back(len);
            i = j + 1;
        }
        i++;

        for(int sz : sizes) {
            string str = s.substr(i, sz);
            decoded.push_back(str);
            i += sz;
        }

        return decoded;
    }
};
