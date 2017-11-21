										/*!!! Hello !!!*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void reserved(string word);
void number(string word);
void identifier(string word);

bool isreserved(string word);

ofstream output("scanner_output.txt");

int main() {
	ofstream Input("tiny_sample_code.txt");
	Input << "{sample program in TINY language- computes factorial}\n";
	Input << "read x;{input an integer}\n";
	Input << "if 0<x then {don’t compute if x<=0}\n";
	Input << "         fact:=1;\n";
	Input << "         repeat\n";
	Input << "                 fact:=fact*x;\n";
	Input << "                 x:=x-1\n";
	Input << "         until x=0;\n";
	Input << "         write fact{output factorial of x}\n";
	Input << "end\n";
	Input.close();

	ifstream input("tiny_sample_code.txt");

	string line;
	string word;
	string num;
	string special;
	while (getline(input,line))
	{
		for (int i=0; i<(int)line.length(); i++){
			if ((int)line[i]==123){
				for (int j=0; j<(int)line.length();j++){
					if ((int)line[j]==125) i=j;
				}
				continue;}
			else if (((int)line[i]>=65 && (int)line[i]<=90) || ((int)line[i]>=97 && (int)line[i]<=122))
			{
				word = word + line[i];
				if ((int)line[i+1]<65 || (int)line[i+1]>122 || ((int)line[i+1]>90 && (int)line[i+1]<97)){
					if (word.length() != 0){
					if (isreserved(word)){
						reserved(word);
						word="";
					}else {identifier(word);word="";}}
				}
			}
			else if ((int)line[i]>=48 && (int)line[i]<=57)
			{
				num = num + line[i];
				if (num.length()!=0){
					number(num);
					num="";
				}

			}
			else if (line[i]=='(' || line[i]==')' || line[i]=='+' || line[i]=='-' || line[i]=='*' || line[i]=='/' || line[i]=='<' || line[i]=='>' || line[i]==';' || line[i]=='=' || line[i]==':')
			{
				if (line[i]==':'){if (line[i+1]=='='){
					special=":=";
					output << special << "  : special symbol" << endl;
					special="";
					i=i+1;
					continue;}}
				special =  line[i];
				output << special << "  : special symbol" << endl;
				special="";
				
			}
			

			
			else{continue;}
		}


	}

	output.close();
	cout << "Finish"<<endl;
	return 0;
}


void reserved(string word){

	output << word << "  : reserved word" << endl;
}

void number(string word){
	output << word << "  : number" << endl;
}

void identifier(string word){
	output << word << "  : identifier" << endl;
}

bool isreserved (string word){
	if (word == "if") return true;
	else if (word == "then") return true;
	else if (word == "else") return true;
	else if (word == "repeat") return true;
	else if (word == "until") return true;
	else if (word == "end") return true;
	else if (word == "read") return true;
	else if (word == "write") return true;
	else {return false;}
}

