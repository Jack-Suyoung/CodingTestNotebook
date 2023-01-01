
int maxDpeth(char* s);

int main()
{
	char string[] = "(1)+((2))+(((3)))";
	int RetVal;

	RetVal = maxDpeth(string);

	return 0;
}

int maxDpeth(char* s)
{
	int Depth = 0;
	int MaxDepth = 0;
	int NumOfChar = 0;

	while (s[NumOfChar] != '\0')
	{
		if (s[NumOfChar] == '(')
		{
			++Depth;
		}
		else if (s[NumOfChar] == ')')
		{
			--Depth;
		}
		else
		{
			// Do Nothing
		}

		if (Depth > MaxDepth)
		{
			MaxDepth = Depth;
		}
		else
		{
			// Do Nothing
		}

		++NumOfChar;
	}

	return MaxDepth;
}