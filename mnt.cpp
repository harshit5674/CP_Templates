
template<const int mxm>
struct mxmmnt{
	int v;
	mxmmnt()=default;
	mxmmnt(ll vv): v(vv){}
	inline mxmmnt<mxm> operator - (mxmmnt<mxm> se){
		int er=this->v-se.v;
		if(er<0){
			return mxmmnt<mxm>(er+mxm);
		}
		else{
			return mxmmnt<mxm>(er);
		}
	}
	inline mxmmnt<mxm> operator + (mxmmnt<mxm> se){
		int er=this->v+se.v;
		if(er>=mxm){
			return mxmmnt<mxm>(er-mxm);
		}
		else{
			return mxmmnt<mxm>(er);
		}
	}
	inline mxmmnt<mxm> operator * (mxmmnt<mxm> se){
		int er=(ll)this->v*se.v%mxm;
		if(er<0){
			return mxmmnt<mxm>(er+mxm);
		}
		else{
			return mxmmnt<mxm>(er);
		}
	}
	inline mxmmnt<mxm> operator - (){
		return mxmmnt<mxm>(this->v? mxm- this->v :0);
	}
	mxmmnt<mxm> pow(ll r)  { mxmmnt<mxm> x = *this, y = 1; for (; r; r >>= 1) { if (r & 1) y *= x; x *= x; } return y; }
	mxmmnt<mxm> inv() { return pow(mxm - 2); }
	inline mxmmnt<mxm> operator /  (mxmmnt<mxm> se){ 
		return *this *  se.inv(); 
	}
	inline bool operator ==  (mxmmnt<mxm> se){ 
		return (this->v)==(se.v);
	}
	inline bool operator !=  (mxmmnt<mxm> se){ 
		return (this->v)==(se.v);
	}
	inline bool operator >  (mxmmnt<mxm> se){ 
		return (this->v)>(se.v);
	}
	inline bool operator <  (mxmmnt<mxm> se){ 
		return (this->v)<(se.v);
	}
};

template <int mxm> istream & operator >> (istream & in, mxmmnt<mxm> &n) { 
	return in >> n.v; 
}
template <int mxm> ostream & operator << (ostream & out, mxmmnt<mxm> n) { 
	return out << n.v; 
}
template <int mxm> mxmmnt<mxm> operator * (int v, mxmmnt<mxm> n) { 
	return mxmmnt<mxm>(v%mxm) * n; 
}
template <int mxm> mxmmnt<mxm> operator + (int v, mxmmnt<mxm> n) { 
	return mxmmnt<mxm>(v%mxm) + n; 
}
template <int mxm> mxmmnt<mxm> operator - (int v, mxmmnt<mxm> n) { 
	return mxmmnt<mxm>(v%mxm) - n; 
}
template <int mxm> mxmmnt<mxm> operator - ( mxmmnt<mxm> n,int v) { 
	return n-mxmmnt<mxm>(v%mxm) ; 
}
using mnt = mxmmnt<mxm>;
