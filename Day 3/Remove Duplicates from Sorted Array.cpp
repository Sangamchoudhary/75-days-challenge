class Solution {
public:
    int removeDuplicates(vector<int>& A) {
        if (A.size()==0) return 0;
        int j=0;
        for (int i=0; i<A.size(); i++)
            if (A[i]!=A[j]) A[++j]=A[i];
        return ++j;
    }
};