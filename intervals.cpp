/*
given an array of numbers, we want to remove and add some elements,
and query the maximal absolute difference among adjacent elements in
the sorted array

handle the cases where n=1, often leads to RTE
*/

// ms := multiset that stores points
// d  := multiset that stores distances between adjacent points

// remove x from the set
auto it=ms.lower_bound(x);
if(it==ms.begin() && ms.size()>=2){
        // if smallest element
        d.erase(d.find(*pt-*next(it)));
}
else if(next(it)==ms.end() && ms.size()>=2){
        // if largest element
        d.erase(d.find(*it-*prev(it)));
}
else if(ms.size()>1){
        auto pt=prev(it), nt=next(it);
        d.erase(d.find(*it-*pt));
        d.erase(d.find(*nt-*it));
        d.insert(*nt-*pt);
}
ms.erase(ms.find(x));

// add x to the set
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
