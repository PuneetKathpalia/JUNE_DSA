void topView(struct Node *root)
{
   set<int> s;
   queue<pair<Node*,int>> q;
   if(root==NULL)return ;
   q.push({root,0});
   while(!q.empty())
   {
       int size=q.size();
       while(size--)
       {
           auto a=q.front();
           q.pop();
           if(s.find(a.second)==s.end())
           {
               s.insert(a.second);
               cout<<a.first->data<<" ";
           }
          
           Node* x=a.first;
           if(x->left)
           {
               q.push({x->left,a.second-1});
           }
            if(x->right)
           {
               q.push({x->right,a.second+1});
           }
           
      
       }
       
   }
   
}