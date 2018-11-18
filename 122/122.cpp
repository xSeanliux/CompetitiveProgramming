#include <iostream>
#include <string.h>

using namespace std;

string com;

int nodeHead;
struct Node
{
    int head;
    string vals[256 + 10];
    Node *right;
    Node *left;
} *root;
Node *nodeStack[256 + 50];
Node *create()
{
    Node *p = new Node();
    p -> head = 0;
    p -> right = NULL;
    p -> left = NULL;
    return p;
}
string outputStack[300];
int oHead;


bool checkValid(Node *currentNode)
{
    if(currentNode == NULL) return true;
    if(currentNode -> head != 1)  //head = 0, which means no value or >2, which means multiple values
    {
        return false;
    }
    else if(currentNode -> left == NULL && currentNode -> right == NULL)
        return true;
    return (checkValid(currentNode -> left) && checkValid(currentNode -> right));
}


int main()
{
    root = create();
    while(cin >> com)
    {
        if(com == "()")
        {
            if(checkValid(root))
            {
                oHead = 0;
                for(int i = 0; i < 306; i++)
                {
                    nodeStack[i] = NULL;
                }
                int currentIndex = 0;
                nodeStack[0] = root;
                nodeHead = 1;
                while(nodeStack[currentIndex] != NULL)
                {
                    //cout << nodeStack[currentIndex] -> vals[0] << " ";
                    outputStack[oHead] = nodeStack[currentIndex] -> vals[0];
                    oHead++;
                    if(nodeStack[currentIndex] -> left != NULL)
                    {
                        nodeStack[nodeHead] = nodeStack[currentIndex] -> left;
                        nodeHead++;
                    }
                    if(nodeStack[currentIndex] -> right != NULL)
                    {
                        nodeStack[nodeHead] = nodeStack[currentIndex] -> right;
                        nodeHead++;
                    }
                    currentIndex++;
                }
                cout << outputStack[0];
                for(int i = 1 ; i < oHead; i++)
                {
                    cout << " " << outputStack[i];
                }
                cout << endl;
            }
            else
            {
                printf("not complete\n");
            }
            root = create();
        }
        else
        {
            string val = "";
            string c = "";
            int l = com.length(), i;
            for(i = 1 ; i < l && com[i] != ','; i++)
            {
                val += com[i];
            }
            for(i++; i < l-1; i++)
            {
                c += com[i];
            }
            //cout << "val: " << val << " command: " << c << endl;
            if(c == "")
            {
                //cout << "root command" << endl;
                root -> vals[root -> head] = val;
                root -> head++;
            }
            else
            {
                int cl = c.length();
                Node *currentNode = root;
                for(int i = 0 ; i < cl; i++) //traveling to target node
                {
                    switch(c[i])
                    {
                    case 'R':
                        //cout << "going right" << endl;
                        if(currentNode -> right == NULL)
                        {
                            //cout << "create"<< endl;
                            currentNode -> right = create();
                        }
                        currentNode = currentNode -> right;
                        break;
                    case 'L':
                        //cout << "going left" << endl;
                        if(currentNode -> left == NULL)
                        {
                            //cout << "create"<< endl;
                            currentNode -> left = create();
                        }
                        currentNode = currentNode -> left;
                    }
                }
                currentNode -> vals[currentNode -> head] = val;
                currentNode -> head++;
            }

        }
    }
}
