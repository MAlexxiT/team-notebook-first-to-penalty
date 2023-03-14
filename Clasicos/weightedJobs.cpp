// Dado n Jobs y su profit, calcula cual es el mayor profit que se puede obtener en O(n^2)
struct Job{int start, finish, profit;};
bool jobComparataor(Job s1, Job s2){return (s1.finish < s2.finish);}
// Find the latest job (in sorted array) that doesn't
// conflict with the job[i]. If there is no compatible job,
// then it returns -1.
vector <Job> arr;
int* memo;
int latestNonConflict( int i){
	for (int j = i - 1; j >= 0; j--)
		if (arr[j].finish <= arr[i - 1].start)
			return j;
	return -1;
}
// A recursive function that returns the maximum possible
// profit from given array of jobs.  The array of jobs must
// be sorted according to finish time.
int findMaxProfitRec( int n){
	// Base case
	if (n == 1) return arr[n - 1].profit;
    if (memo[n]>=0) return memo[n];
	// Find profit when current job is included
	int inclProf = arr[n - 1].profit;
	int i = latestNonConflict(n);
	if (i != -1) inclProf += findMaxProfitRec( i + 1);
 
	// Find profit when current job is excluded
	int exclProf = findMaxProfitRec( n - 1);
 
	return memo[n]=max(inclProf, exclProf);
}
 
// The main function that returns the maximum possible
// profit from given array of jobs
int findMaxProfit( int n){
	sort(arr.begin(),arr.end(), jobComparataor);
	return findMaxProfitRec(n);
}