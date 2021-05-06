#include <iostream>
#include <sstream>
#include <string>
#include "Tree.h"

struct Node {
    int key;
    Node *left;
    Node *right;

    Node(int k, Node *l = nullptr, Node *r = nullptr) {
        this->key = k;
        this->left = l;
        this->right = r;
    }
};

Tree::Tree() {
    _root = nullptr;
}

Tree::Tree(std::string serial) {
    _root = nullptr;
    std::stringstream ss(serial);
    _serializeTree(ss, &_root);
}

Tree::~Tree() {
    _root = _clear(_root);
}

void Tree::_serializeTree(std::stringstream& ss, Node **node) {
    std::string value;
    ss >> value;
    if(value == "#") // filho == nullptr
        return;
    int key = std::stoi(value);
    *node = new Node(key);
    _serializeTree(ss, &((*node)->left));
    _serializeTree(ss, &((*node)->right));
}

Node *Tree::_clear(Node *node) {
    if(node != nullptr) { // caso geral: vamos liberar essa arvore
        node->left = _clear(node->left);
        node->right = _clear(node->right);
        delete node;
    }
    return nullptr;
}

void Tree::inorder() {
    _inorder(_root);
    std::cout << std::endl;
}

void Tree::_inorder(Node *node) {
    if(node != nullptr) { // Caso Geral
        _inorder(node->left);
        std::cout << node->key << " ";
        _inorder(node->right);  
    }
}

void Tree::bshow(){
    _bshow(_root, "");
}

void Tree::_bshow(Node *node, std::string heranca) {
    if(node != nullptr && (node->left != nullptr || node->right != nullptr))
        _bshow(node->right , heranca + "r");
    for(int i = 0; i < (int) heranca.size() - 1; i++)
        std::cout << (heranca[i] != heranca[i + 1] ? "│   " : "    ");
    if(heranca != "")
        std::cout << (heranca.back() == 'r' ? "┌───" : "└───");
    if(node == nullptr){
        std::cout << "#" << std::endl;
        return;
    }
    std::cout << node->key << std::endl;
    if(node != nullptr && (node->left != nullptr || node->right != nullptr))
        _bshow(node->left, heranca + "l");
}


bool Tree::identical(Tree *t) { // TODO
    return _identical(_root, t->_root);
}

bool Tree::_identical(Node *nd1, Node *nd2) { // TODO
   
    if(nd1 != nullptr && nd2 != nullptr){
        

        bool res1 = _identical(nd1->right, nd2->right);
        
        if((nd1->key == nd2->key) && (res1 != false)){
            return true;
        }else{
            return false;
        }

        bool res2 = _identical(nd1->left, nd2->left );
        
        if((nd1->key == nd2->key) && (res2 != false)){
            return true;
        }else{
            return false;
        }

    }

    
}

Tree *Tree::clone() { // TODO
    Tree *clone = new Tree();

    clone->_root = _clone(_root);

    return clone;
}

Node *Tree::_clone(Node *node) { // TODO
    Node *aux = node;

    if(node != nullptr){
        aux->right = _clone(node->right);
        aux->left = _clone(node->left);
    }

    return aux;
}


