#pragma once
#include<string>
#include<vector>
#include<fstream>
#include<iostream>

class Encryption
{
	public:
		Encryption();
		Encryption(int, int, int);
		~Encryption();
		int getn();//returns n
		int getencryptionkey();//returns the public encryption key e, used to for the public to encrypt messages
		std::vector<int> encode(std::string);
		std::string decode(std::vector<int>);
		//the main function expected to be used for the user
		void encrypt_file(std::string, std::string);//input name (file being read), output name (file being written to)
		
		int encrypt(int);
		std::vector<int> encrypt(std::vector<int>);
		int decrypt(int);
		std::vector<int> decrypt(std::vector<int>);

	private:
		int p, q, n, phi, e, d;
		int expmod(int, int, int);
		int modinverse(int, int);
		int gcd(int, int);//not currently used
};

