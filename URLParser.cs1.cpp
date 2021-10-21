#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int main(int vargs, char *args[])
{
string url = "http://www.example.com:80500000/path/robot.html?name=jason";
cout << url << endl;

string goodProto[] = {"http", "https","ftp","ftps"};
string proto = url.substr(0, url.find("://"));
for (int i = 0; i < 4; i++)
{
if (proto == goodProto[i])
{
cout << "\nProtocol:" << proto << endl;
break;
}
if (i == 3)
{
cout << proto << "is not a valid protocol" << endl;
return 1;
}
}
string removeProto = url.substr(url.find(".")+9);
//Domain
string domain = removeProto.substr(0,removeProto.find(":"));
domain = domain.substr(0, domain.find("/"));
string removeDomain = removeProto.substr(removeProto.find("/")+1);
string goodDomain[] = {"com","net","edu","biz","gov"};
for (int j = 0; j < 5; j++)
{
if (domain == goodDomain[j])
{
cout << "Domain:" << domain << endl;
break;
}
if (j == 4)
{
cout << domain << " is not a valid domain " << endl;
return 1;
}
}
//File Path
string file = removeDomain.substr(0, removeDomain.find("?"));
cout << "File Path:" << file << endl;
//Parameters
string para= removeDomain.substr(removeDomain.find("?")+1);
cout << "Parameters:" << para << endl;
//Port
int i = 0;
for (;i < url.length();i++)
{
if (isdigit(url[i]))
break;
}
url = url.substr(i,url.length() - i);
int port = atoi(url.c_str());
if(port > 65535)
{
cout << port << "---- port number must be between 1 and 65535" << endl;
}
else if (port < 1 )
{
cout << "---- port number must be between 1 and 65535" << endl;
}
else
{
cout << "Port:" << port << endl;
}
cout << " have a good day :)...Jason Hoang " << endl;
}


