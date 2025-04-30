//brute using greedy logic
double minimiseMaxDistance(vector<int> &arr, int k){
	int n = arr.size();
	vector<int> cntnewstations(n-1, 0);// count number of stations placed between arr[i] and arr[i+1]
	//placing 1 new station at a time in optimal way
	for(int newstation = 1; newstation <= k; newstation++){
		//find maximum ajacent distance between stations
		int maxind = -1, maxsection = -1;
		for(int i = 0; i < n-1; i++){
			long double sectionsize = (long double)(arr[i+1] - arr[i])/(long double)(cntnewstations[i]+1);
			if(sectionsize > maxsection){
				maxsection = sectionsize;
				maxind = i;
			}
		}
		cntnewstations[maxind]++;
	}
	long double maxdist = -1;
	for(int i = 0; i < n-1; i++){
		long double dist = (long double)(arr[i+1]-arr[i]) / (long double)(cntnewstations[i]+1);
		maxdist = max(maxdist, dist);
	}
	return maxdist;
}


// optimal 1 : using priority queues
double numberofgasstations(vector<int> &arr, long double maxdist){
	int cnt = 0;
	int n = arr.size();
	for(int i = 0; i < n-1; i++){
		cnt += ceil((long double)(arr[i+1]-arr[i])/maxdist) -1;
	}
	return cnt;
}

double minimiseMaxDistance(vector<int> &arr, int k){
	int n = arr.size();
	long double low = 0, high = 0;
	//high is set to be the max difference among all
	for(int i = 0; i < n-1; i++){
		high = max(high, (long double)arr[i+1]-arr[i]);
	}
	long double diff = 1e-6;
	while(high - low > diff){
		long double mid = (high + low)/2.0;
		int cnt = numberofgasstations(arr, mid) ;
		if(cnt <= k){// try improve the answer by reducing it since its min of max
			high = mid;
		}
		else low = mid;
	}
	return high;
}

