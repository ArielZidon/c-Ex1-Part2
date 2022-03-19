#include "mat.hpp"
#include<iostream>
#include<string>
#include<stdexcept>
#include<vector>

using namespace std;
namespace ariel{
    string mat(int c,int r, char s1,char s2)
    {
        vector<vector<int>> matrix1(r,vector<int>(c));
        vector<vector<int>> matrix2(r,vector<int>(c));
        if(r<=0 || c<=0)
        {
            throw runtime_error("cant be negativ");
        }
        
        if(r%2==0 || c%2==0)
        {
            throw runtime_error("cant be even num");
        }

        string M;

        int i = 0;
        int j = 0;
        
        for(i = 0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                matrix1[i][j] = min(i,j);
                matrix2[i][j] = min(r-i-1,c-j-1);
                matrix1[i][j] = min(matrix1[i][j],matrix2[i][j]);            
            }
        }

        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                if(matrix1[i][j]%2==0)
                {
                    M+=s1;
                }
                else
                {
                    M+=s2;
                }
            }
            if(i!=r-1)
            {
                M+='\n';
            }

        }
    return M;
    }
}