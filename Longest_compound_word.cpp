
#include <bits/stdc++.h>
#include <ctime>
using namespace std;



//  using tries data structure for this problem. Tries provide very ordered system and is easy to transverse
class trie
{
public:
    //  created a hash-table in tries of size 26 as alphabets are of size 26. It will cover all cases. Initializing all to zero.
    trie *hash[26] = {0};
    //  if a word ends wordend will be used to indicate that word has been ended.
    int wordend = 0;
    int prefix=0;
};  


//  will use compare function to sort the words given according to their size.
bool compare(string &s1, string &s2)
{
    return s1.size() > s2.size();
}


//  insert function will insert a word in tries using a heap. It will take input of root of tries, word , length of word and current index at which we are in a word
void insert(trie **root, string word, int len, int index)
{
    if (index < len)
    {       
        // converting a letter of word to a number to be used by hash-table.
        if (((*root)->hash[word[index] - 97]) == 0)
        {
            ((*root)->hash[word[index] - 97]) = new trie();
        }
        // if (index==len-1)
        // {
        //     (*root)->wordend=1;
        // }
        ((*root)->hash[word[index] - 97])->prefix += 1;

        insert(&((*root)->hash[word[index] - 97]), word, len, index + 1);
    }
    if (index == len)

    {
        // if the word is ended the next node below  it will contain wordend=1 not the current node.
        (*root)->wordend = 1;
    }
}


//  finding the largest compound word 
int longest_compound_word(trie **root, string word, int index, int length, int splited)
{
    trie *new_copy = (*root);
    //  checking if new word given is present or not.
    if (index < length)
    {
        if ((new_copy->hash[word[index] - 97]) == 0)
            return 0;
    }
    while (index < length)
    {   
        //  if found a prefix using recursion for checking if another part is also a word /prefix or not.
        if (((new_copy->hash[word[index] - 97])->wordend == 1) && (index != length - 1))
        {
            int x = longest_compound_word(root, word, index + 1, length, 1);
            if (x == 1)
            {
                return 1;
            }
        }
        new_copy = (new_copy->hash[word[index] - 97]);
        index += 1;
        if (((new_copy->hash[word[index] - 97]) == 0) && (index != length))
            return 0;
    }
    if ((index == length) && (splited == 1))
        return 1;
    if ((splited == 1) && ((new_copy->wordend) == 1))
        return 1;
    return 0;
}

int main()
{


#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    clock_t start, end;
     start = clock();
    trie *root = new trie();
    int n;
    vector<string> colour;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        string s;
        getline(cin, s);
        colour.push_back(s);
        insert(&root, s, s.length(), 0);
    }

    // sorting words according to size
    sort(colour.begin(), colour.end(), compare);
    int not_present=1;
    int count=0;


    // checking for largest compound word starting from longest word 
    for (int i = 0; i < n; i++)

    {
        if (longest_compound_word(&root, colour[i], 0, colour[i].length(), 0) == 1)
        {
            cout << colour[i]  << endl;
            count+=1;
            if (count==2)
            {
            not_present=0;
            break;
            }
        }
    }

    //  if no compound word is found
    if (not_present==1)
        cout<<"No compound word found";
        end = clock();
        double duration_sec = double(end-start)/CLOCKS_PER_SEC;
        cout<<"time taken is " <<duration_sec<< " seconds";
    
}
