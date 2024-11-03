#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

std::vector< std::vector<int> > spiralMatrix(int m, int n, ListNode* head) {
    std::vector< std::vector<int> > matrix(m, std::vector<int>(n, -1));
    int top = 0, bottom = m - 1, left = 0, right = n - 1;
    ListNode* current = head;

    while (top <= bottom && left <= right && current != nullptr) {
        for (int i = left; i <= right && current != nullptr; ++i) {
            matrix[top][i] = current->val;
            current = current->next;
        }
        ++top;

        for (int i = top; i <= bottom && current != nullptr; ++i) {
            matrix[i][right] = current->val;
            current = current->next;
        }
        --right;

        for (int i = right; i >= left && current != nullptr; --i) {
            matrix[bottom][i] = current->val;
            current = current->next;
        }
        --bottom;

        for (int i = bottom; i >= top && current != nullptr; --i) {
            matrix[i][left] = current->val;
            current = current->next;
        }
        ++left;
    }

    return matrix;
}

ListNode* createLinkedList(const std::vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

int main() {
    int m, n;
    std::cout << "Type matrix dimensions (M x N): ";
    std::cin >> m >> n;

    int num;
    std::vector<int> values;
    std::cout << "Type linked list values (-1 to stop): ";
    while (std::cin >> num && num != -1) {
        values.push_back(num);
    }

    ListNode* head = createLinkedList(values);

    std::vector< std::vector<int> > matrix = spiralMatrix(m, n, head);

    std::cout << "Generated Matrix:\n";
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }

    return 0;
}