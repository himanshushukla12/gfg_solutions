//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printlist(Node *head) {
    if (head == NULL)
        return;
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void append(struct Node **headRef, char data) {
    struct Node *new_node = new Node(data);
    struct Node *last = *headRef;

    if (*headRef == NULL) {
        *headRef = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}


// } Driver Code Ends
/*
Structure of the node of the linked list is as
struct Node
{
    char data;
    struct Node *next;

    Node(char x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    // task is to complete this function
    // function should return head to the list after making
    // necessary arrangements
    Node* arrangeCV(Node* head) {
    if (head == NULL || head->next == NULL) return head; // Handle edge cases

    Node dummyVowel(0); // Using dummy nodes to simplify list operations
    Node dummyConsonant(0);
    Node* vowels = &dummyVowel;
    Node* consonants = &dummyConsonant;

    while (head != NULL) {
        if (head->data == 'a' || head->data == 'e' || head->data == 'i' || 
            head->data == 'o' || head->data == 'u') {
            vowels->next = head; // Attach vowel nodes here
            vowels = vowels->next;
        } else {
            consonants->next = head; // Attach consonant nodes here
            consonants = consonants->next;
        }
        head = head->next;
    }

    vowels->next = dummyConsonant.next; // Link the end of the vowel list to the start of the consonant list
    consonants->next = NULL; // The end of the consonant list should point to NULL

    return dummyVowel.next; // The start of the rearranged list, skipping the dummy node
}
};


//{ Driver Code Starts.

// task is to complete this function
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        char tmp;
        struct Node *head = NULL;
        cin >> n;
        while (n--) {
            cin >> tmp;
            append(&head, tmp);
        }
        Solution obj;
        head = obj.arrangeCV(head);
        printlist(head);
    }
    return 0;
}

// } Driver Code Ends