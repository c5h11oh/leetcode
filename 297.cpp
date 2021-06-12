#include <bits/stdc++.h>
using namespace std;


/**
 * Definition for a binary tree node.
 */ 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
public:
    TreeNode *deserialize_level_order(deque<string>& s)
    {
        TreeNode* ret = nullptr;
        auto a = s.front();
        if (a.size() == 0)
            return ret;
        s.pop_front();
        ret = new TreeNode(stoi(a));

        deque<TreeNode*> nodes;
        nodes.push_back(ret);
        while( !nodes.empty() ) {
            auto node = nodes.front();
            nodes.pop_front();

            // get left node
            if (s.empty()) 
                break;
            auto l_str = s.front();
            s.pop_front();
            if (l_str.size() > 0 && l_str != "null") {
                node->left = new TreeNode(stoi(l_str));
                nodes.push_back(node->left);
            }

            // right node
            if (s.empty()) 
                break;
            auto r_str = s.front();
            s.pop_front();
            if (r_str.size() > 0 && r_str != "null") {
                node->right = new TreeNode(stoi(r_str));
                nodes.push_back(node->right);
            }
        }

        return ret;
    }

    TreeNode *deserialize(string s)
    {
        if (s.size() == 0) return nullptr;
        TreeNode *root = nullptr;
        deque<string> nodes;
        while (true)
        {
            auto i = s.find(",");
            nodes.push_back((i == string::npos) ? s : s.substr(0, i));
            if (i == string::npos)
                break;
            s.erase(0, i + 1);
        }

        return deserialize_level_order(nodes);
    }

    string serialize_level_order(TreeNode* root) {
        deque<TreeNode *> nodes;
        nodes.push_back(root);
        string ret;

        while(!nodes.empty()) {
            auto node = nodes.front();
            nodes.pop_front();

            if (!node) {
                ret = ret + "null,";
                continue;
            }
                
            ret = ret + to_string(node->val) + ",";
            nodes.push_back(node->left);
            nodes.push_back(node->right);
        }
        ret.erase(ret.end()-1);

        while (ret.size() >= 5 && ret.substr(ret.size()-5) == ",null")
            ret.erase(ret.end()-5, ret.end());
        return ret;
    }
    
    string serialize(TreeNode* root) {
        if (!root)
            return "";
        return serialize_level_order(root);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

int main() {
    Codec cod;
    string in("4,-7,-3,null,null,-9,-3,9,-7,-4,null,6,null,-6,-6,null,null,0,6,5,null,9,null,null,-1,-4,null,null,null,-2");
    cout << cod.serialize(cod.deserialize(in)) << endl;
    return 0;
}