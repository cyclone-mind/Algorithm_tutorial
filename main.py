class ListNode:
    def __init__(self, val:int) -> None:
                    self.val:int = val
                    self.next:ListNode | None = None
        
node = ListNode(2)

print(node.val)