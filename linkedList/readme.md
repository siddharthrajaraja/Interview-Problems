<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/materialize/1.0.0/css/materialize.min.css">
<h5>Linked List that 😨 up your interview !! But they are amazing!!</h5>
<hr>
<strong>DELETE A NODE WITHOUT HEADER!! :</strong>
<a href='https://practice.geeksforgeeks.org/problems/delete-without-head-pointer/1'>Link to problem</a>
<br>
This at first sight seems to be vague but this problem has a fine Intution inside !! <br>
<strong>Intution:</strong>
<ol>
    <li>Think of a O(n) solution.</li>
    <li>Try to play with data by copying the next node data to current one.</li>
    <li>End up deleting the end node of list.</li>
    <li>Corner case: What about a single node ?</li>
</ol>
<hr>
<strong>Swap Nodes in Pairs :</strong>
<a href='https://leetcode.com/problems/swap-nodes-in-pairs/'>Link to problem</a>
<br>This of solving it in single traversal without any additional Space !!<br>
<strong>Intution:</strong>
<ol>
    <li>Think of a O(n) solution.</li>
    <li>Try to think to work with list containing both even and odd number of nodes!!</li>
    <li>Corner case: What about a single node or list with no node ?</li>
    <pre>
    <u>Algorithm:</u>
        def swapPairs(ListNode *head):
            if(head==NULL):
                return NULL
            if(head->next==NULL):
                return head
            #make ListNode variables:  i,j,t,preI
            i=head ;  j=head->next ;  head=j;
            while(i->next!=NULL){
                t=j->next;
                j->next=i;
                i->next=t;
                preI=i;
                i=i->next;
                if(i!=NULL){
                    j=i->next;
                    preI->next=j;
                }
                else{
                    preI->next=i;
                    break;
                }
            }
            //for odd number of nodes in List:
            if(j==NULL):
                preI->next=i;
            return head;
    </pre>
    <li><strong>Note: Please try to implement the Algorithm code and visualize the steps then work on implementation part!!</strong></li>
</ol>

<hr>
<strong>Merge K Sorted Lists 👍</strong>
<a href='https://leetcode.com/problems/merge-k-sorted-lists/'>Link to problem</a>
<br>
This at first sight seems to be tricky but this problem has a fine Intution inside !! <br>
<strong>Intution:</strong>
<ol>
    <li>Think of a O(nlogn)  solution.</li>
    <li>Try to design or implement a Data Structure that stores the ingested in each of the list a sorted manner . (Hint : related to type of Queues)</li>
    <li>End up deleting the element from the designed data structure and add it to the generated Linked List .</li>
    <li>Return head of generated Linked List</li>
</ol>
<hr>
    