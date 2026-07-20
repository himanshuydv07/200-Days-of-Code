/* Structure of a Linked List node
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/

class Solution {
  private:
    Node* reverseList(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;

        while (curr) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

  public:
    Node *compute(Node *head) {
        if (!head || !head->next) return head;

        // Reverse the linked list
        head = reverseList(head);

        int maxi = head->data;
        Node* curr = head;

        while (curr && curr->next) {
            if (curr->next->data < maxi) {
                Node* temp = curr->next;
                curr->next = temp->next;
                delete temp;
            } else {
                curr = curr->next;
                maxi = curr->data;
            }
        }

        // Reverse again to restore order
        return reverseList(head);
    }
};
