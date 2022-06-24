#include <bits/stdc++.h>
using namespace std;

struct AVLTreeNode{
    int key;
    int height;
    AVLTreeNode* lchild;
    AVLTreeNode* rchild;
    AVLTreeNode(){
        height = 0;
        lchild = NULL;
        rchild = NULL;
    }
};

int GetHeight(AVLTreeNode* pnode){
    if(pnode == NULL){
        return 0;
    }
    return pnode->height;
}

AVLTreeNode* LeftRotation(AVLTreeNode* proot){
    AVLTreeNode* prchild = proot->rchild;
    proot->rchild = prchild->lchild;
    prchild->lchild = proot;

    proot->height = max(GetHeight(proot->lchild),GetHeight(proot->rchild)) + 1;
    prchild->height = max(GetHeight(prchild->lchild),GetHeight(prchild->rchild)) + 1;
    return prchild;
}

AVLTreeNode* RightRotation(AVLTreeNode* proot){
    AVLTreeNode* plchild = proot->lchild;
    proot->lchild = plchild->rchild;
    plchild->rchild = proot;

    proot->height = max(GetHeight(proot->lchild),GetHeight(proot->rchild)) + 1;
    plchild->height = max(GetHeight(plchild->lchild),GetHeight(plchild->rchild)) + 1;
    return plchild;
}

AVLTreeNode* RightLeftRotation(AVLTreeNode* proot){
    proot->rchild = RightRotation(proot->lchild);
    return LeftRotation(proot);
}

AVLTreeNode* LeftRightRotation(AVLTreeNode* proot){
    proot->lchild = LeftRotation(proot->lchild);
    return RightRotation(proot);
}

AVLTreeNode* InsertAVLTree(AVLTreeNode* &pnode,int key){
    if(pnode == NULL){
        pnode = new AVLTreeNode();
        pnode->key = key;
    }
    else if(key < pnode->key){
        pnode->lchild = InsertAVLTree(pnode->lchild,key);
        if(GetHeight(pnode->lchild) - GetHeight(pnode->rchild) == 2){
            if(key < pnode->lchild->key){
                pnode = RightRotation(pnode);
            }
            else{
                pnode = LeftRightRotation(pnode);
            }
        }
    }
    else{
        pnode->rchild = InsertAVLTree(pnode->rchild,key);
        if(GetHeight(pnode->rchild) - GetHeight(pnode->lchild) == 2){
            if(key >= pnode->rchild->key){
                pnode = LeftRotation(pnode);
            }
            else{
                pnode = RightLeftRotation(pnode);
            }
        }
    }
    pnode->height = max(GetHeight(pnode->lchild),GetHeight(pnode->rchild)) + 1;
    return pnode;
}

void PreOrder(AVLTreeNode* &proot){
    if(proot == NULL){
        return;
    }
    printf("%d ",proot->key);
    PreOrder(proot->lchild);
    PreOrder(proot->rchild);
}

void InOrder(AVLTreeNode* &proot){
    if(proot == NULL){
        return;
    }
    InOrder(proot->lchild);
    printf("%d ",proot->key);
    InOrder(proot->rchild);
}

void PostOrder(AVLTreeNode* &proot){
    if(proot == NULL){
        return;
    }
    PostOrder(proot->lchild);
    PostOrder(proot->rchild);
    printf("%d ",proot->key);
}

AVLTreeNode* MaxAVLNode(AVLTreeNode* proot){
    while(proot->rchild!= NULL){
        proot = proot->rchild;
    }
    return proot;
}

AVLTreeNode* MinAVLNode(AVLTreeNode* proot){
    while(proot->lchild!= NULL){
        proot = proot->lchild;
    }
    return proot;
}

AVLTreeNode* RemoveAVLNode(AVLTreeNode* &proot,int key){
    if(key == proot->key){
        if(proot->lchild != NULL && proot->rchild != NULL){
            if(GetHeight(proot->lchild) > GetHeight(proot->rchild)){
                AVLTreeNode* temp = MaxAVLNode(proot->lchild);
                proot->key = temp->key;
                proot->lchild = RemoveAVLNode(proot->lchild,temp->key);
            }
            else{
                AVLTreeNode* temp = MinAVLNode(proot->rchild);
                proot->key = temp->key;
                proot->rchild = RemoveAVLNode(proot->rchild,temp->key);
            }
        }
        else{
            AVLTreeNode* temp = proot;
            if(proot->lchild != NULL){
                proot = proot->lchild;
            }
            else if(proot->rchild != NULL){
                proot = proot->rchild;
            }
            delete(temp);
            return NULL;
        }
    }
    else if(key > proot->key){
        proot->rchild = RemoveAVLNode(proot->rchild,key);
        if(GetHeight(proot->lchild) - GetHeight(proot->rchild) == 2){
            if(GetHeight(proot->lchild->rchild) > GetHeight(proot->lchild->lchild)){
                proot = LeftRightRotation(proot);
            }
            else{
                proot = RightRotation(proot);
            }
        }
    }
    else{
        proot->lchild = RemoveAVLNode(proot->lchild,key);
        if(GetHeight(proot->rchild) - GetHeight(proot->lchild) == 2){
            if(GetHeight(proot->rchild->lchild) > GetHeight(proot->rchild->rchild)){
                proot = RightLeftRotation(proot);
            }
            else{
                proot = LeftRotation(proot);
            }
        }
    }
    return proot;
}


int main(void){
    AVLTreeNode* TestTree = NULL;
    for(int i=0;i<=10;i++){
        TestTree = InsertAVLTree(TestTree,i);
    }
    PreOrder(TestTree);
    printf("\n");
    printf("%d %d\n",MaxAVLNode(TestTree)->key,MinAVLNode(TestTree)->key);
    RemoveAVLNode(TestTree,10);
    PreOrder(TestTree);
    printf("\n");
    InOrder(TestTree);
    printf("\n");
    RemoveAVLNode(TestTree,5);
    PreOrder(TestTree);
    printf("\n");
    InOrder(TestTree);
    printf("\n");
    RemoveAVLNode(TestTree,3);
    PreOrder(TestTree);
    printf("\n");
    InOrder(TestTree);
    printf("\n");
    return 0;
}