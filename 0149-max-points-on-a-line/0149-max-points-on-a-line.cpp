class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        vector<vector<double>> temp;
        vector<double> smpl;
        for(int i=0;i<points.size();i++){
            smpl.clear();
            for(int j=0;j<points.size();j++){
                double a=999;
                if((points[i][0]-points[j][0])!=0){
                    a=((double)(points[i][1]-points[j][1]))/((double)(points[i][0]-points[j][0]));
                }
                
                smpl.push_back(a);
                if(i==j) smpl.pop_back();
            }
            temp.push_back(smpl);
            
        }
        // cout<<temp.size();
        int maxi=0,max=0;
        for (int i = 0; i < temp.size(); i++) {
            max=0;
            map<double,int> m;
            for (int j = 0; j < temp[i].size(); j++){
             // cout << temp[i][j] << " ";
                
                
                m[temp[i][j]]++;
            }
            for(auto i:m){
                // cout<<i.first<<":"<<i.second;
                // cout<<endl;
                if(i.second>max) max=i.second;
            }
            // cout<<max<<",";
            if(max>maxi){
                maxi=max;
            }
            // cout << endl;
        }
         return maxi+1;
        // return 9;
    }
};