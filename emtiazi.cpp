#include <iostream>
#include <vector>

using namespace std;

const int FARMED = 0;

long int calculate_row_sum(int row_index, vector<vector<int>> farm){
    long int result = 0;
    for(int i=0 ; i<farm[0].size() ; i++){
        result += farm[row_index][i];
    }
    return result;
}

int get_max_row_sum_index(vector<vector<int>> farm) {
    long int save_max_amount = 0;
    int save_index = 0;
    for(int i=0 ; i<farm.size() ; i++){
        if(calculate_row_sum(i, farm) > save_max_amount){
            save_index = i;
            save_max_amount = calculate_row_sum(i ,farm);
        }
    }
    return save_index;
}

long int calculate_col_sum(int col_index, vector<vector<int>> farm){
    long int result = 0;
    for(int i=0 ; i<farm.size() ; i++){
        result += farm[i][col_index];
    }
    return result;
}

int get_max_col_sum_index(vector<vector<int>> farm) {
    long int save_max_amount = 0;
    int save_index = 0;
    for(int i=0 ; i<farm[0].size() ; i++){
        if(calculate_col_sum(i, farm) > save_max_amount){
            save_index = i;
            save_max_amount = calculate_col_sum(i ,farm);
        }
    }
    return save_index;
}

long int add_harvest_amount(int row, int col, vector<vector<int>> farm){
    if(calculate_row_sum(row, farm) > calculate_col_sum(col, farm)){
        return calculate_row_sum(row, farm);
    }
    else{
        return calculate_col_sum(col, farm);
    }
}

vector<vector<int>> harvest_most(int row, int col, vector<vector<int>> farm){
    if(calculate_row_sum(row, farm) > calculate_col_sum(col, farm)){
        for(int i=0 ; i<farm[0].size() ; i++){
            farm[row][i] = FARMED;
        }
    }
    else{
        for(int i=0 ; i<farm.size() ; i++){
            farm[i][col] = FARMED;
        }
    }
    return farm;
}

long int solve(int row_size, int col_size,vector<vector<int>> farm){
    long int harvest_weight = 0;
    for(int move = 0 ; move < 4 ; move++) {
        int max_row_index = 0;
        max_row_index = get_max_row_sum_index(farm);
        int max_col_index=0;
        max_col_index = get_max_col_sum_index(farm);
        harvest_weight += add_harvest_amount(max_row_index, max_col_index, farm);
        farm = harvest_most(max_row_index, max_col_index, farm);
    }
    return harvest_weight;
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
    long int max_harvest_amount;
    max_harvest_amount = solve(row_size, col_size, farm);
    cout << max_harvest_amount;
    return 0;
    cout << "Hello there! I'm unreachable!" << endl;
}
