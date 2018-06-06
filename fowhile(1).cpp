#include <iostream>
#include <sstream>
#include <fstream>
#include <stack>

using namespace std;

void cleanup(string &str)
{
    for(int i=0; i<str.length(); i++)
    {
        if((str[i] == '(') || (str[i] == ')') || (str[i] == ':') || (str[i] == ';'))
            str[i] = ' ';
    }
}

deleteFor(string &str)
{
    string temp="";
    istringstream iss(str);
    string str1 = "";
    while(iss >> str1)
    {
        if(str1 == "for")
            continue;
        else
            temp += str1 + " ";
    }
    str = temp;
}

string calcIndent(string str)
{
    string temp = "";
    for(int i=0; i<str.length(); i++)
    {
        if(str[i] != ' ')
            break;
        temp += str[i];
    }
    return temp;
}

int checkFor(string str)
{
    int ans = 0;

    cleanup(str);

    istringstream iss(str);

    string str1;

    iss >> str1;
    if(str1 == "for")
        ans = 1;

    return ans;
}

void takeOnePart(int &i,string &str, string &str1)
{
    string temp="";
    while(i<str.length())
    {
        if((str[i] == ' ') && (temp.length() == 0))
        {
            i++;
            continue;
        }
        if((str[i] == ';') || (str[i] == ')'))
        {
            str1 = temp;
            temp = "";
            i++;
            break;
        }
        temp += str[i];
        i++;
    }
}


void takeParts(string str, string &str1, string &str2, string &str3)
{
    int i=0;
    while(i<str.length())
    {
        if(str[i] == '(')
        {
            i++;
            break;
        }
        i++;
    }
    takeOnePart(i,str,str1);
    takeOnePart(i,str,str2);
    takeOnePart(i,str,str3);
}

void addSemiColons(string &str1, string &str3)
{
    str1 += ';';
    str3 += ';';
}

int checkFirstCurly(string str)
{
    for(int i=0; i<str.length(); i++)
        if(str[i] == '{')
            return 1;
    return 0;
}

int checkLastCurly(string str)
{
    for(int i=0; i<str.length(); i++)
        if(str[i] == '}')
            return 1;
    return 0;
}

int checkSwitch(string str)
{
    int ans = 0;

    cleanup(str);

    istringstream iss(str);

    string str1;

    iss >> str1;
    if(str1 == "switch")
        ans = 1;

    return ans;
}

int checkCase(string str)
{
    int ans = 0;

    cleanup(str);

    istringstream iss(str);

    string str1;

    iss >> str1;
    if(str1 == "case")
        ans = 1;

    return ans;
}

int checkBreak(string str)
{
    int ans = 0;

    cleanup(str);

    istringstream iss(str);

    string str1;

    iss >> str1;
    if(str1 == "break")
        ans = 1;
    return ans;
}

int checkDefault(string str)
{
    int ans = 0;

    cleanup(str);

    istringstream iss(str);

    string str1;

    iss >> str1;
    if(str1 == "default")
        ans = 1;
    return ans;
}

string takeVariable(string str)
{
    int i=0;
    while(i<str.length())
    {
        if(str[i] == '(')
        {
            i++;
            break;
        }
        i++;
    }
    string temp = "";
    while(i<str.length())
    {
        if(str[i] == ')')
            break;
        temp += str[i];
        i++;
    }
    return temp;
}

string getCase(string str)
{
    string temp = "";
    int i=0;
    while(i<str.length())
    {
        if(str[i] == 'e')
        {
            i++;
            break;
        }
        i++;
    }
    while(i<str.length())
    {
        if(str[i] == ':')
            break;
        if(str[i] != ' ')
            temp += str[i];
        i++;
    }
    return temp;
}

string convertToWhile(ifstream &ifile,stack <string> &mys, stack <char> &symbol, string spaces, string norm)
{
    string str;
    string code = "";
    while(getline(ifile,str))
    {
        int flag = 0;
        if(checkFor(str))
        {
            string strFor;
            string spaceInItr = calcIndent(str) + "    ";
            strFor = spaceInItr + "while(1){\n";
            string str1="",str2="",str3="";
            takeParts(str,str1,str2,str3);
            addSemiColons(str1,str3);
            strFor += spaceInItr +"    "+str1+"\n"+spaceInItr +"    "+"while("+str2+" ){\n";
            if(!checkFirstCurly(str))
                while(getline(ifile,str))
                    if(checkFirstCurly(str))
                        break;
            symbol.push('{');
            mys.push(str3);
            strFor += convertToWhile(ifile,mys,symbol,(spaceInItr+"    "), (norm+"    "))+spaceInItr +"    "+"break;\n"+spaceInItr +"}\n";
            code += strFor;
            continue;
        }
        if(checkFirstCurly(str))
        {
            code += str + '\n';
            symbol.push('{');
            mys.push("");
        }
        if(checkLastCurly(str))
        {
            if(mys.top() != "")
            {
                code += spaces + "    " + mys.top() + "\n";
                code += spaces + "}\n";
                flag =1;
            }
            else
            {
                code += mys.top();
                flag = 2;
            }
            mys.pop();
            symbol.pop();
        }
        if(flag == 1)
            break;
        else if(flag == 2)
            continue;
        code += norm + str + '\n';
    }
    return code;
}

string convertToIf(istringstream &iss, string var, string spaces, stack <char> &symbol)
{
    string str = "";
    string strSw = "";
    while(getline(iss,str))
    {
        if(checkCase(str))
        {
            strSw += getCase(str) + " ){\n";
            break;
        }
        if(checkLastCurly(str))
        {
            strSw += "}\n";
            break;
        }
    }
    while(getline(iss,str))
    {
        if((checkBreak(str)) && (symbol.size() < 2))
                continue;
        if(checkCase(str))
        {
            strSw += spaces + "}\n" + spaces + "else if( " + var +" == " + getCase(str) + " ){\n";
            continue;
        }
        if(checkDefault(str))
        {
            strSw += spaces + "}\n" + spaces + "else{\n";
            continue;
        }
        if(checkFirstCurly(str))
            if(!checkSwitch(str))
                symbol.push('{');
        if(checkLastCurly(str))
        {
            symbol.pop();
            if(symbol.empty())
            {
                strSw += spaces + "}\n";
                break;
            }
        }
        if(checkSwitch(str))
        {
            string spacesItr =  calcIndent(str);
            strSw += spacesItr + "if( ";
            string var1 = takeVariable(str);
            strSw += var1 + " == ";
            if(!checkFirstCurly(str))
                while(getline(iss,str))
                    if(checkFirstCurly(str))
                        break;
            stack <char> symbol1;
            symbol1.push('{');
            strSw += convertToIf(iss, var1, spacesItr,symbol1);
            continue;
        }
        strSw += str + '\n';
    }
    return strSw;
}

string convertSwitch(istringstream &iss)
{
    string str;
    string code = "";
    while(getline(iss,str))
    {
        if(checkSwitch(str))
        {
            string spaces = calcIndent(str);
            string strSw = spaces + "if( ";
            string var = takeVariable(str);
            strSw += var + " == ";
            if(!checkFirstCurly(str))
                while(getline(iss,str))
                    if(checkFirstCurly(str))
                        break;
            stack <char> symbol;
            symbol.push('{');
            strSw += convertToIf(iss, var, spaces,symbol);
            code += strSw;
        }
        else
            code += str + '\n';
    }
    return code;
}

string readfile()
{
    ifstream ifile;
    ifile.open("code.txt");

    string str;
    string code = "";

    while(getline(ifile,str))
    {
        if(checkFor(str))
        {
            string strFor;
            string spaces = calcIndent(str);
            strFor = spaces + "while(1){\n";
            string str1="",str2="",str3="";
            takeParts(str,str1,str2,str3);
            addSemiColons(str1,str3);
            strFor += spaces +"    "+str1+"\n"+spaces +"    "+"while("+str2+" ){\n";
            if(!checkFirstCurly(str))
                while(getline(ifile,str))
                    if(checkFirstCurly(str))
                        break;
            stack <string> mys;
            stack <char> symbol;
            symbol.push('{');
            mys.push(str3);
            strFor += convertToWhile(ifile,mys,symbol,(spaces+"    "),"    ")+spaces +"    "+"break;\n"+spaces +"}\n";
            code += strFor;
        }
        else
            code += str + '\n';
    }
    ifile.close();
    istringstream iss(code);
    code = convertSwitch(iss);
    return code;
}

void writefile(string str)
{
    ofstream ofile;
    ofile.open("output.txt");
    ofile << str;
    ofile.close();
}
int main()
{
    string str = readfile();
    //cout << str ;
    writefile(str);
    return 0;
}
