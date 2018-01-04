
bool find_lca(Node * root,vector<int> &path,int a)
{
  if(!root)
    retrun false;

  path.push_back(root->val);

  if(root->val==a)
    return true;

  if(root->left && find_lca(root->left,path,a)||root->right && find_lca(root->right,path,b))
    return true;

  path.pop_back();
  return false;
}
int find_lca(Node * root,int a, int b)
{
  vector<int> path1,path2;

  if(!find_path(root,path1,a)||!find_path(root,path2,b))
    return -1;

  int i;
  for( i=0;i<path1.size() && i<path2.size();i++)
    {
      if(path1[i]!=path2[i])
        break;
    }
    return path1[i-1];
}
