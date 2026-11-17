class Solution {
    public String convert(String s, int n) {
        if(n==1) return s;
        String ans="";
        int p=2*(n-1);
        //start
        for(int i=0;i<s.length();i+=p)
        ans+=s.charAt(i);

        //middle
        for(int j=1;j<=n-2;j++)
        {
            for(int i=0;i<s.length()+p;i+=p)
            {
                if(i-j>=0 && i-j<=s.length()-1)
                ans+=s.charAt(i-j);
                if(i+j<=s.length()-1)
                ans+=s.charAt(i+j);
            }
        }

        //end
        for(int i=n-1;i<s.length();i+=p)
        ans+=s.charAt(i);
        return ans;
    }
}