class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.empty()) {
            return "";
        }
        string combined;
        vector<int> sizes;

        for(string& str : strs) {
            combined += str;
            sizes.push_back(str.length());
        }

        string encoded;
        for(int& sz : sizes) {
            encoded.append(to_string(sz));
            encoded.push_back(',');
        }
        encoded += '#';
        encoded += combined;
        return encoded;
    }

    vector<string> decode(string s) {
        if(s.empty()) {
            return {};
        }
        vector<int> sizes;
        
        int i=0;
        while(s[i] != '#') {
            int j=i;
            while(s[j] != ',') {
                j++;
            }
            int len = stoi(s.substr(i,j-i));
            sizes.push_back(len);
            i = j+1;
        }
        i++;

        vector<string> decoded;
        for(int& sz : sizes) {
            decoded.push_back(s.substr(i,sz));
            i += sz;
        }

        return decoded;
    }
};
