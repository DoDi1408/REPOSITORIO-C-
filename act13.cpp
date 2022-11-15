//Mateo Bernasconi and Rodrigo Chavez
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;


vector<int> split (string str)  
{  
    vector<int> output;
    int i = 0;  
    int startIndex = 0;  

    while (i <= 18)  
    {  
        if (str[i] == '.' || str[i] == ':' || i == 18)  
        {  
            string subStr = str.substr(startIndex, i-startIndex);  
            output.push_back(stoi(subStr));
            startIndex = i + 1;  
        }  
        i++;  
        }     
    return output;
}  

//O(18) where 18 is the max length of the ip
bool compareTwoIp(string firstIp, string secondIp){
    vector<int> firstIpNums = split(firstIp);
    vector<int> secondIpNums = split(secondIp);
    for(int i = 0; i < 5; i++){
        if(firstIpNums[i] < secondIpNums[i]){
            return true;
        } else if (firstIpNums[i] > secondIpNums[i])
        {
            return false;
        }
    }
    return true;
}

// MergeSort O(nlogn)
void MergeSortedData(vector<string>& data, int s, int m, int e) {
    // temp is used to temporary store the vector obtained by merging
	vector<string> temp;
	int i, j;
	i = s;
	j = m + 1;

	while (i <= m && j <= e) {
        int startIndexI = data[i][15] == ' ' ? 16 : 15;
        int startIndexJ = data[j][15] == ' ' ? 16 : 15;
        
		if (compareTwoIp(data[i].substr(startIndexI, 18), data[j].substr(startIndexJ, 18))) {
			temp.push_back(data[i]);
			++i;
		}
		else {
			temp.push_back(data[j]);
			++j;
		}

	}

	while (i <= m) {
		temp.push_back(data[i]);
		++i;
	}

	while (j <= e) {
		temp.push_back(data[j]);
		++j;
	}

	for (int i = s; i <= e; ++i)
		data[i] = temp[i - s];

}

// MergeSort O(nlogn)
void MergeSort(vector<string>& data, int startIndex, int endIndex) {
	if (startIndex < endIndex) {
		int mid = (startIndex + endIndex) / 2;
		MergeSort(data, startIndex, mid);
		MergeSort(data, mid + 1, endIndex);
		MergeSortedData(data, startIndex, mid, endIndex);
	}
}

// Binary search O(logn)
int binarySearch(vector<string>& testCase, string target){
    int left = 0;
    int right = testCase.size() - 1;
    int mid;
    while(left <= right){
        mid = (left + right) / 2;

        int startIndex = testCase[mid][15] == ' ' ? 16 : 15;
        int ipLength = testCase[mid][startIndex+17] == ' ' ? 17 : 18;

        if (testCase[mid].substr(startIndex, ipLength) == target){
            return mid;
        }else if(compareTwoIp(testCase[mid].substr(startIndex, 18), target)){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    //If not found, left is the next corresponding index within range
    return left;
}

int main(){
    vector <string> sortedData; 
    int index;
    string target, endTarget;
    ifstream file;
    string line;

    //Add each line to the vector and sort
    file.open("bitacora.txt"); 
    if (file.is_open()) {
        while (getline(file, line)) {
            sortedData.push_back(line);
        }
        
        file.close();
    }
    MergeSort(sortedData, 0, sortedData.size()-1);

    //Get search start and search end from User
    string ipStart, ipEnd;
    cout << "Welcome to the DENIED ENTRY DATABSE, you can choose a time range to get all denied entries" << endl;
    cout << "\nPlease enter the ip you want to begin your search i.e. (865.72.473.15:4095): ";
    cin >> ipStart;
    cout << "\nPlease enter the day you want to end your search i.e (865.72.473.15:4095): ";
    cin >> ipEnd;


    //Get starting index 
    index = binarySearch(sortedData, ipStart);
    int startCharIndex = sortedData[index][15] == ' ' ? 16 : 15;
    cout << "\nSearch Results: \n" << endl;

    while (index < sortedData.size() && compareTwoIp(sortedData[index].substr(startCharIndex,18), ipEnd)){
        cout << sortedData[index] << endl;
        index++;
        //ip starting index
        startCharIndex = sortedData[index][15] == ' ' ? 16 : 15;
    }


    //Add all sorted ip to new txt file
    fstream sortedBitacora;
	sortedBitacora.open("sortedDataByIp.txt", ios::out);

    int curIndex = 0;
	while (curIndex < sortedData.size()){
        sortedBitacora << sortedData[curIndex] << endl;
        curIndex++;
    }

    cout << "\nAll of sorted denied entries have been added to sortedDataByIp.txt" << endl;
	sortedBitacora.close();

    return 0;
}