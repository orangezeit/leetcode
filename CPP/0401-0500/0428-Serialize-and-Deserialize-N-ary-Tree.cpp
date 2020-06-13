/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Codec {
public:
    wstring ws;

    void s_helper(Node* root, wstringstream& out) {
        wchar_t status = 0;
        if (root) status++;
        if (root) status += (2 * root->children.size());
        out.write(&status, sizeof(wchar_t));
        if (!root) return;
        out.write(reinterpret_cast<wchar_t*>(&(root->val)), sizeof(root->val));
        for (int i = 0; i < root->children.size(); ++i)
            s_helper(root->children[i], out);
    }

    // Encodes a tree to a single string.
    string serialize(Node* root) {
        wstringstream out;
        s_helper(root, out);
        ws = out.str();
        return "";
        //return "";
    }

    Node* helper(wstringstream& in) {
        wchar_t status;
        in.read(&status, sizeof(wchar_t));
        if (!(status % 2)) return NULL;
        Node* root = new Node();
        in.read(reinterpret_cast<wchar_t*>(&(root->val)), sizeof(root->val));
        int n = status / 2;
        root->children.resize(n);
        for (int i = 0; i < n; ++i)
            root->children[i] = helper(in);
        return root;
    }
    // Decodes your encoded data to tree.
    Node* deserialize(const string& data) {
        wstringstream in(ws);
        ws.clear();
        return helper(in);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
