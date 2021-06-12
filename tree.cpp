#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:    
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right) {}
    int val;
    TreeNode *left, *right;
};

/* preorder: after reading the discussion */
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        istringstream in(data);
        return deserialize(in);
    }

private:
    void serialize(TreeNode *node, ostringstream &out)
    {
        if (!node)
            out << "# ";
        else
        {
            out << node->val << " ";
            serialize(node->left, out);
            serialize(node->right, out);
        }
    }
    TreeNode *deserialize(istringstream &in)
    {
        string s;
        in >> s;
        if (s == "#")
            return nullptr;
        else
        {
            TreeNode *node = new TreeNode(stoi(s));
            node->left = deserialize(in);
            node->right = deserialize(in);
            return node;
        }
    }
};

/* TLE Implementation (Leetcode level order representation)
class Codec
{
public:
    TreeNode *deserialize_level_order(string s)
    {
        size_t i = 0;
        while (true)
        {
            i = s.find(',', i);
            if (i == string::npos)
                break;
            s[i] = ' ';
        }

        stringstream ss(s);
        string node_str;
        ss >> node_str;
        TreeNode *ret = new TreeNode(stoi(node_str));
        deque<TreeNode *> node_q;
        node_q.push_back(ret);

        while (ss >> node_str)
        {
            TreeNode *&cur_node = node_q.front();
            if (node_str == "null")
            {
            }
            else
            {
                cur_node->left = new TreeNode(stoi(node_str));
                node_q.push_back(cur_node->left);
            }

            if (!(ss >> node_str))
                break;

            if (node_str == "null")
            {
            }
            else
            {
                cur_node->right = new TreeNode(stoi(node_str));
                node_q.push_back(cur_node->right);
            }
            node_q.pop_front();
        }

        return ret;
    }

    TreeNode *deserialize(string s)
    {
        if (s.size() == 0)
            return nullptr;
        return deserialize_level_order(s);
    }

    string serialize_level_order(TreeNode *root)
    {
        deque<TreeNode *> nodes;
        nodes.push_back(root);
        string ret;

        while (!nodes.empty())
        {
            auto node = nodes.front();
            nodes.pop_front();

            if (!node)
            {
                ret = ret + "null,";
                continue;
            }

            ret = ret + to_string(node->val) + ",";
            nodes.push_back(node->left);
            nodes.push_back(node->right);
        }
        ret.erase(ret.end() - 1);

        return ret;
    }

    string serialize(TreeNode *root)
    {
        if (!root)
            return "";
        return serialize_level_order(root);
    }
};
*/

    int main()
    {
        string s("4,-7,-3,null,null,-9,-3,9,-7,-4,null,6,null,-6,-6,null,null,0,6,5,null,9,null,null,-1,-4,null,null,null,-2");
        // cout << s[104] << endl;
        // cout << s.find(',', 104) << endl;
        Codec sol;
        TreeNode *ans = sol.deserialize(s);
        cout << sol.serialize(ans) << endl;
        return 0;
    }