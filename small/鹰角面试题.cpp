int findTarget(vector<int>& nums, int target){
    int left = 0;
    int n = nums.size();
    int right = n - 1;
    while(left < right){
        mid = left + (right - left) / 2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    retunr -1;
}

int findTargett(vector<int>& nums, int k){
    priority_queue<int> q;

}

float a = 3.123456789f;
float b = 3.123456787f;
float c = 1.0f / 3.0f;
double d = 1.0 / 3.0;

class Test{
    public Test();
    public virtual void TestFunction1;
    public virtual void TestFunction2;
    public float a;
}
class Test2 : Test{
    public void TestFunction1;
    public void TestFunction2;
    public bool b;
    public int c;
}