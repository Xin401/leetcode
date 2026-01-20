struct node
{
    int val;
    node*l,*r;
    int level;
    node(int v,int l):val(v),level(l){}
};
class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        deque q{1,2,3,4,5,6,7,8,9};
        n--;
        while(n--)
        {
            int sz = q.size();
            for(int i = 0;i<sz;i++)
            {
                int l = q.front()%10;
                for(int j = 0;j<10;j++)
                {
                    if(abs(l-j)==k)
                    {
                        q.push_back(q.front()*10+j);
                    }
                }
                q.pop_front();
            }
        }
        return vector<int>(q.begin(),q.end());
    }
};