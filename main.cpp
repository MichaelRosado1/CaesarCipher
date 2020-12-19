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
	}
	return input;
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
				word[i] = alphabet[(j+3) % 26];

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

std::string decryptedWord(std::string input) {
	std::vector<char> word(input.begin(), input.end());

	for (int i = 0; i < (int) input.length(); i++) {
		for (int j = 0; j < (int) alphabet.length(); j++) {
			if (word[i] == alphabet[j]) {
				word[i] = alphabet[(j-3) % 26];
				break;
			}
		}
	}
	std::string str(word.begin(), word.end());
	return str;
}
void decryptPrompt() {
	//Need to implement
	std::string input;
	std::cout<<"enter in the string you would like to decrypt: ";
	std::cin>>input;
	std::cout<<"decrypted version: "<<decryptedWord(input);


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
