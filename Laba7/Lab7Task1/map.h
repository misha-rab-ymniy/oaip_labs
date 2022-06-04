#ifndef MAP_H
#define MAP_H
#include "pair.h"

template<class KeyType, class ValueType>
class map
{
private:

    struct  TreeNode
    {
        pair<KeyType, ValueType> kv;
        TreeNode *left;
        TreeNode *right;
        TreeNode *prev;
        short height;

        TreeNode(KeyType key, ValueType value, TreeNode* prev = nullptr) :
            prev(prev),
            kv(key, value),
            left(nullptr), right(nullptr),
            height(1)
        {}
    };

    TreeNode* root;
    int _size;
    static void DestroyNode(TreeNode* node) {
            if (node) {
                DestroyNode(node->left);
                DestroyNode(node->right);
                delete node;
            }
    }

    static short Height(TreeNode* p)
    {
        return p ? p->height : 0;
    }

    static short Bfactor(TreeNode* p)
    {
        return Height(p->right) - Height(p->left);
    }

    static void Fixheight(TreeNode* p)
    {
        short hl = Height(p->left);
        short hr = Height(p->right);
        p->height = (hl > hr ? hl : hr) + 1;
    }

    static TreeNode* RotateRight(TreeNode* p)
    {
        TreeNode* q = p->left;
        TreeNode* parent = p->prev;
        p->left = q->right;
        q->right = p;

        p->prev = q;
        q->prev = parent;
        q->left->prev = q;
        q->right->prev = q;
        Fixheight(p);
        Fixheight(q);
        return q;
    }

    static TreeNode* RotateLeft(TreeNode* q)
    {
        TreeNode* parent = q->prev;
        TreeNode* p = q->right;
        q->right = p->left;

        p->left = q;
        p->left->prev = p;
        p->right->prev = p;
        p->prev = parent;
        Fixheight(q);
        Fixheight(p);
        return p;
    }

    static TreeNode* Balance(TreeNode* p)
    {
        if (p == nullptr)
            return nullptr;
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

    TreeNode* Insert(TreeNode* p, KeyType key, ValueType value, TreeNode* prev)
    {
        if (!p)
        {
            ++_size;
            return new TreeNode(key, value, prev);
        }
        if (key < p->kv.first)
            p->left = Insert(p->left, key, value, p);
        else if (key > p->kv.first)
            p->right = Insert(p->right, key, value, p);
        return Balance(p);
    }

    static TreeNode* FindMin(TreeNode* p)
    {
        return p->left ? FindMin(p->left) : p;
    }

    static TreeNode* RemoveMin(TreeNode* p)
    {
        if (p->left == 0)
            return p->right;
        p->left = RemoveMin(p->left);
        return Balance(p);
    }

    TreeNode* Delete(TreeNode* cur, KeyType key)
    {
        if (!cur) return 0;
        if (key < cur->kv.first)
            cur->left = Delete(cur->left, key);
        else if (key > cur->kv.first)
            cur->right = Delete(cur->right, key);
        else {
            TreeNode* q = cur->left;
            TreeNode* r = cur->right;
            TreeNode* parent = cur->prev;
            delete cur;
             --_size;
            if( !r ) return q;
            TreeNode* min = FindMin(r);
            min->right = RemoveMin(r);
            min->left = q;
            min->prev = parent;

            if (min->right)
                min->right->prev = min;
            if (min->left)
                min->left->prev = min;
            return Balance(min);
        }
        return Balance(cur);
    }

    void Insert(KeyType key, ValueType value) {
        root = Insert(root, key, value, nullptr);
        //Balance();
    }

    ValueType& Search(KeyType key){
        TreeNode** cur = &root;
        TreeNode* prev = nullptr;
        while (*cur) {
            if (key < (*cur)->kv.first) {
                prev = *cur;
                cur = &(*cur)->left;
            }
            else if (key > (*cur)->kv.first) {
                prev = *cur;
                cur = &(*cur)->right;
            }
            else {
                return (*cur)->kv.second;
            }
        }
        ++_size;
        *cur = new TreeNode(key, ValueType());
        (*cur)->prev = prev;
        ValueType& value = (*cur)->kv.second;
        (*cur)->prev = Balance((*cur)->prev);
        return value;
    }

    void Delete(KeyType key){
        root = Delete(root, key);
        //Balance();
    }

public:
    map() :
        root(nullptr),
        _size(0){}

    class iterator{
        using T = pair<KeyType, ValueType>;

        TreeNode* node;
    public:
        iterator(TreeNode* node) : node(node) {}

        iterator(const iterator& other) : node(other.node) {}

        T& operator*()
        {
            return this->node->kv;
        }

        T* operator->(){
            return &this->node->kv;
        }

        iterator operator++(){
            KeyType min = node->kv.first;
            if (node->right && min < node->right->kv.first) {
                node = node->right;
                while (node->left){
                    node = node->left;
                }
                return *this;
            }
            if (node->prev && node->prev->kv.first > min){
                node = node->prev;
                return *this;
            }
            while (node->prev && node->prev->kv.first < min) {
                node = node->prev;
            }
            if (node->prev && min < node->prev->kv.first) {
                node = node->prev;
                return *this;
            }
            node = nullptr;
            return *this;
        }

        iterator operator++(int) {
            return ++*this;
        }

        bool operator!=(const iterator& other) {
            return this->node != other.node;
        }

        bool operator==(const iterator& other) {
            return this->node == other.node;
        }

        operator bool() {
            return node;
        }

        friend void map<KeyType, ValueType>::erase(const iterator& it);
    };

    iterator begin(){
        TreeNode* node = root;
        while (node && node->left) node = node->left;
        return iterator(node);
    }

    iterator end(){
        return iterator(nullptr);
    }

    void insert(const KeyType& key, const ValueType& value){
        Insert(key, value);
    }

    iterator find(const KeyType& key){
        TreeNode* cur = root;
        while (cur) {
            if (key < cur->kv.first) {
                cur = cur->left;
            }
            else if (key > cur->kv.first) {
                cur = cur->right;
            }
            else {
                return iterator(cur);
            }
        }
        return iterator(cur);
    }

    void erase(const KeyType& key){
        Delete(key);
    }


    void erase(const iterator& iter){
        if (!iter.node){
            throw 0;
        }
        Delete(iter.node->key);
    }

    void clear(){
        DestroyNode(root);
        root = nullptr;
        _size = 0;
    }

    bool empty(){
        return _size == 0;
    }

    int count(KeyType key){
        return find(key) != iterator(nullptr);
    }

    int size(){
        return _size;
    }

    ValueType& at(KeyType key){
        return Search(key);
    }

    ValueType& operator[](KeyType key){
        return at(key);
    }
};

#endif // MAP_H
