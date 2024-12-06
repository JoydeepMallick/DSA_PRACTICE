//optimal 1
#include<vector>

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &left, vector<long long> &right){
	int l = left.size() - 1, r = 0;
	while(left[l] > right[r] ){
		swap(left[l], right[r]);
		l--;
		r++;
	}
	sort(left.begin(), left.end());
	sort(right.begin(), right.end());
}


//optimal 2

void swapifgreater(vector<long long> &left, vector<long long> &right, int indl, int indr){
	if(left[indl] > right[indr]){
		swap(left[indl], right[indr]);
	}
}

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &left, vector<long long> &right){
	int szl = left.size(), szr = right.size();
	int gap = ceil((szl + szr)/2.0);
	while(1){//kind of like do while
		int l = 0, r = l + gap;//basically gap since l = 0
		while(r < (szl + szr)){
			//3 scenarios 

			//case 1 : both pointers in left array
			if(l < szl && r < szl){
				swapifgreater(left, left, l, r);
			}
			//case 2 : both pointers in right array
			else if(l >= szl && r >= szl){
				swapifgreater(right, right, l-szl, r-szl);
			}
			//case 3 : l pointer in left and r pointer in right
			else if(l < szl && r >= szl){
				swapifgreater(left, right, l, r-szl);
			}
		
			l++;r++;
		}

		if(gap == 1) break;
		else gap = ceil(gap/2.0);
	}
}