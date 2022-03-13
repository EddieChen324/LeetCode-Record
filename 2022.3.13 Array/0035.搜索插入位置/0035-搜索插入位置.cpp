class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        // if (nums[0] > target) {
        //     return 0;
        // }
        // if (nums[right] < target) {
        //     return right + 1;
        // }
        while (left <= right) {
            int middle = left + ((right - left) / 2);
            if (nums[middle] < target) {
                left = middle + 1;
            }
            if (nums[middle] > target) {
                right = middle -1;
            }
            if (nums[middle] == target) {
                return middle;
            }
            // if (nums[middle] > target && nums[middle - 1] < target) {
            //     return middle;
            // }
        }
        return right + 1;
    }
};

// class Solution {
// public:
//     int searchInsert(vector<int>& nums, int target) {
//         int n = nums.size();
//         int left = 0;
//         int right = n - 1; // ����target������ұյ������[left, right]
//         while (left <= right) { // ��left==right������[left, right]��Ȼ��Ч
//             int middle = left + ((right - left) / 2);// ��ֹ��� ��ͬ��(left + right)/2
//             if (nums[middle] > target) {
//                 right = middle - 1; // target �������䣬����[left, middle - 1]
//             } else if (nums[middle] < target) {
//                 left = middle + 1; // target �������䣬����[middle + 1, right]
//             } else { // nums[middle] == target
//                 return middle;
//             }
//         }
//         // �ֱ��������������
//         // Ŀ��ֵ����������Ԫ��֮ǰ  [0, -1]
//         // Ŀ��ֵ����������ĳһ��Ԫ��  return middle;
//         // Ŀ��ֵ���������е�λ�� [left, right]��return  right + 1
//         // Ŀ��ֵ����������Ԫ��֮������ [left, right]�� return right + 1
//         return right + 1;
//     }
// };