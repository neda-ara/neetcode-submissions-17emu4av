class Solution {
public:

    string encode(vector<string>& strs) {
        int n = strs.size();
        if(n == 0) {
            return "";
        }

        vector<int> sizes;

        string allStrs;
        for(const string& str : strs) {
            sizes.push_back(str.length());
            allStrs.append(str);
        }
        
        string encoded = "";
        for(int sz : sizes) {
            encoded.append(to_string(sz));
            encoded.push_back(',');
        }
        encoded.push_back('#');
        encoded.append(allStrs);
        return encoded;
    }

    vector<string> decode(string s) {
        if(s.empty()) {
            return {};
        }

        vector<string> decoded;
        vector<int> sizes;

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

        for(int sz: sizes) {
            decoded.push_back(s.substr(i,sz));
            i += sz;
        }

        return decoded;
    }
};
