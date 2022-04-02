#include <iostream>
#include <vector>

using namespace std;

long int Sum(vector<int> v) {
    long int sum = 0;
    for (int i = 0 ; i < v.size() ; i++)
    sum += v[i];
    return sum;
}


int solve(int row_size, int col_size,vector<vector<int>> farm){
    int result = 0;
    int sum = 0;
    int max_row = 0;
    int max_column = 0;
    int row = 0;
    int column = 0;

    for(int move = 0 ; move < 4 ; move++) {
        vector<int> row_sums;

        for(int i = 0 ; i < row_size ; i++){
            sum = Sum(farm[i]);
            row_sums.push_back(sum);
            sum = 0;
        }

        for(int i = 0 ; i < row_size ; i++){
            if (row_sums[i] > max_row) {
                max_row = row_sums[i];
                row = i;
            }
        }

        for(int j = 0 ; j < col_size ; j++){
            for(int i = 0 ; i < row_size ; i++){
                sum += farm[i][j];
            }
            if(sum > max_column){
                max_column = sum;
                column = j;
            }
            sum = 0;
        }
        if(max_column > max_row){
            result += max_column;
            for(int i = 0 ; i < row_size ; i++){
                farm[i][column] = 0;
            }
        }
        else{
            result += max_row;
            for(int j = 0 ; j < col_size ; j++){
                farm[row][j] = 0;
            }
        }
        row = 0;
        column = 0;
        max_column = 0;
        max_row = 0;
    }
    return result;
}

vector<vector<int>> get_farm_map(int row_size, int col_size){
    vector<vector<int>> farm;
    farm = vector<vector<int>> (row_size, vector<int>(col_size));
    for(int i = 0 ; i < row_size ; i++){
        for(int j = 0 ; j < col_size ; j++){
            int product_weight;
            cin >> product_weight;
            farm[i][j] = product_weight;
        }
    }
    return farm;
}

int main() {
    int row_size, col_size;
    cin >> row_size >> col_size;
    vector<vector<int>> farm;
    farm = get_farm_map(row_size, col_size);
    int max_harvest_amount;
    max_harvest_amount = solve(row_size, col_size, farm);
    cout << max_harvest_amount;
    return 0;
    cout << "Hello there! I'm unreachable!" << endl;
}
