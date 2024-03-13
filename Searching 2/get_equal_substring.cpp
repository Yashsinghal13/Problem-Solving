class Solution {
public:
    int equalSubstring(string s, string t, int maxcost) {
        int i=0,j=0;
        int maxlen=0,len=0;
        while(j<s.size())
        {
            if(maxcost>=abs(s[j]-t[j]))
            {
                maxcost-=abs(s[j]-t[j]);
                j++;
            }
            else
            {
                maxlen=max(maxlen,j-i);
                if(j-i==0)
                {
                    j++;
                    i++;
                }
                else
                {
                    while(i<j && maxcost<abs(s[j]-t[j]))
                    {
                        maxcost+=abs(s[i]-t[i]);
                        i++;
                    }
                }
            }
        }
        maxlen=max(maxlen,j-i);
        return maxlen;
    }
};