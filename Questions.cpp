// Problem No. - 1
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>temp;
     for(int i=0;i<nums.size();i++){
         for(int j=i+1;j<nums.size();j++){
             if(nums[i]+nums[j]==target){
             temp.push_back(i);
             temp.push_back(j);
                 return temp;
                 
             }
         }
     }
 return temp;
    }
};

// Problem No. - 2


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l3=new ListNode(0);
        ListNode *head=l3;
        int carry=0;
        while(l1 && l2){
            
            int val=l1->val + l2->val +carry;
            carry=val/10;
            l3->next=new ListNode(val%10);
            l3=l3->next;
            l2=l2->next;
            l1=l1->next;
        }
        while(l1){
                 
            int val=l1->val +carry;
            carry=val/10;
            l3->next=new ListNode(val%10);
            l3=l3->next;
            l1=l1->next;
        
            }
        while(l2){
             
            int val= l2->val +carry;
            carry=val/10;
            l3->next=new ListNode(val%10);
            l3=l3->next;
            l2=l2->next;
        }
        
        if(carry){
            l3->next=new ListNode(carry);
        }
        return head->next;
        
    }
};


// Problem No. - 3

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastIndex;  
        int left = 0; 
        int maxLength = 0;  

        for (int right = 0; right < s.size(); ++right) {
            char currentChar = s[right];
            if (lastIndex.find(currentChar) != lastIndex.end()) {
                left = max(left, lastIndex[currentChar] + 1);
            }

            lastIndex[currentChar] = right;
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};

// Problem No. - 11

class Solution {
public:
    int maxArea(vector<int>& height) {
        int start=0;
        int end=height.size()-1;
        int maxarea=0;
        while(start < end){
            int mini=min(height[start],height[end]);
            int area=(end - start) * mini;
            maxarea=max(area,maxarea);
            if(height[start] < height[end]){
                start++;
            }
            else{
                end--;
            }
            
            
        }
        return maxarea;
    }
};


// Problem No. - 13


class Solution {
public:
    int num(char ch){
        if(ch == 'I'){
            return 1;
        }
        else if(ch == 'V'){
            return 5;
        }
        else if(ch == 'X'){
            return 10;
        }
        else if(ch == 'L'){
            return 50;
        }
        else if(ch == 'C'){
            return 100;
        }
        else if(ch == 'D'){
            return 500;
        }
        else if(ch == 'M'){
            return 1000;
        }
        return 0;
    }
    int romanToInt(string s) {
        int i=0;
        int sum=0;
        while(i < s.size()-1){
            if(num(s[i]) < num(s[i+1])){
                sum-=num(s[i]);
            }
            else{
                sum+=num(s[i]);
            }
            i++;
        }
        sum+=num(s[i]);
        return sum;
    }
};

// Problem No. - 15

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;

        for(int i = 0; i < n; i++) {
            int j = i + 1;
            int k = n - 1;
            if(i > 0 && nums[i] == nums[i-1]) continue;

            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if(sum < 0) {
                    j++;
                } else if(sum > 0) {
                    k--;
                } else {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);

                    while(j < k && nums[j] == nums[j+1]) j++;
                    while(j < k && nums[k] == nums[k-1]) k--;

                    j++;
                    k--;
                }
            }
        }
        return ans;
    }
};


// Problem No. - 19

class Solution {
public:
    int Size(ListNode *head){
        ListNode *temp = head;
        int count = 0;
        while (temp != NULL) {
            temp = temp->next;
            count++;
        }
        return count;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = Size(head);
        int k = size - n;
        
        if (k == 0) {
            ListNode* temp = head;
            head = head->next;  
            delete temp;        
            return head;
        }

        ListNode *curr = head->next;
        ListNode *prev = head;
        for (int i = 0; i < k - 1; i++) {
            curr = curr->next;
            prev = prev->next;
        }

        prev->next = curr->next;  
        delete curr;              
        return head;
    }
};



// Problem No. - 20
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(ch=='(' || ch=='[' || ch=='{'){
                stk.push(ch);
            }
            else{
                if(stk.empty()){
                    return false;
                }
                if((stk.top()=='(' && ch==')') ||
                   (stk.top()=='[' && ch==']') ||
                   (stk.top()=='{' && ch=='}'))
                {
                    stk.pop();
                }
                else{
                    return false; 
                }
            }
        }
        if(!stk.empty()){
        return false;
        }
        else{
        return true;
        }
        }
};

// Problem No. - 21 

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {  
       ListNode *l3=new ListNode(0);
        ListNode *head=l3;
        while(list1 && list2){
            if(list1->val<=list2->val){
                l3->next=new ListNode(list1->val);
                list1=list1->next;
                l3=l3->next;
            }else{
                l3->next=new ListNode(list2->val);
                 list2=list2->next;
                l3=l3->next;
            }
        }
        while(list1){
             l3->next=new ListNode(list1->val);

             list1=list1->next;
            l3=l3->next;
        }
        while(list2){
        l3->next=new ListNode(list2->val);

             list2=list2->next;
            l3=l3->next;
       
        }
        return head->next;
    }
};


// Problem No. - 24

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *temp=head;
        while(temp != NULL && temp->next != NULL ){
            swap(temp->val,temp->next->val);
            temp=temp->next->next;
        }
        return head;
    }
};


// Problem No. - 26

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int j=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i] != nums[i-1]){
                nums[j]=nums[i];
                j++;
            }
        }
        return j;
        
        
    }
};

// Problem No. - 27

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val){
                nums[k]=nums[i];
                k++;
            }
        }
        return k;
    }
};


// Problem No. - 42

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int leftmax[20000];
        int rightmax[20000];
        leftmax[0]=height[0];
        rightmax[n-1]=height[n-1];
        
        for(int i=1;i<n;i++){
             leftmax[i]=max(leftmax[i-1],height[i-1]);
        }
        for(int i=n-2;i>=0;i--){
         rightmax[i]=max(rightmax[i+1],height[i+1]);   
        }
        int total=0;
        for(int i=0;i<n;i++){
            int sum=min(leftmax[i],rightmax[i])-height[i];
            if(sum>0){
                total=total+sum;
            }
        }
        return total;
        
    }
};


// Problem No. - 48


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};

// Problem No. - 53 ->Kadane's algo 

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    int maxsum=-238753;
    int sum=0;
    for(int start=0;start<nums.size();start++){
        sum+=nums[start];
        maxsum=max(maxsum,sum);
        if(sum<0){
            sum=0;
        }
    }
        return maxsum;
    }
};

// Problem No. - 61 

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        ListNode *temp = head;
        int count = 1; 
        while (temp->next != NULL) {
            count++;
            temp = temp->next;
        }
        temp->next = head;

        k = k % count;
        int rotation = count - k; 

        temp = head;
        for (int i = 1; i < rotation; i++) {
            temp = temp->next;
        }

        head = temp->next;
        temp->next = NULL;

        return head;
    }
};

// Problem No. - 73

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> row(n, 0);
        vector<int> col(m, 0);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (row[i] == 1 || col[j] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};


// Problem No. - 74

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& vect, int target) {
   for (int i = 0; i < vect.size(); i++)  
    { 
        for (int j = 0; j < vect[i].size(); j++) 
        { 
            if(vect[i][j]==target){
                return true;
            }
        }     
        
    } 
        return false;
    }
};

// Problem No. - 75 

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=n=nums.size();
        int low=0;
        int mid=0;
        int high=n-1;
        
        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[mid],nums[low]);
                mid++;
                low++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
        
    }
};

// Problem No. - 81

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                return true;
            }
        }
        return false;
        
    }
};

// Problem No. -83 

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *temp=head;
        
        while(temp != NULL && temp->next != NULL){
            if(temp->next->val == temp->val){
                
                temp->next=temp->next->next;
                
            }    
            else{
                
                temp=temp->next;
                
            }
        }
     return head;   
    }
};

// Problem No. - 88 

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1; 
        int j = n - 1; 
        int k = m + n - 1; 
        
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
        
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};


// Problem No. - 92

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head) return nullptr;
        
        ListNode *dummy = new ListNode(0); 
        dummy->next = head;
        ListNode *prev = dummy;
        
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }
        
        //Reverse process
        ListNode *curr = prev->next; 
        ListNode *next = nullptr;
        ListNode *end = curr; 
        
        for (int i = 0; i < right - left; i++) {
            next = curr->next;
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }
        
        return dummy->next;
    }
};

// Problem No. - 94

class Solution {
public:
    
    void list(TreeNode *root,vector<int> &temp){
        if(root == NULL){
            return;
        }
        list(root->left,temp);
        temp.push_back(root->val);
        list(root->right,temp);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> temp;
        list(root,temp);
        return temp;
    }
};

// Problem No. - 102

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root){
            return result;
        } 
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int levelSize = q.size(); 
            vector<int> currentLevel;
            
            for (int i = 0; i < levelSize; i++) {
                TreeNode* curr = q.front();
                q.pop();
                currentLevel.push_back(curr->val); 
                
                if (curr->left) {
                    q.push(curr->left);
                }
                if (curr->right) {
                    q.push(curr->right);
                }
            }
            result.push_back(currentLevel); 
        }
        
        return result; // Return the level order traversal
    }
};

// Problem No. - 104

class Solution {
public:
    int maxDepth(TreeNode* root) {
        
        if(root==NULL){
        return 0;    
        }
        int leftdepth=maxDepth(root->left);
        int rightdepth=maxDepth(root->right);
        return max(leftdepth,rightdepth)+1;
        
    }
};

// Problem No. - 111

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        if (root->left == NULL) {
            return minDepth(root->right) + 1;
        }
        if (root->right == NULL) {
            return minDepth(root->left) + 1;
        }

        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};

// Problem No. - 118

class Solution {
public:
    vector<int> generaterow(int n){
        vector<int> temp;
        long long ans=1;
        temp.push_back(1);
        for(int i=1;i<n;i++){
            ans = ans * (n-i);
            ans = ans/i;
            temp.push_back(ans);
        }
        return temp;
    }
    
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1;i<=numRows;i++){
            ans.push_back(generaterow(i));
        }
        
        return ans;
    }
};

// Problem No. - 119

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        long long ans=1;
        vector<int> temp;
        temp.push_back(1);
        for(int i=1;i<=rowIndex;i++){
            ans=ans * (rowIndex-i+1);
            ans=ans/i;
            temp.push_back(ans);
        }
        return temp;
    }
};

// Problem No. - 121

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int bestbuy[100000];
        bestbuy[0]=INT_MAX;
        for(int i=1;i<n;i++){
            bestbuy[i]=min(bestbuy[i-1],prices[i-1]);
        }
        int sum=0;
        for(int i=0;i<n;i++){
            int currsum=prices[i]-bestbuy[i];
            sum=max(sum,currsum);
        }
        
        return sum;
    }
};

// Problem No. - 125

class Solution {
public:
    bool palindrome(string ans) {
        int start = 0;
        int end = ans.size() - 1;
        while(start < end) {
            if(ans[start] != ans[end]) {  
                return false;
            }
            start++;
            end--; 
        }
        return true;
    }

    bool isPalindrome(string s) {
        string ans = "";
    
        for(int i = 0; i < s.size(); i++) {
            if(isalnum(s[i])) { 
                ans += tolower(s[i]); 
            }
        }
    
        return palindrome(ans);
    }
};

// Problem No. - 141 

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast != NULL && fast->next != NULL){
        
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow==fast){
                return true;            
            }
        }
        return false;
        
    }
};

// Problem No. - 142

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return NULL;
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) { 
                ListNode *start = head;
                while (start != slow) {
                    start = start->next;
                    slow = slow->next;
                }
                return start;  
            }
        }
        
        return NULL; 
    }
};

// Problem No. - 143

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        ListNode *temp = head;
        stack<ListNode*> s;
        while (temp != NULL) {
            s.push(temp);
            temp = temp->next;
        }

        ListNode *helper = head;
        ListNode *nexti;
        int count = s.size() / 2;

        while (count--) {
            ListNode *last = s.top(); 
            s.pop();

            nexti = helper->next;     
            helper->next = last;      
            last->next = nexti;    
            helper = nexti;      
        }
        helper->next = nullptr; 
    }
};


// Problem No. - 144
class Solution {
public:
    
    void helper(TreeNode *root,vector<int> &temp){
        if(root == NULL){
            return;
        }
        temp.push_back(root->val);
        helper(root->left,temp);
        helper(root->right,temp);
        
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> temp;
        helper(root,temp);
        return temp;
    }
};


// Problem No. - 145

class Solution {
public:
    
    void helper(TreeNode *root,vector<int> &temp){
        if(root == NULL){
            return;
        }
        helper(root->left,temp);
        helper(root->right,temp);
        temp.push_back(root->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> temp;
        helper(root,temp);
        return temp;
    }
};

// Problem No. - 283 
class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int idx = 0; 
        
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] != 0) {
                swap(arr[idx], arr[i]);
                idx++;
            }
        }
    }
};



// Problem No. 268
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum1 = 0;
           sum1 = (n * (n+1))/2;
        int sum2 = 0;
        for(int i=0;i<n;i++){
            sum2 += nums[i];
        }
        return sum1 - sum2;
    }
};


//problem No. 485
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxi = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 1){
                count++;
                maxi=max(count,maxi);
            }
            else{
                count=0;
            }
        }
        return maxi;
    }
};

//problem No. 3151

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n=nums.size();
        if(nums.size()==1){
            return true;
        }
        if(nums.size()==2){
            if(nums[0]%2 == nums[1]%2){
                return false;
            }
        }
        for(int i=1;i<n-1;i++){
            if((nums[i-1]%2) == (nums[i]%2) || (nums[i+1]%2) == (nums[i]%2)){
                return false;
            }
        }
        return true;
    }
};


//problem No. 905

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> temp;
         vector<int> temp2;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                temp.push_back(nums[i]);
            }else{
                temp2.push_back(nums[i]);
            }
        }
        for(int i=0;i<temp2.size();i++){
            temp.push_back(temp2[i]);
        }
        return temp;
    }
};

//problem No. 1480
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for(int i=1;i<nums.size();i++){
            nums[i]=nums[i]+nums[i-1];
        }
        return nums;
    }
};

//problem No. 1004
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0;
        int r=0;
        int zeros=0;
        int maxi=0;
        int length=0;
        while(r < nums.size()){
            if(nums[r] == 0) zeros++;
            
            
            while(zeros > k){
                if(nums[l] == 0) zeros--;
                l++;
            }
            length=r-l+1;
            maxi=max(maxi,length);
            r++;
        }
        
        return maxi;
    }
};

//problem No. 1446


class Solution {
public:
    int maxPower(string s) {
        int maxi=0;
        for(int i=0;i<s.size();i++){
            int j=i+1;
            while(j < s.size() && s[j] == s[j-1]) j++;
            maxi=max(maxi,j-i);
        }
        return maxi;
    }
};