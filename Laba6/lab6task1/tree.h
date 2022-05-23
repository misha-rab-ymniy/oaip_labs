#ifndef TREE_H
#define TREE_H

#include <QString>
#include <queue>

class tree
{
private:

    struct  Node
    {
        int key;
        QString data;
        Node *left;
        Node *right;
        short height;
        Node(int key, QString data) :
            key(key), data(data),
            left(nullptr), right(nullptr),
            height(1)
        {}
    };

    Node* root;

    static void DestroyNode(Node* node) {
        if (node) {
            DestroyNode(node->left);
            DestroyNode(node->right);
            delete node;
        }
    }

    static QString inorderPrint(Node *root)
    {
        if (root == nullptr) {
           return "";
        }
        QString ans;
        ans += inorderPrint(root->left);
        ans += root->data + " ";
        ans += inorderPrint(root->right);
        return ans;
    }

    static QString preorderPrint(Node *root)
    {
        if (root == nullptr) {
           return "";
        }
        QString ans;
        ans += root->data + " ";
        ans += preorderPrint(root->left);
        ans += preorderPrint(root->right);
        return ans;
    }

    static QString postorderPrint(Node *root)
    {
        if (root == nullptr) {
           return "";
        }
        QString ans;
        ans += postorderPrint(root->left);
        ans += postorderPrint(root->right);
        ans += root->data + " ";
        return ans;
    }

    static short Height(Node* p)
    {
        return p ? p->height : 0;
    }

    static short Bfactor(Node* p)
    {
        return Height(p->right) - Height(p->left);
    }

    static void Fixheight(Node* p)
    {
        short hl = Height(p->left);
        short hr = Height(p->right);
        p->height = std::max(hl, hr) + 1;
    }

    static Node* RotateRight(Node* p)
    {
        Node* q = p->left;
        p->left = q->right;
        q->right = p;
        Fixheight(p);
        Fixheight(q);
        return q;
    }

    static Node* RotateLeft(Node* q)
    {
        Node* p = q->right;
        q->right = p->left;
        p->left = q;
        Fixheight(q);
        Fixheight(p);
        return p;
    }

    static Node* Balance(Node* p)
    {
        Fixheight(p);
        if (Bfactor(p) == 2) {
            if (Bfactor(p->right) < 0)
                p->right = RotateRight(p->right);
            return RotateLeft(p);
        }
        if (Bfactor(p) == -2) {
            if (Bfactor(p->left) > 0)
                p->left = RotateLeft(p->left);
            return RotateRight(p);
        }
        return p;
    }

    static Node* insert(Node* p, int key, QString data)
    {
        if (!p) return new Node(key, data);
        if (key < p->key)
            p->left = insert(p->left, key, data);
        else
            p->right = insert(p->right, key, data);
        return Balance(p);
    }

    static Node* FindMin(Node* p)
    {
        return p->left ? FindMin(p->left) : p;
    }

    static Node* RemoveMin(Node* p)
    {
        if (p->left == 0)
            return p->right;
        p->left = RemoveMin(p->left);
        return Balance(p);
    }

    static Node* erase(Node* cur, int key)
    {
        if (!cur) return 0;
        if (key < cur->key)
            cur->left = erase(cur->left,key);
        else if (key > cur->key)
            cur->right = erase(cur->right,key);
        else {
            Node* q = cur->left;
            Node* r = cur->right;
            delete cur;
            if( !r ) return q;
            Node* min = FindMin(r);
            min->right = RemoveMin(r);
            min->left = q;
            return Balance(min);
        }
        return Balance(cur);
    }
public:
    tree() :
        root(nullptr){}

    void insert(int key, QString data) {
        root = insert(root, key, data);
    }

    QString search(int key){
        Node* cur = root;
        while (cur) {
            if (key < cur->key) {
                cur = cur->left;
            }
            else if (key > cur->key) {
                cur = cur->right;
            }
            else {
                return cur->data;
            }
        }
        return "Not find";
    }

    void erase(int key){
        root = erase(root, key);
    }

    QString preorderPrint()
    {
        return preorderPrint(root);
    }

    QString inorderPrint()
    {
        return inorderPrint(root);
    }

    QString postorderPrint()
    {
        return postorderPrint(root);
    }

    QString heightCal(){
        Node* node = root;
        if (node == nullptr) {
            return "tree is empty";
        }
        QString ans;
        std::queue<std::pair<Node*, int>> q;
        q.push(std::make_pair(node, 0));
        int a = 0;
        int c = 0;
        while(!q.empty()){
            Node* v = q.front().first;
            int h = q.front().second;
            q.pop();
            if (h == a){
                c++;
            }
            else {
                ans += "Число узлов на глубине " + QString::number(a) + " равна " + QString::number(c) + "\n";
                a = h;
                c = 1;
            }
            if (v->left)
                q.push(std::make_pair(v->left, h + 1));
            if (v->right)
                q.push(std::make_pair(v->right, h + 1));
        }
        ans += "Число узлов на глубине " + QString::number(a) + " равна " + QString::number(c) + "\n";
        return ans;
    }

};
#endif // TREE_H
