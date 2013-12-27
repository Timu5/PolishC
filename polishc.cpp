/* PolishC - C language with polish keywords
** Copyright (C) 2013  Mateusz Muszyński
**
** This program is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.

** You should have received a copy of the GNU General Public License
** along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <cstdio>
#include <string>

std::string IdentifierStr;
bool isDoubleQuotes = false;
bool isSingleQuotes = false;

std::string StrToLower(std::string input)
{
	char * p = (char*)input.c_str();
	for ( ; *p; ++p) *p = tolower(*p);
	return input;
}

bool DoJob() 
{
	static int LastChar = ' ';
#define NextChar() LastChar = getchar()
	if(LastChar == '"')
	{
		isDoubleQuotes = isDoubleQuotes?false:true;
		printf("\"");
		NextChar();
	}
	if(LastChar == '\'')
	{
		isSingleQuotes = isSingleQuotes?false:true;
		printf("'");
		NextChar();
	}

	if(!isDoubleQuotes && !isSingleQuotes)
	{
		if (isalpha(LastChar) || LastChar == '_' || LastChar == '#')
		{
			IdentifierStr = LastChar;
			while (isalnum((NextChar())) || LastChar == '_')
				IdentifierStr += LastChar;

#define TOKEN(a, b) if (StrToLower(IdentifierStr) == a){ printf(b);return true;}
			TOKEN("glowna", "main")
			TOKEN("przerwij", "break")
			TOKEN("stan", "case")
			TOKEN("znak", "char")
			TOKEN("stala", "const")
			TOKEN("staly", "const")
			TOKEN("kontynuluj", "continue")
			TOKEN("domyslna", "default")
			TOKEN("domyslne", "default")
			TOKEN("domyslny", "default")
			TOKEN("rob", "do")
			TOKEN("podwojna", "double")
			TOKEN("podwojny", "double")
			TOKEN("inaczej", "else")
			TOKEN("enumeracja", "enum")
			TOKEN("zewnetrzna", "extern")		
			TOKEN("zewnetrzny", "extern")
			TOKEN("pojedyncza", "float")
			TOKEN("pojedynczy", "float")
			TOKEN("dla", "for")
			TOKEN("idzdo", "goto")
			TOKEN("jezeli", "if")
			TOKEN("calkowita", "int")
			TOKEN("dlugi", "long")
			TOKEN("dluga", "long")
			TOKEN("rejestr", "register")
			TOKEN("zwroc", "return")
			TOKEN("krotki", "short")
			TOKEN("krotka", "short")
			TOKEN("sygnowany", "signed")
			TOKEN("sygnowana", "signed")
			TOKEN("wielkosc", "sizeof")
			TOKEN("statyczna", "static")
			TOKEN("statyczny", "static")
			TOKEN("struktura", "struct")
			TOKEN("strukt", "struct")
			TOKEN("przelacz", "switch")
			TOKEN("definujtyp", "typedef")
			TOKEN("unia", "union")
			TOKEN("niesygnowany", "unsigned")
			TOKEN("niesygnowana", "unsigned")
			TOKEN("nicosc", "void")
			TOKEN("nic", "void")
			TOKEN("niewazny", "void")
			TOKEN("lotny", "volatile")
			TOKEN("dopoki", "while")
			
			TOKEN("#zalacz", "#include")
			TOKEN("#definiuj", "#define")
			TOKEN("#def", "#define")
			TOKEN("#oddefiniuj", "#undef")
			TOKEN("#oddef", "#undef")
			TOKEN("#jezeli", "#if")
			TOKEN("#inaczej", "#else")
			TOKEN("#koniecjezeli", "#endif")
			TOKEN("#konjez", "#endif")
			TOKEN("#injez", "#elif")
			TOKEN("#jezelizdefiniowany", "#ifdef")
			TOKEN("#jezdef", "#ifdef")
			TOKEN("#jezeliniezdefiniowany", "#ifndef")
			TOKEN("#jeznzdef", "#ifndef")
			TOKEN("#blad", "#error")
			
			TOKEN("p", "f")
			
			printf("%s", IdentifierStr.c_str());
			return true;
		}
		if (LastChar == '/') {
			NextChar();
			if(LastChar == '/')
			{
				do NextChar();
				while (LastChar != EOF && LastChar != '\n' && LastChar != '\r');
			}
			else if(LastChar == '*')
			{
				NextChar();
				while (LastChar) {
					while (LastChar != '*')
						NextChar();
					NextChar();
					if (LastChar == '/')
						LastChar = 0;
				}
				NextChar();
			}
			if (LastChar != EOF)
				return DoJob();
		}
	}
	if (LastChar == EOF)
		return false;

	printf("%c", LastChar);
	NextChar();
	return true;
}

int main()
{
	while(DoJob()){}
	return 0;
}
