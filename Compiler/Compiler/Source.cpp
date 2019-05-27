#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define NO_KEYWORDS 7
#define ID_LENGTH 12

FILE* fp;

enum tsymbol
{
	tnull = -1 , 
	tnot , tnotequ , tmod , tmodAssign , tident , tnumber ,
	tand , tlparen , trparen , tmul , tmulAssign , tplus , 
	tinc , taddAssign , tcomma , tminus , tdec , tsubAssign ,
	tdiv , tdivAssign , tsemicolon , tless , tlesse , tassign ,
	tequal , tgreat , tgreate , tlbracket , trbracket , teof ,
	tconst , telse , tif , tint , treturn, tvoid ,
	twhile , tlbrace , tor , trbrace
};

struct tokenType
{
	int number = 0;
	union
	{
		char id[ID_LENGTH];
		int num;
	}
	value;
};

int hexValue(char ch)
{
	switch (ch)
	{
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			return (ch - '0');
		case 'A':
		case 'B':
		case 'C':
		case 'D':
		case 'E':
		case 'F':
			return (ch - 'A' + 10);
		case 'a':
		case 'b':
		case 'c':
		case 'd':
		case 'e':
		case 'f':
			return (ch - 'a' + 10);
		default:
			return -1;
	}
}

int getIntNum(char firstCharacter)
{
	int num = 0;
	int value;
	char ch;

	if (firstCharacter != '0')
	{
		ch = firstCharacter;
		do
		{
			num = 10 * num + (int)(ch - '0');
			ch = fgetc(fp);
		} 
		while (isdigit(ch));
	}
	else
	{
		ch = fgetc(fp);
		if ((ch >= '0') && (ch <= '7'))
		{
			do
			{
				num = 8 * num + (int)(ch - '0');
				ch = fgetc(fp);
			} 
			while ((ch >= '0') && (ch <= '7'));
		}
		else if ((ch == 'X') || (ch == 'x'))
		{
			while ((value = hexValue(ch = fgetc(fp))) != -1)
			{
				num = 16 * num + value;
			}
		}
		else
		{
			num = 0;
		}
	}
	ungetc(ch, stdin);
	return num;
}
char keyword[NO_KEYWORDS][20] = { "const" , "else" , "if" , "int" , "return" , "void" , "while" };

enum tsymbol tnum[NO_KEYWORDS] = { tconst , telse , tif , tint , treturn, tvoid , twhile };

void lexicalError(int n)
{
	printf(" *** Lexical Error : ");
	switch (n)
	{
		case 1 : 
			printf("an identfier length must be less than 12. \n");
			break;
		case 2:
			printf("next character must be &. \n");
			break;
		case 3:
			printf("next character must be |. \n");
			break;
		case 4:
			printf("invalid character!!! \n");
			break;
	}
}

int superLetter(char ch)
{
	if (isalpha(ch) || ch == '_')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int superLetterOrDigit(char ch)
{
	if (isalnum(ch) || ch == '_')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

struct tokenType scanner()
{
	struct tokenType token;
	int i, index;
	char ch, id[ID_LENGTH];
	token.number = tnull;
	do 
	{
		while (isspace(ch = fgetc(fp)));
	
		if (superLetter(ch))
		{
			i = 0;
			do
			{
				if (i < ID_LENGTH)
				{
					id[i++] = ch;
				}
				ch = fgetc(fp);
			} 
			while (superLetterOrDigit(ch));
			if (i >= ID_LENGTH)
			{
				lexicalError(1);
			}
			id[i] = '\0';
			ungetc(ch, stdin);

			for (index = 0; index < NO_KEYWORDS; index++)
			{
				if (!strcmp(id, keyword[index]))
				{
					break;
				}
			}
			if (index < NO_KEYWORDS)
			{
				token.number = tnum[index];
				strcpy_s(token.value.id, keyword[index]);
			}
			else
			{
				token.number = tident;
				strcpy_s(token.value.id, id);
			}
		}
		else if (isdigit(ch))
		{
			token.number = tnumber;
			token.value.num = getIntNum(ch);
		}
		else switch (ch)
		{
			case '/': 
				ch = fgetc(fp);
				if (ch == '*')
				{
					do
					{
						while (ch != '*')
						{
							ch = fgetc(fp);
						}
						ch = fgetc(fp);
					} 
					while (ch != '/');
				}
				else if (ch == '/')
				{
					while (fgetc(fp) != '\n');
				}
				else if (ch == '=')
				{
					strcpy_s(token.value.id, "/=");
					token.number = tdivAssign;
				}
				else
				{
					strcpy_s(token.value.id, "/");
					token.number = tdiv;
					ungetc(ch, stdin);
				}
				break;
			case '!':
				ch = fgetc(fp);
				if (ch == '=')
				{
					strcpy_s(token.value.id, "!=");
					token.number = tnotequ;
				}
				else
				{
					strcpy_s(token.value.id, "!");
					token.number = tnot;
					ungetc(ch, stdin);
				}
				break;
			case '%':
				ch = fgetc(fp);
				if (ch == '=')
				{
					strcpy_s(token.value.id, "%=");
					token.number = tmodAssign;
				}
				else
				{
					strcpy_s(token.value.id, "%");
					token.number = tmod;
					ungetc(ch, stdin);
				}
				break;
			case '&':
				ch = fgetc(fp);
				if (ch == '&')
				{
					strcpy_s(token.value.id, "&&");
					token.number = tand;
				}
				else
				{
					lexicalError(2);
					ungetc(ch, stdin);
				}
				break;
			case '*':
				ch = fgetc(fp);
				if (ch == '=')
				{
					strcpy_s(token.value.id, "*=");
					token.number = tmulAssign;
				}
				else
				{
					strcpy_s(token.value.id, "*");
					token.number = tmul;
					ungetc(ch, stdin);
				}
				break;
			case '+':
				ch = fgetc(fp);
				if (ch == '+')
				{
					strcpy_s(token.value.id, "++");
					token.number = tinc;
				}
				else if (ch == '=')
				{
					strcpy_s(token.value.id, "+=");
					token.number = taddAssign;
				}
				else
				{
					strcpy_s(token.value.id, "+");
					token.number = tplus;
					ungetc(ch, stdin);
				}
				break;
			case '-':
				ch = fgetc(fp);
				if (ch == '-')
				{
					strcpy_s(token.value.id, "--");
					token.number = tdec;
				}
				else if (ch == '=')
				{
					strcpy_s(token.value.id, "-=");
					token.number = tsubAssign;
				}
				else
				{
					strcpy_s(token.value.id, "-");
					token.number = tminus;
					ungetc(ch, stdin);
				}
				break;
			case '<':
				ch = fgetc(fp);
				if (ch == '=')
				{
					strcpy_s(token.value.id, "<=");
					token.number = tlesse;
				}
				else
				{
					strcpy_s(token.value.id, "<");
					token.number = tless;
					ungetc(ch, stdin);
				}
				break;
			case '=':
				ch = fgetc(fp);
				if (ch == '=')
				{
					strcpy_s(token.value.id, "==");
					token.number = tequal;
				}
				else
				{
					strcpy_s(token.value.id, "=");
					token.number = tassign;
					ungetc(ch, stdin);
				}
				break;
			case '>':
				ch = fgetc(fp);
				if (ch == '=')
				{
					strcpy_s(token.value.id, ">=");
					token.number = tgreate;
				}
				else
				{
					strcpy_s(token.value.id, ">");
					token.number = tgreat;
					ungetc(ch, stdin);
				}
				break;
			case '|':
				ch = fgetc(fp);
				if (ch == '|')
				{
					strcpy_s(token.value.id, "||");
					token.number = tor;
				}
				else
				{
					lexicalError(3);
					ungetc(ch, stdin);
				}
				break;
			case '(':
				strcpy_s(token.value.id, "(");
				token.number = tlparen;
				break;
			case ')':
				strcpy_s(token.value.id, ")");
				token.number = trparen;
				break;
			case ',':
				strcpy_s(token.value.id, ",");
				token.number = tcomma;
				break;
			case ';':
				strcpy_s(token.value.id, ";");
				token.number = tsemicolon;
				break;
			case '[':
				strcpy_s(token.value.id, "[");
				token.number = tlbracket;
				break;
			case ']':
				strcpy_s(token.value.id, "]");
				token.number = trbracket;
				break;
			case '{':
				strcpy_s(token.value.id, "{");
				token.number = tlbrace;
				break;
			case '}':
				strcpy_s(token.value.id, "}");
				token.number = trbrace;
				break;
			case EOF:
				token.number = teof;
				break;
			default:
				printf("Current character : %c ", ch);
				lexicalError(4);
				break;
		}
	}
	while (token.number == tnull);
	return token;
}

int main()
{
	tokenType token;
	
	fopen_s(&fp, "prime.mc", "r");
	if (fp == NULL)
	{
		printf("File open error");
	}

	while (token.number != teof)
	{
		token = scanner();

		if (token.number == tnumber)
		{
			printf("Token: %d (%d,%d)\n", token.value.num, token.number, token.value.num);
		}
		else if(token.number == tident)
		{
			printf("Token: %s (%d,%s)\n", token.value.id, token.number, token.value.id);
		}
		else if (token.number == teof)
		{
			break;
		}
		else 
		{
			printf("Token: %s (%d,%d)\n", token.value.id, token.number, 0);
		}
	}

	fclose(fp);
	system("pause");
}