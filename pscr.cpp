#include <iostream>
#include <bits/stdc++.h> 
#include <fstream>
#include<string> // for string and to_string() 

using namespace std;

string memory[4096];
int registors[32];
int ClockCycles = 0;

int addr(int first, int second){
	return registors[first]+registors[second];
}
int subr(int first, int second){
	return registors[first]-registors[second];
}
int multr(int first, int second){
	return registors[first]*registors[second];
}
int divr(int first, int second){
	return registors[first]/registors[second];
}

void execute(){
	int i = 0;
	string line = memory[i];
	int programCounter = 0;
	while(line != ""){
	    vector <string> tokens; 
	    stringstream check1(line);
	    string intermediate; 
	    while(getline(check1, intermediate, ' ')) { 
	      	tokens.push_back(intermediate); 
	    }
	    ClockCycles += stoi(tokens[tokens.size()-1]);
	    std::cout << "Executing instruction number : " << i << '\n';
	    if(tokens[0] == "add"){
	    	int first = stoi(tokens[2]);
	    	int second = stoi(tokens[3]);
	    	int res = stoi(tokens[1]);
	    	registors[res] = addr(first,second);
	    	std::cout << "The value in the register " << first << " is " << registors[first] << '\n';
	    	std::cout << "The value in the register " << second << " is " << registors[second] << '\n';
	    	std::cout << "The value in the register " << res << " is " << registors[res] << '\n';
	    }
	    else if(tokens[0] == "sub"){
	    	int first = stoi(tokens[2]);
	    	int second = stoi(tokens[3]);
	    	int res = stoi(tokens[1]);
	    	registors[res] = subr(first,second);
	    	std::cout << "The value in the register " << first << " is " << registors[first] << '\n';
	    	std::cout << "The value in the register " << second << " is " << registors[second] << '\n';
	    	std::cout << "The value in the register " << res << " is " << registors[res] << '\n';
	    }
	    else if(tokens[0] == "div"){
	    	int first = stoi(tokens[2]);
	    	int second = stoi(tokens[3]);
	    	int res = stoi(tokens[1]);
	    	registors[res] = divr(first,second);
	    	std::cout << "The value in the register " << first << " is " << registors[first] << '\n';
	    	std::cout << "The value in the register " << second << " is " << registors[second] << '\n';
	    	std::cout << "The value in the register " << res << " is " << registors[res] << '\n';
	    }
	    else if(tokens[0] == "mult"){
	    	int first = stoi(tokens[2]);
	    	int second = stoi(tokens[3]);
	    	int res = stoi(tokens[1]);
	    	registors[res] = multr(first,second);
	    	std::cout << "The value in the register " << first << " is " << registors[first] << '\n';
	    	std::cout << "The value in the register " << second << " is " << registors[second] << '\n';
	    	std::cout << "The value in the register " << res << " is " << registors[res] << '\n';
	    }
	    else if(tokens[0] == "beq"){
	    	int second = stoi(tokens[2]);
	    	int first = stoi(tokens[1]);
	    	int offset = stoi(tokens[3]);
	    	if(registors[first] == registors[second]){
	    		i += offset;
	    		std::cout << "Jumping with offset equal to " << offset << '\n';
	    	}
	    }
	    else if(tokens[0] == "bne"){
	    	int second = stoi(tokens[2]);
	    	int first = stoi(tokens[1]);
	    	int offset = stoi(tokens[3]);
	    	if(registors[first] != registors[second]){
	    		i += offset;
	    		std::cout << "Jumping with offset equal to " << offset << '\n';
	    	}
	    }
	    else if(tokens[0] == "blez"){
	    	int first = stoi(tokens[1]);
	    	int offset = stoi(tokens[2]);
	    	if(registors[first] <= 0){
	    		i += offset;
	    		std::cout << "Jumping with offset equal to " << offset << '\n';
	    	}
	    }
	    else if(tokens[0] == "bgtz"){
	    	int first = stoi(tokens[1]);
	    	int offset = stoi(tokens[2]);
	    	if(registors[first] > 0){
	    		i += offset;
	    		std::cout << "Jumping with offset equal to " << offset << '\n';
	    	}
	    }
	    else if(tokens[0] == "j"){
	    	int offset = stoi(tokens[1]);
	    	i = offset-1;
	    	std::cout << "Jumping to " << offset << '\n';
	    }
	    else if(tokens[0] == "jal"){
	    	int offset = stoi(tokens[1]);
	    	registors[31] = i;
	    	i = offset-1;
	    	std::cout << "Jumping to " << offset << '\n';
	    }
	    else if(tokens[0] == "jr"){
	    	int offset = registors[31];
	    	i = offset-1;
	    	std::cout << "Jumping to " << offset << '\n';
	    }
	    else if(tokens[0] == "lw"){
	    	int first = stoi(tokens[1]);
	    	int offset = stoi(tokens[2]);
	    	int memLocation = stoi(tokens[3]);
	    	if(memory[memLocation+offset+1000] == "")
	    		registors[first] = 0;
	    	else{
		    	int val = stoi(memory[memLocation+offset+1000]);
		    	registors[first] = val;
		    }
	    	std::cout << "Storing value from memory loaction " << memLocation << " with offset " << offset << " into registor " << first <<'\n';
	    }
	    else if(tokens[0] == "sw"){
	    	int first = stoi(tokens[1]);
	    	int offset = stoi(tokens[2]);
	    	int memLocation = stoi(tokens[3]);
	    	int val = registors[first];
	    	memory[memLocation+offset+1000] = to_string(val);
	    	std::cout << "Storing value: " << val << " in memory loaction " << memLocation << " with offset " << offset << '\n';
	    }
	    else if(tokens[0] == "li"){
	    	int first = stoi(tokens[1]);
	    	int value = stoi(tokens[2]);
	    	registors[first] = value;
	    	std::cout << "The value "<< value << " is stored in registor " << " first" << '\n';
	    }
	    else if(tokens[0] == "srl"){
	    	int loc = stoi(tokens[1]);
	    	int val = stoi(tokens[2]);
	    	int shift = stoi(tokens[3]);
	    	registors[loc] = registors[val] * pow(2,-1*shift);
	    	std::cout << "Stored value of " << registors[loc] << " in " << loc << '\n';
	    }
	    else if(tokens[0] == "sll"){
	    	int loc = stoi(tokens[1]);
	    	int val = stoi(tokens[2]);
	    	int shift = stoi(tokens[3]);
	    	registors[loc] = registors[val] * pow(2,shift);
	    	std::cout << "Stored value of " << registors[loc] << " in " << loc << '\n';
	    }
	    i++;
	    line = memory[i];
	    programCounter++;
	}
	float IPC = (float)programCounter/(float)ClockCycles;
	std::cout << "The number of Instructions executed are : " << programCounter << "\n";
	std::cout << "The number of clock cycles taken are : " << ClockCycles << "\n";
	std::cout << "The Instructions per cycle is : " << IPC << '\n';
}

int main(){
  ifstream myfile;
  string line;
  myfile.open ("input.txt");
  if (myfile.is_open()){
  	int i = 0;
    while (getline (myfile,line) ){
    	memory[i] = line;
    	i++;
    }
    myfile.close();
  }

  // INIIALISE ALL THE REGISTORS HERE ...

  registors[2] = 10;
  registors[3] = 20;

  execute();

  return 0;
}