
template <typename T>
T Quicksort(T A, T lo, T hi){
	if(lo >= 0 && hi >= 0){
		if(lo < hi){
			p = partition(A, lo hi)
			quicksort(A lo, p-1)
			quicksort(A p+1, hi)
		}
	}
}

template <typename B>
B partition(B A, B lo, B hi){


}