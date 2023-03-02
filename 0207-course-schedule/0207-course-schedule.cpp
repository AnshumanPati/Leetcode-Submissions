class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prereqs) {

        if(prereqs.size() == 0)
            return true;
        
        int n = numCourses;

        vector<int> visited(n,0);

        vector<int> adj[n];
        vector<int> indegree(n,0);

        for(auto it : prereqs){
            int u = it[0];
            int v = it[1];
            adj[v].push_back(u);
            indegree[u]++;
        }

        queue<int> q;
        int start = -1;

        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
                start = 1;
            }
        }

        if(start == -1)
            return false;

        vector<int> crs;
        
        visited[start] = 1;

        if(q.size() == 0)
            return false;

        while(!q.empty()){
            int it = q.front();
            q.pop();
            crs.push_back(q.front());

            for(auto nbr : adj[it]){
                indegree[nbr]--;
                if(indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }
        return crs.size() == n;
    }
};