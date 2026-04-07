class Solution {
  public:
    vector<int> stableMarriage(vector<vector<int>> &men, vector<vector<int>> &women) {
        int n = men.size();
        
        // womenPartner[i] = the man currently engaged to woman i
        vector<int> womenPartner(n, -1);
        // menPartner[i] = the woman currently engaged to man i (for final output)
        vector<int> menPartner(n, -1);
        
        // Pre-process: rank[w][m] is how much woman w likes man m
        // Lower rank value means higher preference
        vector<vector<int>> rank(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                rank[i][women[i][j]] = j;
            }
        }
        
        // Queue of men who are currently free
        queue<int> freeMen;
        for (int i = 0; i < n; i++) freeMen.push(i);
        
        // Tracks the index of the next woman to propose to for each man
        vector<int> nextProposal(n, 0);
        
        while (!freeMen.empty()) {
            int m = freeMen.front();
            
            // Get the woman 'w' whom man 'm' prefers most and hasn't proposed to
            int w = men[m][nextProposal[m]++];
            
            if (womenPartner[w] == -1) {
                // Woman is free, they get engaged
                womenPartner[w] = m;
                menPartner[m] = w;
                freeMen.pop();
            } else {
                // Woman is already engaged, she compares her current partner with man m
                int currentM = womenPartner[w];
                
                if (rank[w][m] < rank[w][currentM]) {
                    // Woman prefers man m over currentM
                    womenPartner[w] = m;
                    menPartner[m] = w;
                    freeMen.pop();
                    
                    // The jilted man currentM becomes free again
                    freeMen.push(currentM);
                } else {
                    // Woman rejects m, he stays in the queue to propose to his next choice
                }
            }
        }
        
        return menPartner;
    }
};
