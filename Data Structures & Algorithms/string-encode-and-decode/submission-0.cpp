class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.empty()) return "";

        string encodedStr;

        vector<int> sizes;
        sizes.reserve(strs.size());

        for(const string& s : strs) {
            sizes.push_back(s.size());
        }

        for(int sz : sizes) {
            encodedStr += to_string(sz) + ',';
        }
        encodedStr += "#";

        for(const string& s : strs) {
            encodedStr += s;
        }

        return encodedStr;
    }

    vector<string> decode(string s) {
        if(s.empty()) return {};
        
        vector<int> sizes;
        vector<string> decodedStrArr;

        int i=0;

        while(s[i] != '#') {
            string curr = "";

            while(s[i] != ',') {
                curr += s[i];
                i++;
            }
            sizes.push_back(stoi(curr));
            i++; // skip over comma(,)
        }
        i++; // skip over #

        for(int sz:sizes) {
            decodedStrArr.push_back(s.substr(i,sz));
            i+=sz;
        }

        return decodedStrArr;
    }
};
