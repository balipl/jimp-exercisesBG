//
// Created by bartek on 21.03.17.
//

#include "SmartTree.h"

namespace datastructures {

    unique_ptr <SmartTree> CreateLeaf(int value){
        unique_ptr<SmartTree> p = std::make_unique<SmartTree>();
        p->left = nullptr;
        p->right = nullptr;
        p->value = value;
        return p;
    }
    unique_ptr <SmartTree> InsertLeftChild(unique_ptr<SmartTree> tree, unique_ptr<SmartTree> left_subtree){
        tree->left = std::move(left_subtree);
        return tree;
    }
    unique_ptr <SmartTree> InsertRightChild(unique_ptr<SmartTree> tree, unique_ptr<SmartTree> right_subtree){
        tree ->right = std::move(right_subtree);
        return tree;
    }
    void PrintTreeInOrder(const unique_ptr<SmartTree> &unique_ptr, std::ostream *out){
        if (unique_ptr->left != nullptr)
            PrintTreeInOrder(unique_ptr->left, out);
        (*out) << unique_ptr->value<<", ";
        if (unique_ptr->right != nullptr)
            PrintTreeInOrder(unique_ptr->right, out);

    }
    string DumpTree(const unique_ptr<SmartTree> &tree){
        string dump;
        dump = dump + "[";
        dump = dump + std::to_string(tree->value);
        if(tree->left == nullptr)
            dump = dump + " [none]";
        if(tree->left != nullptr)
            dump = dump +" "+ DumpTree(tree->left);
        if(tree->right == nullptr)
            dump = dump + " [none]";
        if(tree->right != nullptr)
            dump = dump +" "+ DumpTree(tree->right);

        dump = dump + "]";

        return dump;

    }
    unique_ptr <SmartTree> RestoreTree(const string &tree){
        int i = 0;
        unique_ptr<SmartTree> root;
        while(tree[i]!= '\0')
        {
            if(tree[i]=='[')
            {

                i+=1;
                string lisc ="";
                while(tree[i]!=' ' && tree[i]!=']')
                {
                    lisc = lisc + tree[i];
                    i+=1;

                }

                root = CreateLeaf(stoi(lisc));


                std::cout << lisc << " ";

            }
            i+=1;
        }
        return root;
    }

}