class Solution {
public:
    int arr[26];
    
    int find(int x){
        if(arr[x]==-1) return x;
        return find(arr[x]);
    }
    
    void Union(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y) return;
        arr[max(x,y)]=min(x,y);
    }
    
    
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        memset(arr,-1,sizeof(arr));
        
        for(int i=0;i<s1.size();i++){
            Union(s1[i]-'a',s2[i]-'a');
        }
        
        for(int i=0;i<baseStr.size();i++){
            baseStr[i]=find(baseStr[i]-'a')+'a';
        }
        
        return baseStr;
    }
};