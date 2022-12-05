/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        stringstream ss;
        
        while(!q.empty()) {
            TreeNode* r = q.front();
            q.pop();
            if(r) ss << r->val;
            else ss << "null";
            ss << " ";
            if(!r) continue;
            
            q.push(r->left);
            q.push(r->right);
        }
        
        string s = ss.str();
        s.pop_back();
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss;
        ss.str(data);
        string s;
        vector<TreeNode*> v;
        while(ss >> s) {
            if(s.compare(",") == 0) continue;
            
            if(s.compare("null") == 0) v.push_back(nullptr);
            else v.push_back(new TreeNode(stoi(s)));
        }
        if(v.size() == 0) return nullptr;
        
        for(int i = 0, j = 1; i < v.size() && j < v.size(); i++) {
            if(!v[i]) continue;
            
            v[i]->left = v[j++];
            v[i]->right = v[j++];
        }
        
        return v[0];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));