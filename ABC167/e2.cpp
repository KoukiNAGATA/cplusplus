#include <cstdio>
#include <algorithm>
#define mod 998244353
#define maxn 200010
#define LL long long
using namespace std;
int n,m,k;
LL fact[maxn],inv[maxn],ans,p;
LL quick_pow(LL a,LL b){//a^b
	LL ans=1;
	while(b){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans%mod;
}
LL C(LL a,LL b){//组合数计算
	return fact[a]*inv[a-b]%mod*inv[b]%mod;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
    ans=0;
    fact[0]=1;
	for(int i=1;i<=n;i++)fact[i]=fact[i-1]*i%mod;//fact[i]代表i!
	inv[n]=quick_pow(fact[n],mod-2);
	for(int i=n-1;i>=0;i--)inv[i]=inv[i+1]*(i+1)%mod;//inv[i]代表i!的乘法逆元
    p=quick_pow(m-1,n-k-1);
	for(int i=n-k;i<=n;i++){
		ans=(ans+m*p%mod*C(n-1,i-1)%mod)%mod;//C(n-1,i-1)隔板法
		p=p*(m-1)%mod;
	}
	printf("%lld\n",ans);
	return 0;
}