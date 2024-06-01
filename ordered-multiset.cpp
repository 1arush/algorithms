// do NOT use '#define int int64_t'

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,
tree_order_statistics_node_update> ordered_multiset;

int t=0;
ordered_multiset ms;

// insert element 'x'
ms.insert({x,t++});

// erase element 'x'
ms.erase(ms.lower_bound({x,0}));

// find the number of elements < x
int cnt=ms.order_of_key({x,0});

// find the k-th element (0-base)
int val=ms.find_by_order(k)->first;
