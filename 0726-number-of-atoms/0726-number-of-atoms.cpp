class Solution {
public:
    int getPower(int& i,string formula){
        string powr="";int n=formula.length();
            while(i<n&&isdigit(formula[i])){
                powr+=string(1,formula[i++]);
            }
            int p=(powr.length()>0)?stoi(powr):1;
            
            return p;
    }
    string countOfAtoms(string formula) {
        map<string,int>mp;
        stack<pair<string,int>>st;
        int i=0,n=formula.length();
        string ans="";
      while(i<n){
        char ch=formula[i];
        if(ch=='('){
            st.push({string(1,ch),0});
            i++;
            }
        else if(ch>='A'&&ch<='Z'){
            string s=string(1, ch);
            i++;
            while(i<n&&islower(formula[i])){
                s+=string(1,formula[i++]);
            }
            int p=getPower(i,formula);
          
            st.push({s,p});
        }
        else if(ch==')'){
            i++;
            int p=getPower(i,formula);
            vector<pair<string,int>>vec;
            while(!st.empty()&&st.top() != make_pair(string(1,'('),0)){
                auto n=st.top();st.pop();
                n.second*=p;
                
                vec.push_back(n);
            }
            
            st.pop();
            while(!vec.empty()){
                st.push(vec.back());
                vec.pop_back();
            }
        }
        else i++;
        }
        while(!st.empty()){
             auto n=st.top();st.pop();
             mp[n.first]+=n.second;
        }
        for(auto x:mp){
            
            ans+=x.first+((x.second>1)?to_string(x.second):"");
            
        }
        return ans;
    }
};