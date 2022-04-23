class Solution {
    unordered_map<string,string> m;
    
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        int hashSize= m.size();
        string tt= to_string(hashSize+1);
        m[tt]=longUrl;
        return "http://tinyurl.com/"+tt;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        cout<<shortUrl.substr(19);
        return m[shortUrl.substr(19)];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));