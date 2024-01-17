struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *final_sum = new ListNode();
        ListNode *temp = final_sum;
        int carry = 0, digit_sum = 0;

        while (true)
        {
            if (l1 != nullptr)
            {
                digit_sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr)
            {
                digit_sum += l2->val;
                l2 = l2->next;
            }
            digit_sum += carry;

            if (digit_sum > 9)
            {
                carry = digit_sum / 10;
                digit_sum %= 10;
            }
            else
            {
                carry = 0;
            }

            temp->val = digit_sum;

            if (l1 == nullptr && l2 == nullptr && carry == 0)
            {
                break;
            }

            temp->next = new ListNode();
            temp = temp->next;
            digit_sum = 0;
        }

        return final_sum;
    }
};