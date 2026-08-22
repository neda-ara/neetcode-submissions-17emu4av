class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.empty()) {
            return "";
        }

        vector<int> sizes;
        string combinedStr;

        for(const string& str : strs) {
            sizes.push_back(str.length());
            combinedStr.append(str);
        }

        string encoded;
        for(int sz : sizes) {
            encoded.append(to_string(sz));
            encoded.push_back(',');
        }
        encoded.push_back('#');
        encoded.append(combinedStr);
        return encoded;
    }

    vector<string> decode(string s) {
        if(s.empty()) {
            return {};
        }

        vector<int> sizes;
        vector<string> decoded;

        int i=0;

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
            decoded.push_back(s.substr(i, sz));
            i += sz;
        }

        return decoded;
    }
};
