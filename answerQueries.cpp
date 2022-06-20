#include <bits/stdc++.h>

using namespace std;

vector<int> answerQueries(vector<vector<int>> q, int n)
{
  vector<int> ans;
  vector<bool> arr(n, false);
  bool s;
  int cont = 0;

  for(int i = 0; i < n; i++)
  {
      s = false;

      if(q[i][0] == 1)
      {
        arr[q[i][1] - 1] = true;
      }
      else if(q[i][0] == 2)
      {
        cont = q[i][1] - 1;
        while(cont < n)
        {
            if(arr[cont] == true)
            {
                ans.push_back(cont+1);
                s = true;
            }
            cont++;
        }

        if(s == false)
        {
            ans.push_back(-1);
        }
      }
  }
  return ans;
}

int main()
{
  int n;
  int q;
  int in;
  
  cin >> n;
  cin >> q;

  vector<vector<int>> queries(q, vector<int>(2));

    for(int i = 0; i < q; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            cin >> in;
            queries[i][j] = in;
        }
    }

  vector<int> ans;
  
  ans = answerQueries(queries, n);

  for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}

/*
5
5
2 3
1 2
2 1
2 3
2 2
*/