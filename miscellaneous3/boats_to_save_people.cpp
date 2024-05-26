class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int i=0,k=people.size()-1;
        int c=0;
        while(i<=k)
        {
            if(i!=k && (people[i]+people[k])<=limit) i++;
            else if(i!=k && (people[i]+people[k])>limit) i=i;
            else i++;
            c++;
            k--;
        }
        return c;

        
    }
};