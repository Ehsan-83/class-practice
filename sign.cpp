#include <iostream>

void separator(std::string txt , std::string array[] , std::string n_array[] , int &p_size , int &n_size);
void show(std::string array[] , int size);

int main(){
    const int SIZE = 10;
    std::string data;
    std::string negatives[SIZE];
    std::string positives[SIZE];

    int n_size = 0;
    int p_size = 0;


    std::cout<<"Please enter "<< SIZE <<" entegers and separate them with space\n";
    std::getline(std::cin , data);
    std::cout<<"***********************\n";

    separator(data , positives , negatives , p_size , n_size);

    show(positives,p_size);
    show(negatives,n_size);

    std::cout<<"***********************";
    
    
    return 0;
}
void separator(std::string txt, std::string p_array[] , std::string n_array[] , int &p_size , int &n_size){
    int i=0;
    std::string temp;

    while(i < txt.length()){
        for(int j=i ; txt[j]!=' ' && j<txt.length() ; j++){
            temp+=txt[j];
            i++;
        }
        if(temp[0] == '-' ){
            n_array[n_size] = temp;
            n_size++;
        }
        else  if(temp =="0");
        else{
            p_array[p_size]=temp;
            p_size++;
        }
        temp="";
        i++;
    }
}
void show(std::string array[] , int size){
    for(int i=0 ; i<size ; i++){
        std::cout<<array[i]<<(i == (size-1) ? "" : " , ");
    }
    if(array[0][0]=='-'){
        std::cout<<"   ( "<<size<<" negative numbers )\n";
    }
    else{
        std::cout<< "   ( " <<size<< " positive numbers )\n";
    }
}