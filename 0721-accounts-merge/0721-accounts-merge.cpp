class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
      
      
        class Disjointset{
            vector<int> parent , rank;
            public:

            Disjointset(int n){
                parent.resize(n+1);
                rank.resize(n+1 , 0);

                for(int i =0;i<=n;i++){
                    parent[i] = i;
                }
            }

            int ulparent(int node){
                  if(node == parent[node])
                  return node;

                  return parent[node] = ulparent(parent[node]);
            }

            void unionbyrank(int u , int v){
                int pu = ulparent(u);
                int pv = ulparent(v);

               if(pu == pv)
               return;


               if(rank[pu] > rank[pv])
               parent[pv] = pu;

              else if(rank[pv] > rank[pu])
               parent[pu] = pv;

               else{
                parent[pu] = pv;
                rank[pv]++;
               }
            }


        };
         

         //step 1 - creating a mapping of a no(name) with emails and if email already exists in the map attach to previous one

         int n = accounts.size();
        Disjointset ds(n);
        sort(accounts.begin(), accounts.end());
        unordered_map<string, int> mapMailNode;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if (mapMailNode.find(mail) == mapMailNode.end()) {
                    mapMailNode[mail] = i;     //if map doesnt have initiliase a new one
                }
                else {
                    ds.unionbyrank(i, mapMailNode[mail]);   //if already present attach to existing one
                }
            }
        }
  

          //step 2 - connecting to the ultimate parent
         vector<string> mergedMail[n];
        for (auto it : mapMailNode) {
            string mail = it.first;
            int node = ds.ulparent(it.second);
            mergedMail[node].push_back(mail);
        }


         //step 3 
        vector<vector<string>> ans;

        for (int i = 0; i < n; i++) {
            if (mergedMail[i].size() == 0) continue;     //if empty continue

            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto it : mergedMail[i]) {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        sort(ans.begin(), ans.end());
        return ans;
    

    }
};