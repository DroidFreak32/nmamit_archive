{ split($0,a.” “);
	for (i=1;i<=NF;i++)
	{
		row[NR]+=a[i]
	}     
	printf “%s”, $0
	printf “   %d\n”, row[NR]
} 