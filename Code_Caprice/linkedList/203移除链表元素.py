from __future__ import annotations
from typing import Optional

class ListNode:
    def __init__(self, val: int = 0, next: ListNode = None) -> None:
        self.val: int = val
        self.next: ListNode = next


def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
    # 实现移除链表元素的逻辑
    dummyHead:ListNode = ListNode()
    dummyHead.next = head
    cur:ListNode = dummyHead
    while cur.next:
        if cur.next.val == val :
            cur.next = cur.next.next
        else:
            cur = cur.next
    return dummyHead.next


