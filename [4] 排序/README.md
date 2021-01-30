## 排序算法总结

常用的排序算法

### 快速排序(Quick sort)

采用左闭右闭的二分写法

```c++

```

### 归并排序(Merge sort)

```c++

```

### 插入排除(Insertion sort)



### 冒泡排序(Bubble sort)


### 选择排序(Selection sort)


以上排序算法的调用方法为

```c++
vector<int> nums = {1,3,5,7,2,6,4,8,9,2,8,7,6,0,3,5,9,4,1,0};
vector<int> temp(nums.size());
sort(nums.begin(), nums.end());
quick_sort(nums, 0, nums.size());
merge_sort(nums, 0, nums.size(), temp);
insertion_sort(nums, nums.size());
bubble_sort(nums, nums.size());
selection_sort(nums, nums.size());
```

