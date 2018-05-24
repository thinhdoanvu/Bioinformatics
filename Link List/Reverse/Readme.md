[Algorithm by Picture](https://algorithms.tutorialhorizon.com/files/2014/08/Linked-List-Reversal-846x1024.png)
1. Create 3 nodes, currNode, PrevNode and nextNode.
2. Initialize them as currNode = head; nextNode = null;prevNode = null;
3. Now keep reversing the pointers one by one till currNode!=null.

while(currNode!=null){
     nextNode = currNode.next;
     currNode.next = prevNode;
     prevNode = currNode;
     currNode = nextNode;
}
