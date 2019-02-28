#include<iostream>
#include<fstream>
#include"Encryption.h"
#include<string>

void testbench();
int testbench2();

int main()
{
	testbench();
	testbench2();
	return 0;
}

void testbench()
{
	Encryption t(11, 13, 7);
	std::string readmsg = "message.txt", writemsg = "encrypted_message.txt";
	t.encrypt_file(readmsg, writemsg);
	std::cout<< "Public Key: " << t.getencryptionkey() << std::endl;
}


int testbench2()
{	
	int msg;
	std::vector<int> m;
	std::ifstream file("encrypted_message.txt");
	while (file >> msg) {
		m.push_back(msg);
	}

	file.close();
	std::cout << "Encrypted msg: ";
	for (unsigned i = 0; i < m.size(); i++) {
		std::cout << m.at(i) << " ";
	}
	std::cout << std::endl;

	Encryption t(11, 13, 7);
	std::string stringmsg = t.decode(m);
	std::cout << "Translating Encrypted msg into string: " << stringmsg << std::endl;
	m = t.decrypt(m);
	/*for (unsigned i = 0; i < m.size(); i++) {
		std::cout << m.at(i) << " ";
	}*/

	std::cout << std::endl;
	std::cout << "Decrypted msg: "<< t.decode(m) << std::endl;
	

	return 0;
}