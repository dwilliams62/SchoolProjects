template <typeName T>
Set<T> operator+ (const Set<T>& lhs, const Set<T>& rhs) {
	Set<T> setUnion;
	set<T>::const_iterator lhsiter = lhs.begin(), rhsIter = rhs.begin();

	while (lhsIter != lhs.end()) {
		setUnion.insert(*lhsIter);
		lhsIter++;
	}
	while (rhsIter != rhs.end()) {
		if (rhs.find(rhsIter) == rhs.end()) {
			setUnion.insert(*rhsIter);
		}
		rhsIter++;
	}
	return setUnion;
}

template <typeName T>
Set<T> operator- (const Set<T>& lhs, const Set<T>& rhs) {
	Set<T> setDifference;
	set<T>::const_iterator lhsiter = lhs.begin(), rhsIter = rhs.begin();

	while (lhsIter != lhs.end()) {
		if (*lhsIter == *rhsIter) {
			lhsIter++;
			rhsIter++;
		}
		else if (*lhsIter > *rhsIter && rhsIter != rhs.end()) {
			rhsIter++;
		else {
			setDifference.insert(*lhsIter);
			lhsIter++;
		}
	}
	return setDifference;
}