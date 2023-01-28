void permute(string str){
	// Sort the string in lexicographically
	// ascennding order
	sort(str.begin(), str.end());

	// Keep printing next permutation while there
	// is next permutation
	do {
		cout<<str<<endl;
	} while (next_permutation(str.begin(), str.end()));
	return 0;
}