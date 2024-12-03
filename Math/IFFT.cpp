void IFFT(vector<cd>& A) {
	for (auto& p : A) p = conj(p);
	// complex conjugate
	// a + bi -> a - bi
	FFT(A);
	for (auto& p : A) p = conj(p);// complex conjugate
	// **not needed for our purpose**
	for (auto& p : A) p /= A.size();// scale down (1/n)
}