/*
Given an array of numbers, we want to remove and add some elements,
and query the maximal absolute difference among adjacent elements in
the sorted array. 

Note : Please handle the cases where N=1, it often leads to RTE.
*/
auto it=ms.lower_bound(a[i]);
// remove a[i]
if(it==ms.begin() && ms.size()>=2){
    auto pt=next(it);
    d.erase(d.find(*pt-*it));
}
else if(next(it)==ms.end() && ms.size()>=2){
    auto pt=prev(it);
    d.erase(d.find(*it-*pt));
}
else if(ms.size()>1){
    auto pt=prev(it), nt=next(it);
    d.erase(d.find(*it-*pt));
    d.erase(d.find(*nt-*it));
    d.insert(*nt-*pt);
}
ms.erase(ms.find(a[i]));
// add x
it=ms.upper_bound(x);
if(it==ms.end()){
    d.insert(x-*prev(it));
}
else if(it==ms.begin()){
    d.insert(*it-x);
}
else if(ms.size()>1){
    auto pt=prev(it);
    d.erase(d.find(*it-*pt));
    d.insert(x-*pt);
    d.insert(*it-x);
}
ms.insert(x);
