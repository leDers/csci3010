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

// node structure to organize tree 
template <typename T>
struct Node{
    T data_;        // value
    Node* left_;    // left child
    Node* right_;   // right child

    // constructor 
    Node(T data){
        this->data_ = data;
        this->left_ = NULL;
        this->right_ = NULL;
    }
};

template <typename T>
class Tree{
    private:
        Node<T>* root_;     // root

        /**
         * @brief destroys tree
         * 
         * @param leaf -- node to call function on
         */
        void destroyTree(Node<T>* leaf){
            if (leaf!=NULL){
                destroyTree(leaf->left_);
                destroyTree(leaf->right_);
                delete leaf;
            }
        }

        /**
         * @brief inserts elements into tree
         * 
         * @param key the value to insert
         * @param leaf the node to insert from
         */
        void insert(T key, Node<T>* leaf){
            // if key is less that durrent node
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

            //if key is greater than current node
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

        /**
         * @brief search for a value in the tree
         * 
         * @param key value to find
         * @param leaf node to start from
         * @return Node<T>*    pointer to node if found, else NULL
         */
        Node<T>* search(T key, Node<T>* leaf){
            //if not null
            if (leaf != NULL){
                // if key is value
                if (key == leaf->data_) { return leaf; }

                //if key less than value
                if (key < leaf->data_){
                    return search(key, leaf->left_);
                }

                // if key greater than value
                else { return search(key, leaf->right_); }
            }
            else { return NULL; }
        }

        /**
         * @brief returns value of successor node
         * 
         * @param leaf node to find succ. of
         * @return T value of node
         */
        T successor(Node<T>* leaf){
            leaf = leaf->right_;
            while(leaf->left_ != NULL){
                leaf = leaf->left_;
            }
            return leaf->data_;
        }

         /**
         * @brief returns value of predecessor node
         * 
         * @param leaf node to find pred.of
         * @return T value of node
         */
        T predecessor(Node<T>* leaf){
            leaf = leaf->left_;
            while(leaf->right_ != NULL){
                leaf = leaf->right_;
            }
            return leaf->data_;
        }

        /**
         * @brief deletes element from tree
         * 
         * @param key value to delete
         * @param leaf node to start from
         * @return Node<T>* 
         */
        Node<T>* deleteElement(T key, Node<T>* leaf){
            // empty tree check
            if (leaf == NULL) { return leaf; }

            // find target 
            if (key < leaf->data_) {leaf->left_ = deleteElement(key, leaf->left_); }
            else if (key > leaf->data_) { leaf->right_ = deleteElement(key, leaf->right_); }
            
            // if the node has one or less children
            else{
                // if both child null
                if ((leaf->left_ == NULL) && (leaf->right_ == NULL)) { leaf = NULL; }

                // if right child not null
                else if (leaf->right_ != NULL) {
                    leaf->data_ = successor(leaf);
                    leaf->right_ =  deleteElement(leaf->data_, leaf->right_);
                } 
                
                // if left child mot null
                else {
                    leaf->data_ = predecessor(leaf);
                    leaf->left_ = deleteElement(leaf->data_, leaf->left_);
                }
            }

           return leaf;
        }

        /**
         * @brief prints tree inorder
         * 
         * @param leaf node to begin print from
         */
        void inorder(Node<T>* leaf) const {
            if (leaf!= NULL){
                inorder(leaf->left_);
                std::cout << leaf->data_ << " "; 
                inorder(leaf->right_);
            }
        }

    public:

        Tree() {this->root = new Node(NULL); }
        Tree(T val) {this->root_ = new Node(val);} 
        ~Tree() { destroyTree(this->root_); }

        // calls private insert()
        void insertElement(T key){
            if (root_ != NULL) { insert(key, root_); }
            else{
                root_ = new Node(key);
                root_->left_ = NULL;
                root_->right_ = NULL;
            }
        }

        // calls private: searh()
        bool search(T key) { return search(key, this->root_); }

        // calls private: delete()
        void deleteElement(T key) { deleteElement(key, this->root_); }

        // calls inorder()
        void inorder() const { inorder(this->root_); }

        T minValue(Node<T>* leaf){
            if (leaf->left_ == NULL) { return leaf->data_; }
            return minValue(leaf->left_);
        }

        T maxValue(Node<T>* leaf){
            if (leaf->right_ == NULL) {return leaf->data_; }
            return maxValue(leaf->right_);
        }

        Node<T>* getRoot() {return this->root_; }

        // << overload
        friend std::ostream& operator<<(std::ostream& os, const Tree<T> &t){
            t.inorder();
            return os;
        }
};

#endif