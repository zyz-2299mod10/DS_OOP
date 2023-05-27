#include <cstdlib>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

struct MinHeapNode 
{
    char data;
    int freq;
    MinHeapNode* left, * right;

    MinHeapNode(char data_, int freq_) : left(NULL), right(NULL), data(data_), freq(freq_) {};
};

struct compare
{
    bool operator()(MinHeapNode* l, MinHeapNode* r)
    {
        return(l->freq > r->freq);
    }
};

class HMTree
{
public:
    int WELP;
    vector<string> ans;
    string decode;
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;
    HMTree() : WELP(0) {};
    void StoreAns(MinHeapNode*, string);
    void HuffmanCodes(char[], int[], int);
    void SortAns(vector<string>);
    void DecodeHuffmancode(MinHeapNode*, MinHeapNode*, int, string);
};

void HMTree :: StoreAns(MinHeapNode* root, string str)
{
    if (root == NULL)  return;

    if (root->data != '$')
    {
        string str2 = " : " + str;
        string str3 = root->data + str2;
        ans.push_back(str3);
        WELP += (str.length() * root->freq);
    }

    StoreAns(root->left, str + "0");
    StoreAns(root->right, str + "1");
}

void HMTree::SortAns(vector<string> ans)
{
    sort(ans.begin(), ans.end());

    for (const auto& item : ans)
    {
        cout << item << "\n";
    }
}

void HMTree :: HuffmanCodes(char data[], int freq[], int size)
{
    MinHeapNode *left, *right, *top;

    for (int i = 0; i < size; ++i)  minHeap.push(new MinHeapNode(data[i], freq[i]));

    while (minHeap.size() != 1) 
    {
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();

        top = new MinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        minHeap.push(top);

    }

    StoreAns(minHeap.top(), "");
}

void HMTree::DecodeHuffmancode (MinHeapNode* current, MinHeapNode* root, int index, string s)
{
    if (current->data != '$')
    {
        decode += current->data;
        current = root;
    }
    
    if (s[index] == '0')
    {
        DecodeHuffmancode(current->left, root, index + 1, s);
    }

    else if (s[index] == '1')
    {
        DecodeHuffmancode(current->right, root, index + 1, s);
    }
   
}

int countOccurrences(char c, string& str)
{
    int count = 0;

    for (char i : str)
        if (i == c)
            count++;

    return count;
}

int main(int argc, const char* argv[])
{
    vector<std::string> all_args;
    all_args.assign(argv, argv + argc);
    cout << "\nDSOO-Program2-Demo: ";
    for (auto a : all_args) {
        cout << a << " ";
    }
    cout << "\n";

    // Q1-------------------------------------------------------------------------------

    if (argc != 2)
    {
        cout << "part1 : \n";
        HMTree Q1;
        char arr[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T' , 'U', 'V' , 'W' , 'X' , 'Y' ,'Z' };
        int freq[] = { 11,   5,   2,   3,  12,   3,   5,   6,   8,   1,   2,   4,   8,   7,   2,   2,   1,   9,   6,   2,    4,   1,    10,   10,   1,   1 };
        int size = sizeof(arr) / sizeof(arr[0]);
        int Q1_count = 1;

        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " = " << freq[i];
            if (Q1_count % 10 == 0) cout << "\n";
            else cout << " | ";
            Q1_count++;
        }
        cout << "\n" << endl;

        Q1.HuffmanCodes(arr, freq, size);
        Q1.SortAns(Q1.ans);
        cout << "\nWELP : " << Q1.WELP << endl;
    }

    // Q2-------------------------------------------------------------------------------
    else
    {
        HMTree Q2;
        string filename = argv[1];
        ifstream f;
        char store[100] = "";
        string str;
        string code;
        char c;
        int times[100];
        int Q2_count = 1;

        f.open(filename);

        while (f.get(c))
        {

            if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
            {
                int store_index = 0;
                int check = 1;

                for (; store[store_index] != '\0'; store_index++)
                {
                    if (store[store_index] == c) check = 0;
                }

                if (check == 1)
                {
                    store[store_index] = c;
                    store[store_index + 1] = '\0';
                }

                str += c;
            }

            if (c == '0' || c == '1')
            {
                code += c;
            }
        }

        sort(store, store+strlen(store));

        for (int i = 0; store[i] != '\0'; i++)
        {
            times[i] = countOccurrences(store[i], str);
        }

        cout << "character : " << str << "\n" << endl;

        for (int i = 0; store[i] != '\0'; i++)
        {
            cout << store[i] << " = " << times[i];
            if (Q2_count % 10 == 0) cout << "\n";
            else cout << " | ";
            Q2_count++;
        }

        cout << "\n\n";

        Q2.HuffmanCodes(store, times, strlen(store));
        Q2.SortAns(Q2.ans);

        // Q3-------------------------------------------------------------------------------
        cout << endl;

        cout << "Huffman code : " << code << endl;
        Q2.DecodeHuffmancode(Q2.minHeap.top(), Q2.minHeap.top(), 0, code);
        cout << "decode : " << Q2.decode << endl;
        cout << "WELP : " << Q2.WELP << endl;

        f.close();
    }

    return 0;
}
