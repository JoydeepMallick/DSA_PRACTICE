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
#include <queue>

double minimiseMaxDistance(vector<int> &arr, int k){
	int n = arr.size();
	vector<int> cntnewstations(n-1, 0);// count number of stations placed between arr[i] and arr[i+1]

	priority_queue<pair<long double, int>> pq;
	for(int i = 0; i < n-1; i++){
		long double diff = (arr[i+1] - arr[i]);
		pq.push({diff, i});
	}

	for(int newstation = 1; newstation <= k; newstation++){
		//find maximum ajacent distance between stations
		int maxind = pq.top().second;			
		pq.pop();
		cntnewstations[maxind]++;//add 1 new station
		long double newsectionsize = (long double)(arr[maxind+1] - arr[maxind]) / (long double)(cntnewstations[maxind]+1);
		pq.push({newsectionsize, maxind});
	}

	return pq.top().first;
}


// most optimal : BS on floating points

