class Solution {
public:
    string longestPalindrome(string s) {
         string str=convert_string(s);
        int c=0,r=0,LPS[2005]={0},max_len=0,center_index=0;
        int len=str.size();
        for(int i=0;i<len;i++)
        {
            int mirror=2*c-i;
            if(r>i && mirror>=0)
            {
                LPS[i]=min(r-i,LPS[mirror]);
            }
            int a=i+LPS[i]+1;
            int b=i-LPS[i]-1;
            while(a<len && b>=0 && str[a]==str[b])
            {
                a++;
                b--;
                LPS[i]++;
            }
            if(i+LPS[i]>r)
            {
                c=i;
                r=i+LPS[i];
            }
            
        }
        for(int i=0;i<str.size();i++)
        {
            if(LPS[i]>max_len)
            {
                max_len=LPS[i];
                center_index=i;
            }
        }
       return s.substr((center_index-max_len)/2,max_len);
    }
private:
    string convert_string(string s)
    {
        string str;
        str='#';
        for(int i=0;i<s.size();i++)
        {
            str=str+s[ i ]+'#';
        }
        return str;
    }
};
