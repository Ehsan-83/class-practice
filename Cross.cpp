#include <iostream>
#include <vector>
#include <sstream>


using namespace std;

void set_size(int &row1, int &column1,int &row2,int &column2);
void set_mat(vector<vector<double>> &array,const int row,const int column);
void Cross(vector<vector<double>> &matrix1,const int row1,const int column1,vector<vector<double>> &matrix2,const int row2,const int column2,vector<vector<double>> &matrix3);
void show(vector<vector<double>> matrix);

int main(){
    int row1,column1,row2,column2;
    set_size(row1,column1,row2,column2);
    cin.ignore();
    if (column1 != row2)
    {
        cout << "Cross can not be done!";
        return 0;
    }

    vector<vector<double>> matrix1;
    vector<vector<double>> matrix2;
    vector<vector<double>> result;

    cout<<"Matrix 1:\n";
    set_mat(matrix1,row1,column1);
    cout<<"Matrix 2:\n";
    set_mat(matrix2,row2,column2);

    Cross(matrix1,row1,column1,matrix2,row2,column2,result);

    show(result);

    return 0;
}
void set_size(int &row1, int &column1,int &row2,int &column2)
{

    while (true)
    {
        cout << "How many rows for first matrix? ";
        cin >> row1;
        cout << "How many columns for first matrix? ";
        cin >> column1;

        cout << "How many rows for second matrix? ";
        cin >> row2;
        cout << "How many columns for second matrix? ";
        cin >> column2;
        if (row1 < 6 && column1 < 6 && row2 < 6 && column2 < 6)
        {
            break;
        }
        cout << "Rows and columns can not be more than 5. Try again!\n";
    }
}
void set_mat(vector<vector<double>> &array,const int row,const int column)
{
    cout << "*****************\n";
    cout<<"Enter numbers respectively and separate them with space (each row must have "<<column<<" element(s)!)\n";

    for (int i = 0; i < row; i++)
    {
        string text = "";
        double num, j = 0;

        cout << "row" << i + 1 << ": ";
        getline(cin, text);
        stringstream ss(text);
        array.push_back({});
        while (ss >> num)
        {
            array[i].push_back(num);
            j++;
        }
        if(j!=column){
            cout<<"number of columns does not match\n";
            throw;
        }
        for(int i=0;i<text.length();i++){
            if(isalpha(text[i])){
                cout<<"Only numbers are allowed\n";
                throw;
            }
        }
    }
    cout << '\n';
}
void Cross(vector<vector<double>> &matrix1,const int row1,const int column1,vector<vector<double>> &matrix2,const int row2,const int column2,vector<vector<double>> &matrix3)
{
    matrix3.resize(row1);
    for(int i=0;i<row1;i++){
        matrix3[i].resize(column2);
    }
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < column2; j++)
        {
            double temp = 0;
            for (int k = 0; k < column1; k++)
            {
                temp += matrix1[i][k] * matrix2[k][j];
            }
            matrix3[i][j] = temp;
        }
    }
}
void show(vector<vector<double>> matrix)
{
    cout<<"********************\nResult:\n";
    for (int i = 0; i < matrix.size(); i++)
    {
        cout<<"|";
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (j != matrix[i].size() - 1)
            {
                cout <<matrix[i][j]<<", ";
            }
            else
            {
                cout <<matrix[i][j];
            }
        }
        cout <<'\n';
    }
}