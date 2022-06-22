#include "Tree.h"
#include "helper.h"


int main()
{
    Tree tree;

    cout << "File content is:" << endl;
    string filename = "laba_task.txt";
    display_file(filename);

    ifstream file(filename);

    string temp;
    int counter = 1;

    while (!file.eof()) 
    {
        getline(file, temp);
        if (temp != "\n")
        {
            vector <string> words = split(temp);
            for (string word : words) 
            {
                // for last word
                int last_index = word.length() - 1;
                if (word[last_index] == ';')
                {
                    word.erase(last_index, 1); // word[word:-1]
                }

                // for functions call
                int start_pos = word.find('(');
                if (start_pos != -1)
                {
                    word.erase(start_pos);
                }

                if (isidentifier(word))
                {
                    tree.addElement(word, counter);
                }
            }
        }
    }

    file.close();
    tree.printTree();

    return 0;
}