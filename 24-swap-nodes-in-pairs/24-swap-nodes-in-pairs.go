/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func swapPairs(head *ListNode) *ListNode {
    if head==nil || head.Next==nil{
        return head
    }
    res:=head.Next
    head.Next=swapPairs(head.Next.Next)
    res.Next=head
    return res
}