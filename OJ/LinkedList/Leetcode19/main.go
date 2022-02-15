
type ListNode struct {
	Val  int
	Next *ListNode
}

func removeNthFromEnd(head *ListNode, n int) *ListNode {
	id := 0
	m := make(map[int]*ListNode, 30)
	node := head
	for node != nil {
		m[id] = node
		id++
		node = node.Next
	}
	id--

	prev := m[id-n]
	next := m[id-n+2]
	//沒有考慮到 edge case e.g. only one node hence prev = nil

	//一開始假設如果 prev = nil 那要刪除的是第一個元素
	// 所以head 可以設成 nil? <= 錯了
	//
	if prev != nil {
		prev.Next = next
	} else {
		head = next
	}

	return head

}