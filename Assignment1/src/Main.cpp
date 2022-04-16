#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

//Pre-definition of functions
int** My2DArray(int N);

//Pre-definition of vectors variables
//This vector of vectors
// created to keep linked elements
vector <vector <int> > connected_elements;
vector<int> row_column2;
int counter3 = 0;

void looking_for_connection(int row, int column, int point,int N ,int **MyGrid);
bool does_contain(vector< vector< int > >, int ,int );

int** My2DArray(int N){
    int** array2D = nullptr;
    array2D = new int *[N];

    for(int h = 0 ; h < N; h++){
        array2D[h] = new int[N];
        for(int w = 0; w < N; w++){
            array2D[h][w] = 0;
        }
    }
    return array2D;
}

//Shows whether element is in
// linked elements group or not
bool does_contain(vector<vector<int >>connected_elements, int row_new,int column_new){

    for(const auto  &item :  connected_elements){
        if(item.at(0) == row_new && item.at(1) == column_new){
            //if it contains the element it returns 0
            return 0;
        }
    }
    //it returns 1 if connected_elements doens't contain the element
    return 1;

}

//LOOKS AROUND THE ELEMENT
void looking_for_connection(int row, int column, int point,int N,int **MyGrid){


    //ADDING TO THE LINK VECTOR
    //Re-creating the row_column2 vector

    row_column2.clear();
    row_column2.push_back(row);
    row_column2.push_back(column);

    //pushing to the main vector
    connected_elements.push_back(row_column2);


    if(column != 0 ){
        if(does_contain(connected_elements,row,column-1) && MyGrid[row][column-1] == MyGrid[row][column] ){
            looking_for_connection(row,column-1,point,N,MyGrid);
        }
    }

    if(row != 0){
        if(does_contain(connected_elements,row-1,column) && MyGrid[row-1][column] == MyGrid[row][column]){
            looking_for_connection(row-1,column,point,N,MyGrid);
        }
    }

    if(column != N-1){

        if(does_contain(connected_elements,row,column+1) && MyGrid[row][column+1] == MyGrid[row][column] ){
            looking_for_connection(row,column+1,point,N,MyGrid);
        }
    }
    if(row != N-1){
        if(does_contain(connected_elements,row+1,column) && MyGrid[row+1][column] == MyGrid[row][column]){
            looking_for_connection(row+1,column,point,N,MyGrid);
        }
    }
}

//int main() function with argv
int main(int argc, char* argv[]) {

    //READING FROM FILE INTO AN VECTOR
    ifstream readData(argv[1], ios::in);

    string str;
    vector<string> numbers;
    int count1 = 0;
    while (getline(readData, str)) {
        if (str.size() > 0) {
            count1++;
            numbers.push_back(str);
        }

    }
    readData.close();

    //Stoi function converts string to an int
    int N = stoi(numbers.at(0));

    //Creating Array
    int **MyGrid = (My2DArray(N));

    //SPLITTING THE STRING
    vector<vector<int> > tokens_main;
    int count2 = 0;
    for (int k = 1; k < count1; k++) {

        vector<int> tokens;
        stringstream check1(numbers.at(k));
        string intermediate;

        while (getline(check1, intermediate, ' ')) {
            tokens.push_back(stoi(intermediate));
            if (tokens.size() == 3) {
                tokens_main.push_back(tokens);
                count2++;
            }
        }
    }

    //LINE BY LINE PLACING ELEMENTS

    for (int i = 0; i < count2; i++) {
        //INITIALIZING ROW,COLUMN AND POINT VARIABLES
        int row1 = 0;
        int column1 = 0;
        int point = 0;

        //TAKING POINT ELEMENT
        point = tokens_main.at(i).at(0);

        //TAKING ROW ELEMENT
        row1 = tokens_main.at(i).at(1);

        //TAKING COLUMN ELEMENT
        column1 = tokens_main.at(i).at(2);


        //ASSIGNING POINT ELEMENT TO THE 2D ARRAY
        MyGrid[row1][column1] = point;

        //Checks around the element
        connected_elements.clear();
        //row_column2.clear();
        //row_column2.push_back(row1);
        //row_column2.push_back(column1);
        looking_for_connection(row1, column1, point, N, MyGrid);
        //connected_elements.push_back(row_column2);


        while(connected_elements.size() >= 3){
            for(const auto &item : connected_elements){
                if(item.at(0) == row1 && item.at(1) == column1){
                    point++;
                    MyGrid[row1][column1] = point;
                }
                else{
                    MyGrid[item.at(0)][item.at(1)] = 0;
                }
            }
            //reset the vector that shows whether element is in
            //linked elements group or not

            connected_elements.clear();

            //checks around element with new position
            looking_for_connection(row1,column1,point,N,MyGrid);
        }

        //reset the vector that shows whether element is in
        //linked elements group or not
        connected_elements.clear();
    }


    //Opens a file for to write
    ofstream output;
    output.open(argv[3],ios::out);

    //PRINTING 2D ARRAY
    output << "PART 1:" << endl;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){

            output << MyGrid[i][j];

            output <<" ";
        }
        output <<"\n";
    }


    //PART2

    //READING FROM FILE INTO AN VECTOR

    ifstream readData2(argv[2],ios::in);
    string str2;
    vector<string> numbers2;
    while(getline(readData2, str2))
    {
        if(str2.size() > 0){
            numbers2.push_back(str2);
        }

    }

    readData2.close();

    int N2 = stoi(numbers2.at(0));

    //SPLITTING THE STRING

    //TOKENS_MAIN2 vector is FOR ARRAY
    vector <vector <int> > tokens_main2;
    for(int k=1; k <= N2; k++) {
        vector<int> tokens2;
        stringstream check1 (numbers2.at(k));
        string intermediate2;
        while(getline(check1, intermediate2, ' ')){
            tokens2.push_back(stoi(intermediate2));

            if (tokens2.size() == N2){
                tokens_main2.push_back(tokens2);
            }

        }
    }

    //BOMB_LIST vector is Bombs it contains bomb's places
    vector <vector <int> > bomb_list;
    for(int k = N2 + 1; k < numbers2.size(); k++){
        vector<int> tokens2;
        stringstream check1 (numbers2.at(k));
        string intermediate2;
        while(getline(check1, intermediate2, ' ')){
            tokens2.push_back(stoi(intermediate2));

            if (tokens2.size() == 2){
                bomb_list.push_back(tokens2);
            }

        }
    }
    /*
    //TESTING BOMB_LIST

    for(int i =0; i < bomb_list.size(); i++){
        for (int j=0; j < bomb_list.at(i).size(); j++){
            cout << bomb_list.at(i).at(j);
            cout << " ";
        }
        cout << "\n";
    }*/

    int** MyGrid2 = My2DArray(N2);

    for(int i =0; i < tokens_main2.size(); i++){
        for (int j=0; j < tokens_main2.at(i).size(); j++){
            MyGrid2[i][j] = tokens_main2.at(i).at(j);
        }
    }

    int bomb;
    int total_point = 0;
    int k;
    for (k=0; k < bomb_list.size(); k++){

        bomb = MyGrid2[bomb_list.at(k).at(0)][bomb_list.at(k).at(1)];

        if(bomb == 0 ){
            continue;
        }
        //Because of the bomb
        int count_zeros = 1;

        //CHECKING LEFT-RIGHT
        for(int i=0; i < N2 ; i++){
            if(MyGrid2[bomb_list.at(k).at(0)][i] == bomb && i != bomb_list.at(k).at(1)){
                count_zeros++;
                MyGrid2[bomb_list.at(k).at(0)][i] = 0;
            }
        }
        //CHECKING TOP-DOWN
        for(int i = 0; i <N2; i++){
            if(MyGrid2[i][bomb_list.at(k).at(1)] == bomb && i != bomb_list.at(k).at(0)){
                count_zeros++;
                MyGrid2[i][bomb_list.at(k).at(1)] = 0;
            }
        }

        //LOWER RIGHT CHECK
        for(int i = bomb_list.at(k).at(0)+1, j = bomb_list.at(k).at(1)+1; i < N2 && j < N2; i++, j++){
            if(MyGrid2[i][j] == bomb){
                count_zeros++;
                MyGrid2[i][j] = 0;
            }
        }

        //UPPER LEFT CHECK
        for(int i = bomb_list.at(k).at(0)-1, j = bomb_list.at(k).at(1)-1; i >= 0 && j >= 0; i--, j--){
            if(MyGrid2[i][j] == bomb){
                count_zeros++;
                MyGrid2[i][j] = 0;
            }
        }

        //LOWER LEFT CHECK
        for(int i = bomb_list.at(k).at(0)+1, j = bomb_list.at(k).at(1)-1; i < N2 && j >= 0; i++, j--){
            if(MyGrid2[i][j] == bomb){
                count_zeros++;
                MyGrid2[i][j] = 0;
            }
        }

        //UPPER RIGHT CHECK
        for(int i = bomb_list.at(k).at(0)-1, j = bomb_list.at(k).at(1)+1; i >= 0 && j < N2; i--, j++){
            if(MyGrid2[i][j] == bomb){
                count_zeros++;
                MyGrid2[i][j] = 0;
            }
        }


        total_point = total_point + count_zeros*bomb;
        MyGrid2[bomb_list.at(k).at(0)][bomb_list.at(k).at(1)] = 0;

    }

    //PART2
    output << "\n";
    output << "PART 2:" << endl;
    for(int i=0; i<N2; i++){

        for(int j=0; j<N2; j++){

            output << MyGrid2[i][j];

            output <<" ";
        }
        output <<"\n";
    }
    output << "Final Point: " << total_point << "p";
    output << "\n";
    output.close();

    //end of int main()

}

