class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        int hayLen=haystack.size(), neeLen=needle.size();
        for(int i=0; i<hayLen; i++)
        {
            if(haystack[i]==needle[0])
            {
                if((i+neeLen-1)<hayLen  && haystack.substr(i,neeLen)==needle)
                {
                    return i;
                }
            }
        }
        return -1;
    }
};