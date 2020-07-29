//Code_Nation.============================================

//Q.1.Element appearing once
//https://practice.geeksforgeeks.org/problems/element-appearing-once/0

#include <iostream>
using namespace std;

void fun(int arr[], int N)
{
    int ans;
    for (int i = 0; i < N; i++)
    {
        ans ^= arr[i];
    }
    cout << ans << endl;
}

int main()
{
    //code
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        int arr[101];
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        fun(arr, N);
    }

    return 0;
}

//Q.2.Count Smaller elements
//https://practice.geeksforgeeks.org/problems/count-smaller-elements/0

#include <iostream>
#include <vector>

using namespace std;

void fun(vector<int> arr, int N)
{
    vector<int> ans(N, 0);

    for (int i = 0; i < N - 1; i++)
    {

        for (int j = i + 1; j < N; j++)
        {
            if (arr[i] > arr[j])
            {
                ans[i]++;
            }
        }
    }
    for (int ele : ans)
    {
        cout << ele << " ";
    }
    cout << endl;
}

int main()
{
    //code
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        vector<int> arr(N, 0);
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        fun(arr, N);
    }

    return 0;
}

//Q.3.Implement Stack using Linked List
//  https://practice.geeksforgeeks.org/problems/implement-stack-using-linked-list/1

/*
The structure of the node of the stack is
struct StackNode
{
    int data;
    StackNode *next;
    StackNode(int a)
    {
        data = a;
        next = NULL;
    }
};

// And this is structure of MyStack
class MyStack {
private:
StackNode *top;
public :
    void push(int);
    int pop();
    MyStack()
    {
        top = NULL;
    }
};
*/

/* The method push to push element
   into the stack */
void MyStack ::push(int x)
{
    if (top == NULL)
    {
        top = new StackNode(x);
    }
    else
    {
        StackNode *ptr = new StackNode(x);
        ptr->next = top;
        top = ptr;
    }
}

/* The method pop which return the element
  poped out of the stack*/
int MyStack ::pop()
{
    if (top == NULL)
    {
        return -1;
    }
    else
    {
        StackNode *ptr = top;
        top = top->next;
        ptr->next = NULL;
        return ptr->data;
    }
}

//Q.4,Box Stacking
// https://practice.geeksforgeeks.org/problems/box-stacking/1


//Q.5.Rotating an Array
// https://practice.geeksforgeeks.org/problems/reversal-algorithm/0

#include <iostream>
#include <vector>

using namespace std;

void fun(vector<int> arr, int N, int d)
{
    vector<int> temp(d, 0);

    for (int i = 0; i < d; i++)
    {
        temp[i] = arr[i];
    }
    for (int j = 0, i = d; j < N - d, i < N; i++, j++)
    {
        arr[j] = arr[i];
    }
    for (int i = 0, j = N - d; i < d, j < N; i++, j++)
    {
        arr[j] = temp[i];
    }

    for (int ele : arr)
    {
        cout << ele << " ";
    }
    cout << endl;
}

int main()
{
    //code
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        vector<int> arr(N, 0);
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        int d = 0;
        cin >> d;
        fun(arr, N, d);
    }

    return 0;
}

//Q.6.The Painter's Partition Problem
// https://practice.geeksforgeeks.org/problems/the-painters-partition-problem/0


// #include <iostream>
// #include <vector>

// using namespace std;

// void fun(vector<int> arr, int N ,int K)
// {
//     int summ=0;
//     for(int i=0;i<N;i++){
//         summ += arr[i];
//     }
//     summ=summ/K;
    
//     int maxx=0;
    
//     for(int i=0;i<N;i++){
          
//      int req_summ=0;
//      while(req_summ <=summ){
//          req_summ+=arr[i];
//          i++;
//      }
//      K--;
//      if(K==0 && i!=N){
//          while(i<N){
//               req_summ+=arr[i];
//          i++;
//          }
//      }
//      maxx=max(maxx,req_summ);
//     }
    
//     cout<<maxx<<endl;
// }

// int main()
// {
//     //code
//     int T;
//     cin >> T;
//     while (T--)
//     {
//         int K;
//         cin >> K;
//         int N;
//         cin >> N;
//         vector<int> arr(N, 0);
//         for (int i = 0; i < N; i++)
//         {
//             cin >> arr[i];
//         }
//         fun(arr, N , K);
//     }

//     return 0;
// }


//Q.7.String with numbers at its end
// https://practice.geeksforgeeks.org/problems/string-with-numbers-at-its-end/0

#include <iostream>
#include <string>

using namespace std;

int fun(string str, int N)
{
    int strlength = 0;
    int num = 0;
    int flag = 0;
    int p = 1;
    for (int i = N - 1; i >= 0; i--)
    {
        char ch = str[i];
        if (ch >= '0' && ch <= '9' && flag == 0)
        {
            num += (ch - '0') * (p);
            p = p * 10;
        }
        else
        {
            strlength++;
            flag = 1;
        }
    }

    return (strlength == num) ? 1 : 0;
}

int main()
{
    //code
    int T;
    cin >> T;
    while (T--)
    {
        string str;
        cin >> str;
        int N = str.length();
        cout << fun(str, N) << endl;
    }

    return 0;
}
