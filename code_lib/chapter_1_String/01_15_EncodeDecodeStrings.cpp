

//TODO
class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res; 
        // vector<string> res;
        for(int i = 0; i < strs.size(); i++) {
            int len = strs[i].size();
            char strLen[20];
            sprintf(strLen, "%08d", len);
            res.append(strLen);
            res.append(strs[i]);
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        if(s.size() == 0) {
            return {};
        }
        int strLen;
        int count = 0;
        char buf[8];
        string tmp;
        vector<string> res;
        for(int i = 0; i < s.size(); i++) {
            count = 0;
            tmp.clear();
            for(int j = i; j < i + 8; j++) {
                buf[count++] = res[i][j];
            }
            strLen = std::atoi(buf);
            int start = i + 8;
            int end = start + strLen;
            for(int k = start; k < end; k++) {
                tmp.push_back(res[i][k]);
            }
            res.push_back(tmp);
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));