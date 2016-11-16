double absolute(double x)
{
	if (x < 0)
		return(-x);
	return(x);
}

unsigned long long fact(unsigned long long x)
{
	if (x == 1)
		return (x);
	return (x * fact(x - 1));
}

unsigned long long fact_TailRec(unsigned long long x, unsigned long long result = 1)
{
	if (x == 1)
		return(result);
	return(fact_TailRec(x - 1, x * result));
}