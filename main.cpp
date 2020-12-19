#include <vector>
#include <iostream> 
#include <string>

//asks user if they want to encrypt a message or decrypt a message
std::string alphabet = "abcdefghijklmnopqrstuvwxyz";

int getUserChoice() {
	int input;
	std::string rawInput;

	std::cout<<"would you like to (1)encrypt a message or (2)decrypt a message?"<<std::endl;

	std::cin>>rawInput;

	input = std::stoi(rawInput);
	
	if (input != 1) {
		if (input != 2) {
			std::cout<<"Enter in a valid choice\n";
			getUserChoice();
		}
	} else {
		return input;
	}
	return -1;
}

//encrypt word
std::string encryptedWord(std::string input) {
	std::vector<char> word(input.begin(), input.end());
	/*
	   for every letter in the string
			find letter location in alphabet
				set letter equal to (letterpos + 5 mod 26)

	   */

	for (int i = 0; i < (int) input.length();i++) {
		for (int j = 0; j < (int) alphabet.length();j++) {
			if (word[i] == alphabet[j]) {
				std::cout<<"word[i]: "<<word[i]<<" alphabet[j]: "<<alphabet[j]<<std::endl;

				word[i] = alphabet[(j+3) % 26];

				std::cout<<"new word[i]: "<<word[i]<<std::endl;

				break;
			}
		}
	}
	std::string str(word.begin(), word.end());
	return str;
}

//displays user input and encryption output
void encryptPrompt() {
	std::string input;
	std::cout<<"enter in the string you would like to encrypt: ";
	std::cin>>input;
	std::cout<<"Encrypted version: "<<encryptedWord(input);
}

void decryptPrompt() {
	//Need to implement
}

int main(){ 
	int choice = getUserChoice();

	switch (choice) {
		case 1:
			encryptPrompt();
			break;
		case 2: 
			decryptPrompt();
			break;
	}
}
