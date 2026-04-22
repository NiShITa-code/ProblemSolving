class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> result;
        for(auto &q : queries){
            for(auto &d : dictionary){
                int count = 0;
                for(int i = 0; i < q.length(); i++){
                    if(q[i] != d[i]){
                        count++;
                    }
                    if(count > 2){
                        break;
                    }
                }
                if(count <= 2){
                    result.push_back(q);
                    break;
                }
            }
        }

        return result;
    }
};