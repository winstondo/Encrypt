#include "Encryption.h"


Encryption::Encryption()
{}


Encryption::Encryption(int p, int q, int e)//e must be co prime with n
	: p(p), q(q), e(e)
{
	n = p*q;
	phi = (p - 1)*(q - 1);
	d = modinverse(e, phi);
}

int Encryption::getencryptionkey()
{
	return e;
}

int Encryption::getn()
{
	return n;
}

int Encryption::encrypt(int c)
{
	return expmod(c, e, n);
}

std::vector<int> Encryption::encrypt(std::vector<int> msg)
{
	for (unsigned i = 0; i < msg.size(); i++) {
		msg.at(i) = encrypt(msg.at(i));
	}
	return msg;
}


int Encryption::decrypt(int c)//c is message to be decrypted
{
	return expmod(c, d, n);
}

std::vector<int> Encryption::decrypt(std::vector<int> msg)
{
	for (unsigned i = 0; i < msg.size(); i++) {
		msg.at(i) = decrypt(msg.at(i));
	}
	return msg;
}

int Encryption::expmod(int x, int exp, int mod)
{
	if (exp == 0) {
		return 1;
	}
	int i = expmod(x, exp / 2, mod);

	if (exp % 2 == 0) {
		return (i*i) % mod;
	}
	else
		return (((i*x) % mod) * i) % mod;
}

int Encryption::gcd(int a, int b)
{
	if (a < b) {
		return gcd(b, a);
	}
	int g = a%b;
	if (g == 0) {
		return b;
	}
	else {
		return gcd(b, g);
	}
}

int Encryption::modinverse(int e, int phi)//O(n)
{
	e = e%phi;
	for (unsigned i = 1; i < phi; i++) {
		if ((e*i) % phi == 1)

			return i;
	}
}
//takes a string messages and encodes it into messages
std::vector<int> Encryption::encode(std::string msg)
{
	std::vector<int> encdmsg;
	for (unsigned i = 0; i < msg.length(); i++) {
		encdmsg.push_back(static_cast<int>(msg.at(i)));
	}
	return encdmsg;
}


//main workhorse 
void Encryption::encrypt_file(std::string infile, std::string outfile)//reads, encodes, encrypts and writes to the specified file
{
	std::ifstream readmsg(infile);
	std::ofstream writemsg(outfile);
	if (readmsg.fail()) {
		std::cout << "Error reading file" << std::endl;
	}
	std::string msg;
	std::vector<int> intmsg; //the message as a vector if ints, unencrypted
	getline(readmsg, msg);
	intmsg = encode(msg);
	intmsg = encrypt(intmsg);//fucntion that uses e,p,q,n,phi
	for (unsigned i = 0; i < intmsg.size(); i++) {
		writemsg << intmsg.at(i) << " ";
	}
	readmsg.close();
	writemsg.clear();

}


std::string Encryption::decode(std::vector<int> c)
{
	std::string msg;
	for (unsigned i = 0; i < c.size(); i++) {
		msg.push_back(static_cast<char>(c.at(i)));
	}
	return msg;
}

Encryption::~Encryption()
{
}

