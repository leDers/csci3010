/**
 * @file Tree.h
 * @author Leif Anders
 * @brief   Header and implementation for template tree class
 * @version 0.1
 * @date 2023-02-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef _TREE_H_
#define _TREE_H_

#include <iostream>

template <typename T>
struct Node{
    T data_;
    Node* left_;
    Node* right_;

    Node(T data){
        this->data_ = data;
        this->left_ = NULL;
        this->right_ = NULL;
    }
};

template <typename T>
class Tree{
    private:
        Node<T>* root_;

        void destroyTree(Node<T>* leaf){
            if (leaf!=NULL){
                destroyTree(leaf->left_);
                destroyTree(leaf->right_);
                delete leaf;
            }
        }

        void insert(T key, Node<T>* leaf){
            if (key < leaf->data_){
                if (leaf->left_ != NULL){
                    insert(key, leaf->left_);
                }
                else{
                    leaf->left_ = new Node(key);
                    leaf->left_->left_ = NULL;
                    leaf->left_->right_ = NULL;
                }
            }
            else if (key >= leaf->data_){
                if (leaf->right_ != NULL){
                    insert(key, leaf->right_);
                }
                else{
                    leaf->right_ = new Node(key);
                    leaf->right_->left_ = NULL;
                    leaf->right_->right_ = NULL;
                }
            }

        }

        Node<T>* search(T key, Node<T>* leaf){
            if (leaf != NULL){
                if (key == leaf->data_) { return leaf; }

                if (key < leaf->data_){
                    return search(key, leaf->left_);
                }
                else { return seach(key, leaf->right_); }
            }
            else { return NULL; }
        }

        Node<T>* deleteElement(T key, Node<T>* leaf){
            // empty tree check
            if (leaf == NULL) { return leaf; }

            // find target 
            if (key < leaf->data_) {leaf->left_ = deleteElement(key, leaf->left_); }
            else if (key > leaf->data_) { leaf->right = deleteElement(key, leaf->right_); }
            
            // if the node has one or less children
            else{
                if (leaf->left_ == NULL) {
                    Node<T>* temp = leaf->right_;
                    free(leaf);
                    return temp;
                } 
                else if (leaf->right_ == NULL) {
                    Node<T>* temp = leaf->left_;
                    free(leaf);
                    return temp;
                }

            // if node has two children
            Node<T>* temp = leaf->right_;
            while((temp) && (temp->left_ != NULL)) { temp = temp->left_; }
            // place the inorder successor in position of deleted node
            leaf->data_ = temp->data_;
            //delete inorder sucessor
            leaf->right_ = deleteElement(temp->data_, leaf->right_);
            }

           return leaf;
        }

        void inorder(Node<T>* leaf) const {
            if (leaf!= NULL){
                inorder(leaf->left_);
                std::cout << leaf->data_ << " "; 
                inorder(leaf->right_);
            }
        }

    public:
        Tree(T val) {this->root_ = new Node(val);} // fix this
        ~Tree() { destroyTree(this->root_); }

        void insertElement(T key){
            if (root_ != NULL) { insert(key, root_); }
            else{
                root_ = new Node(key);
                root_->left_ = NULL;
                root_->right_ = NULL;
            }
        }

        bool search(T key) { return search(key, this->root_); }

        void deleteElement(T key) { deleteElement(key, this->root_); }

        void inorder() const { inorder(this->root_); }

        friend std::ostream& operator<<(std::ostream& os, const Tree<T> &t){
            t.inorder();
            return os;
        }
};

#endif