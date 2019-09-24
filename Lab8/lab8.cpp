#include<bits/stdc++.h>
using namespace std;

double median(vector<double> vec)
{

    double median;
    size_t size = vec.size();
    median = vec[(size/2)];
    return median;
}

double mom(vector<vector<double> > values)
{
    vector<double> medians;

    for (int i = 0; i < values.size(); i++)
    {
        double m = median(values[i]);
        medians.push_back(m);
    }

    return median(medians);
}

double select(const vector<double> values, int k)
{

    vector<vector<double> > vec2D;

    int count = 0;
    while (count != values.size())
    {
        int countRow = 0;
        vector<double> row;

        while ((countRow < 5) && (count < values.size()))
        {
            row.push_back(values[count]);
            count++;
            countRow++;
        }
        vec2D.push_back(row);
    }
    double m = mom(vec2D);
    vector<double> arr, arr2;

    for (int i = 0; i < vec2D.size(); i++)
    {
        for (int j = 0; j < vec2D[i].size(); j++)
        {
            if (vec2D[i][j] > m)
            {
                arr.push_back(vec2D[i][j]);
            }
            else if (vec2D[i][j] < m)
            {
                arr2.push_back(vec2D[i][j]);
            }
        }
    }

    if ((k - 1) == arr.size())
    {
        return m;
    }
    else if (k <= arr.size())
    {
        return select(arr, k);
    }
    else if (k > (arr.size() + 1))
    {
        return select(arr2, k-((int)arr.size())-1);
    }

}

int main()
{
int t;
cin>>t;
while(t--)
{
   int n;
   cin>>n;
   int x,y;
   vector<double>radii;
   radii.clear();
   for(int i=0;i<n;i++)
   {
       cin>>x>>y;
       radii.push_back(sqrt(x*x+y*y));
   }


        double ans=select(radii,radii.size()+1-(radii.size()+1)/2);
        cout<<ans<<endl;
}





    return 0;
}
